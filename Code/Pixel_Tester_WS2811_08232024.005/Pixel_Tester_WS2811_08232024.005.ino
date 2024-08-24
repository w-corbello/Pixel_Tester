//Working version Pixel_Tester_WS2811_08142024.0001
#include <EEPROM.h>
#include <SPI.h>
#include <TFT_eSPI.h>
#include "defintions.h"
#include <XPT2046_Touchscreen.h>

#include "FastLED.h"

#define DATA_PIN  22

CRGB leds[255];



TFT_eSPI tft = TFT_eSPI();
SPIClass touchscreenSPI = SPIClass(VSPI);
XPT2046_Touchscreen touchscreen(XPT2046_CS, XPT2046_IRQ);

#include "buttonDraw.h"

#include "checkButtons.h"
#include "lightOutOpt.h"





void setup() {
  Serial.begin(115200);
  EEPROM.begin(20);
  delay(150);

  pixelLength = int(EEPROM.read(0));

  if (pixelLength > 201) {
    EEPROM.write(0, 201);
    EEPROM.commit();
    delay(50);
  }


  colorOrder = int(EEPROM.read(2));
  if (colorOrder > 5) {
    EEPROM.write(2, 0);
    EEPROM.commit();
    delay(50);
    colorOrder = 0;
  }


  brightLevel = int(EEPROM.read(4));
  Serial.print("brightLevel: ");
  Serial.println(brightLevel);

  maxPixels = int(EEPROM.read(6));
  maxPixels = maxPixels ;
  Serial.print("maxPixels: ");
  Serial.println(maxPixels);

  if (maxPixels >254) maxPixels = 254;


  switch (colorOrder) {
    case 0:
      FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, maxPixels+1);
      break;
    case 1:
      FastLED.addLeds<WS2811, DATA_PIN, RBG>(leds, maxPixels+1);
      break;
    case 2:
      FastLED.addLeds<WS2811, DATA_PIN, GBR>(leds, maxPixels+1);
      break;
    case 3:
      FastLED.addLeds<WS2811, DATA_PIN, GRB>(leds, maxPixels+1);
      break;
    case 4:
      FastLED.addLeds<WS2811, DATA_PIN, BRG>(leds, maxPixels+1);
      break;
    case 5:
      FastLED.addLeds<WS2811, DATA_PIN, BGR>(leds, maxPixels+1);
      break;
    default:
      FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, maxPixels+1);
      break;
  }




  touchscreenSPI.begin(XPT2046_CLK, XPT2046_MISO, XPT2046_MOSI, XPT2046_CS);
  touchscreen.begin(touchscreenSPI);
  // Set the Touchscreen rotation in landscape mode
  // Note: in some displays, the touchscreen might be upside down, so you might need to set the rotation to 3: touchscreen.setRotation(3);
  touchscreen.setRotation(1);

  // Start the tft display
  tft.init();
  // Set the TFT display rotation in landscape mode
  tft.setRotation(1);

  // Clear the screen before writing to it
  tft.fillScreen(TFT_BLACK);



  // Draw button
  drawButtonsScreenOne();
  drawONButton();

  pinMode(CYD_LED_GREEN, OUTPUT);
  pinMode(CYD_LED_RED, OUTPUT);
  pinMode(CYD_LED_BLUE, OUTPUT);

  digitalWrite(CYD_LED_RED, HIGH);
  digitalWrite(CYD_LED_GREEN, HIGH);
  digitalWrite(CYD_LED_BLUE, HIGH);

  for (int dot = 0; dot < maxPixels; dot++)
  {

    leds[dot] = CRGB::Black;
  }
  FastLED.setBrightness(50);
  FastLED.show();



  Serial.println("Starting");
  Serial.print("Version: ");
  Serial.println("WS2811_08232024.005");


}



void calcValue() {
  bool skipForBS = false;

  if (BSPressed == true) {
    skipForBS = true;
    BSPressed = false;
    pixelLength = pixelLength -  buttonValue ;
    pixelLength = pixelLength / 10;
    tenValue --;
    if (tenValue < 0) tenValue = 0;
    Serial.print("pixelLength: ");
    Serial.println(pixelLength);
    enterPressed = false;
    drawButtonsScreenTwo();
  }

  if (enterPressed == true && skipForBS == false ) {

    if (curScreen == 1) {
      switch (getValForWhat) {
        case 0:
          // do nothing
          break;
        case 1:// max intensity of pixels
          Serial.println("Enter Pressed");
          Serial.print(" max intensity: ");
          Serial.println(pixelLength);
          enterPressed = false;
          if (pixelLength < 254) {
            EEPROM.write(4, pixelLength);
            EEPROM.commit();
            delay(50);
          } else {
            EEPROM.write(4, 254);
            EEPROM.commit();
            delay(50);
          }
          Serial.println("EEPROM Saved");
          ESP.restart();

          break;
        case 2:  // max length of pixels
          Serial.println("Enter Pressed");
          Serial.print("max length: ");
          Serial.println(pixelLength);
          enterPressed = false;
          if (pixelLength < 254) {
            EEPROM.write(6, pixelLength);
            EEPROM.commit();
            delay(50);
          } else {
            EEPROM.write(6, 254);
            EEPROM.commit();
            delay(50);
          }
          Serial.println("EEPROM Saved");
          ESP.restart();
          break;
        case 3: // change count length pixels
          Serial.println("Enter Pressed");
          Serial.print("pixelLength: ");
          Serial.println(pixelLength);
          enterPressed = false;
          if (pixelLength < 254) {
            EEPROM.write(0, pixelLength);
            EEPROM.commit();
            delay(50);
          } else {
            EEPROM.write(0, 254);
            EEPROM.commit();
            delay(50);
          }
          Serial.println("EEPROM Saved");
          ESP.restart();
          break;
        default:
          // statements
          break;
      }
    }
  }

  if (tenValue == 1 && skipForBS == false) {
    pixelLength = buttonValue;
    Serial.print("pixelLength: ");
    Serial.println(pixelLength);
    drawButtonsScreenTwo();
  }

  if (tenValue == 2 && skipForBS == false) {
    pixelLength = (pixelLength * 10) + buttonValue ;
    Serial.print("pixelLength: ");
    Serial.println(pixelLength);
    drawButtonsScreenTwo();
  }

  if (tenValue == 3 && skipForBS == false) {
    pixelLength = (pixelLength * 10) + buttonValue ;
    Serial.print("pixelLength: ");
    Serial.println(pixelLength);
    drawButtonsScreenTwo();
  }
  skipForBS = false;
}


void checkTouchPoints() {
  // Get Touchscreen points
  TS_Point p = touchscreen.getPoint();
  // Calibrate Touchscreen points with map function to the correct width and height
  x = map(p.x, 200, 3700, 1, SCREEN_WIDTH);
  y = map(p.y, 240, 3800, 1, SCREEN_HEIGHT);
  z = p.z;


  checkRed();
  checkGreen();
  checkBlue();
  checkCT();
  checkCT2();
  checkWhite();

  if (tenValue < 3) checkZero();
  if (tenValue < 3) checkOne();
  if (tenValue < 3) checkTwo();
  if (tenValue < 3) checkThree();
  if (tenValue < 3) checkFour();
  if (tenValue < 3) checkFive();
  if (tenValue < 3) checkSix();
  if (tenValue < 3) checkSeven();
  if (tenValue < 3) checkEight();
  if (tenValue < 3) checkNine();
  checkBS();
  checkEnter();
}






void turnLightsOff() {
  for (int dot = 0; dot < maxPixels; dot++)
  {
    leds[dot] = CRGB::Black;
  }
  FastLED.setBrightness(25);
  FastLED.show();
  runCycle = 0;
}



// Clock***********************************************************************************************************
void doClock() {
  timeNow = millis() ;            // the number of milliseconds that have passed since boot
  if (newNTP == true) {          // runs only once per reset
    timeLast = timeNow -  secondsSince;
    newNTP = false;
  }




  if (timeNow - timeLast >= 1000) {
    // save the last time you blinked the LED
    timeLast = timeNow;

    if (runCycle == 8 && rgbRunOK == false) {
      rgbRunOK = true;
      //Serial.println("Next RGB:");
    }

  }


}

//End of doClock routine******************************************************************************



void loop() {
  // Checks if Touchscreen was touched, and prints X, Y and Pressure (Z) info on the TFT display and Serial Monitor
  if (touchscreen.tirqTouched() && touchscreen.touched()) {
    checkTouchPoints();
  }



  if (buttonPressed == true) {
    buttonPressed = false;
    calcValue();
  }

  checkButtonStatus();


  if (turnOffOnce == true) {
    turnLightsOff();
    turnOffOnce = false;
    runCycle = 0;
    drawONButton();
  }

  switch (runCycle) {
    case 0:
      // do nothing
      break;
    case 1:
      runLightsRed();
      break;
    case 2:
      runLightsGreen();
      break;
    case 3:
      runLightsBlue();
      break;
    case 4:
      runLightsCount();
      break;
    case 5:
      runLightsCount2();
      break;
    case 6:
      runLightsWhite();
      break;
    case 7:
      runLightsFind();
      break;
    case 8:
      if (rgbRunOK == true) {
        runLightsRGB();
      }
      break;
    case 9: //define order
      if (newColorOrder == true) {
        runLightsWhat();
        tft.fillRect(ONBUTTON_X, ONBUTTON_Y, ONBUTTON_W, ONBUTTON_H, TFT_WHITE);  //TFT_GREEN
        tft.drawString("Cancel", ONBUTTON_X + (ONBUTTON_W / 2), ONBUTTON_Y + (ONBUTTON_H / 2));
      }
      break;

    case 10:
      curScreen = 1;
      pixelLength = int(EEPROM.read(4));
      Serial.print("Intensity: ");
      Serial.println(pixelLength);
      tft.fillScreen(TFT_BLACK);
      drawButtonsScreenTwo();
      tft.fillRect(Info_X, Info_Y, Info_W, Info_H, TFT_WHITE);  //
      tft.drawString("Int", Info_X + (Info_W / 2), Info_Y + (Info_H / 2));
      tft.fillRect(ONBUTTON_X, ONBUTTON_Y, ONBUTTON_W, ONBUTTON_H, TFT_WHITE);  //TFT_GREEN
      tft.drawString("Cancel", ONBUTTON_X + (ONBUTTON_W / 2), ONBUTTON_Y + (ONBUTTON_H / 2));
      runCycle = 0;
      break;
    case 11:
      curScreen = 1;
      pixelLength = int(EEPROM.read(6));
      Serial.print("String Length: ");
      Serial.println(pixelLength);
      tft.fillScreen(TFT_BLACK);
      drawButtonsScreenTwo();
      tft.fillRect(Info_X, Info_Y, Info_W, Info_H, TFT_WHITE);  //
      tft.drawString("Stn Len", Info_X + (Info_W / 2), Info_Y + (Info_H / 2));
      tft.fillRect(ONBUTTON_X, ONBUTTON_Y, ONBUTTON_W, ONBUTTON_H, TFT_WHITE);  //TFT_GREEN
      tft.drawString("Cancel", ONBUTTON_X + (ONBUTTON_W / 2), ONBUTTON_Y + (ONBUTTON_H / 2));
      runCycle = 0;
      break;
    case 12:  // 5 pressed, second screen, go to manual value
      curScreen = 1;
      pixelLength = int(EEPROM.read(0));
      Serial.print("Count 2: ");
      Serial.println(pixelLength);
      tft.fillScreen(TFT_BLACK);
      drawButtonsScreenTwo();
      tft.fillRect(Info_X, Info_Y, Info_W, Info_H, TFT_WHITE);  //
      tft.drawString("Ct2 Len", Info_X + (Info_W / 2), Info_Y + (Info_H / 2));
      tft.fillRect(ONBUTTON_X, ONBUTTON_Y, ONBUTTON_W, ONBUTTON_H, TFT_WHITE);  //TFT_GREEN
      tft.drawString("Cancel", ONBUTTON_X + (ONBUTTON_W / 2), ONBUTTON_Y + (ONBUTTON_H / 2));
      runCycle = 0;
      break;
    case 13: // BS

      break;
    case 14:
      // wait here for next
      break;
    case 15:
      // wait here for next
      break;
    case 16:
      // wait here for next
      break;
    case 17:
      // wait here for next
      break;
    case 18: // enter value on screen 2 pressed
      // wait here for next
      break;
    case 19:
      // wait here for next
      break;
    default:
      // statements
      break;
  }


  doClock();

}
