//Working version Pixel_Tester_WS2811_08142024.0001
#include <EEPROM.h>
#include <SPI.h>
#include <TFT_eSPI.h>
#include <XPT2046_Touchscreen.h>

#include "FastLED.h"


TFT_eSPI tft = TFT_eSPI();


// Touchscreen pins
#define XPT2046_IRQ 36   // T_IRQ
#define XPT2046_MOSI 32  // T_DIN
#define XPT2046_MISO 39  // T_OUT
#define XPT2046_CLK 25   // T_CLK
#define XPT2046_CS 33    // T_CS

SPIClass touchscreenSPI = SPIClass(VSPI);
XPT2046_Touchscreen touchscreen(XPT2046_CS, XPT2046_IRQ);

#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240
#define FONT_SIZE 2

// Button position and size
#define FRAME_X 10
#define FRAME_Y 80
#define FRAME_W 90
#define FRAME_H 50


//Display Text Box

#define TextBox_X 10            //10
#define TextBox_Y 10            //120
#define TextBox_W 100           //50
#define TextBox_H 50            /50



// Red zone size
#define RedBUTTON_X FRAME_X            //10
#define RedBUTTON_Y FRAME_Y            //120
#define RedBUTTON_W (FRAME_W / 2)      //50
#define RedBUTTON_H FRAME_H            /50

// Green zone size
#define GreenBUTTON_X (RedBUTTON_X +  RedBUTTON_W + 2) //10 + 50 + 5 = 65
#define GreenBUTTON_Y FRAME_Y
#define GreenBUTTON_W (FRAME_W / 2)
#define GreenBUTTON_H FRAME_H

// Blue zone size
#define BlueBUTTON_X (GreenBUTTON_X + GreenBUTTON_W + 2)    //65 + 50 + 5 = 120 
#define BlueBUTTON_Y FRAME_Y
#define BlueBUTTON_W (FRAME_W / 2)
#define BlueBUTTON_H FRAME_H

// Ct zone size
#define CTBUTTON_X (BlueBUTTON_X + BlueBUTTON_W + 2)
#define CTBUTTON_Y FRAME_Y
#define CTBUTTON_W (FRAME_W / 2)
#define CTBUTTON_H FRAME_H

// ct 2 zone size
#define CT2BUTTON_X (CTBUTTON_X + CTBUTTON_W + 2)
#define CT2BUTTON_Y FRAME_Y
#define CT2BUTTON_W (FRAME_W / 2)
#define CT2BUTTON_H FRAME_H

// Open zone size
#define WhiteBUTTON_X (CT2BUTTON_X + CT2BUTTON_W + 2)
#define WhiteBUTTON_Y FRAME_Y
#define WhiteBUTTON_W (FRAME_W / 2)
#define WhiteBUTTON_H FRAME_H




// Zero zone size
#define ZeroBUTTON_X FRAME_X            //10
#define ZeroBUTTON_Y (FRAME_Y + 50) + 2            //120
#define ZeroBUTTON_W (FRAME_W / 2)      //50
#define ZeroBUTTON_H FRAME_H            /50

// One zone size
#define OneBUTTON_X (ZeroBUTTON_X +  ZeroBUTTON_W + 2) //10 + 50 + 5 = 65
#define OneBUTTON_Y (FRAME_Y + 50) + 2
#define OneBUTTON_W (FRAME_W / 2)
#define OneBUTTON_H FRAME_H

// Two zone size
#define TwoBUTTON_X (OneBUTTON_X + OneBUTTON_W + 2)    //65 + 50 + 5 = 120 
#define TwoBUTTON_Y (FRAME_Y + 50) + 2
#define TwoBUTTON_W (FRAME_W / 2)
#define TwoBUTTON_H FRAME_H

// Three zone size
#define ThreeBUTTON_X (TwoBUTTON_X + TwoBUTTON_W + 2)
#define ThreeBUTTON_Y (FRAME_Y + 50) + 2
#define ThreeBUTTON_W (FRAME_W / 2)
#define ThreeBUTTON_H FRAME_H

// Four zone size
#define FourBUTTON_X (ThreeBUTTON_X + ThreeBUTTON_W + 2)
#define FourBUTTON_Y (FRAME_Y + 50) + 2
#define FourBUTTON_W (FRAME_W / 2)
#define FourBUTTON_H FRAME_H

// Five zone size
#define FiveBUTTON_X (FourBUTTON_X + FourBUTTON_W + 2)
#define FiveBUTTON_Y (FRAME_Y + 50) + 2
#define FiveBUTTON_W (FRAME_W / 2)
#define FiveBUTTON_H FRAME_H

// BackSpace zone size
#define BSBUTTON_X (FiveBUTTON_X + FiveBUTTON_W + 2)
#define BSBUTTON_Y (FRAME_Y + 50) + 2
#define BSBUTTON_W (FRAME_W / 4)
#define BSBUTTON_H FRAME_H


// Six zone size
#define SixBUTTON_X FRAME_X
#define SixBUTTON_Y (FRAME_Y + 100) + 4
#define SixBUTTON_W (FRAME_W / 2)
#define SixBUTTON_H FRAME_H


// Seven zone size
#define SevenBUTTON_X (SixBUTTON_X + SixBUTTON_W + 2)
#define SevenBUTTON_Y (FRAME_Y + 100) + 4
#define SevenBUTTON_W (FRAME_W / 2)
#define SevenBUTTON_H FRAME_H

// Eight zone size
#define EightBUTTON_X (SevenBUTTON_X + SevenBUTTON_W + 2)
#define EightBUTTON_Y (FRAME_Y + 100) + 4
#define EightBUTTON_W (FRAME_W / 2)
#define EightBUTTON_H FRAME_H

// Nine zone size
#define NineBUTTON_X (EightBUTTON_X + EightBUTTON_W + 2)
#define NineBUTTON_Y (FRAME_Y + 100) + 4
#define NineBUTTON_W (FRAME_W / 2)
#define NineBUTTON_H FRAME_H

// Enter zone size
#define EnterBUTTON_X (NineBUTTON_X + NineBUTTON_W + 2)
#define EnterBUTTON_Y (FRAME_Y + 100) + 4
#define EnterBUTTON_W (FRAME_W)
#define EnterBUTTON_H FRAME_H





// Button position and size
#define But_FRAME_X 220
#define But_FRAME_Y 10
#define But_FRAME_W 100
#define But_FRAME_H 50

// Red zone size
#define ONBUTTON_X But_FRAME_X
#define ONBUTTON_Y But_FRAME_Y
#define ONBUTTON_W But_FRAME_W
#define ONBUTTON_H But_FRAME_H





// RGB LED Pins
#define CYD_LED_BLUE 17
#define CYD_LED_RED 4
#define CYD_LED_GREEN 16



#define DATA_PIN 22
#define NUM_LEDS 201  // change this for maximum string length


CRGB leds[NUM_LEDS];


// Touchscreen coordinates: (x, y) and pressure (z)
int x, y, z;

int buttonValue = 0;
int pixelLength = 0;
int tenValue = 0;
int i_bright = 0;

int runCycle = 0;

bool BSPressed = false;
bool enterPressed = false;
bool buttonPressed = false;
bool buttonState = false;

bool OKRunLight = false;
bool turnOffOnce = false;

// Print Touchscreen info about X, Y and Pressure (Z) on the Serial Monitor
void printTouchToSerial(int touchX, int touchY, int touchZ) {
  Serial.print("X = ");
  Serial.print(touchX);
  Serial.print(" | Y = ");
  Serial.print(touchY);
  Serial.print(" | Pressure = ");
  Serial.print(touchZ);
  Serial.println();
}

// Draw button frame
void drawFrame() {
  tft.drawRect(But_FRAME_X, But_FRAME_Y, But_FRAME_W, But_FRAME_H, TFT_BLACK);
}

// Draw a ON/Off button
void drawONButton() {
  switch (runCycle) {
    case 0:
      tft.fillRect(ONBUTTON_X, ONBUTTON_Y, ONBUTTON_W, ONBUTTON_H, TFT_WHITE);  //TFT_RED
      break;
    case 1:
      tft.fillRect(ONBUTTON_X, ONBUTTON_Y, ONBUTTON_W, ONBUTTON_H, TFT_RED);  //TFT_RED
      break;
    case 2:
      tft.fillRect(ONBUTTON_X, ONBUTTON_Y, ONBUTTON_W, ONBUTTON_H, TFT_GREEN);  //TFT_GREEN
      break;
    case 3:
      tft.fillRect(ONBUTTON_X, ONBUTTON_Y, ONBUTTON_W, ONBUTTON_H, TFT_BLUE);  //TFT_GREEN
      break;
    case 4:
      tft.fillRect(ONBUTTON_X, ONBUTTON_Y, ONBUTTON_W, ONBUTTON_H, TFT_WHITE);  //TFT_GREEN
      break;
    case 5:
      tft.fillRect(ONBUTTON_X, ONBUTTON_Y, ONBUTTON_W, ONBUTTON_H, TFT_WHITE);  //TFT_GREEN
      break;
    case 6:
      tft.fillRect(ONBUTTON_X, ONBUTTON_Y, ONBUTTON_W, ONBUTTON_H, TFT_WHITE);  //TFT_GREEN
      break;
    default:
      // statements
      break;
  }


  drawFrame();
  tft.setTextColor(TFT_BLACK);
  tft.setTextSize(FONT_SIZE);
  tft.setTextDatum(MC_DATUM);

  switch (runCycle) {
    case 0:
      tft.drawString("OFF", ONBUTTON_X + (ONBUTTON_W / 2), ONBUTTON_Y + (ONBUTTON_H / 2));
      break;
    case 1:
      tft.drawString("ON", ONBUTTON_X + (ONBUTTON_W / 2), ONBUTTON_Y + (ONBUTTON_H / 2));
      break;
    case 2:
      tft.drawString("ON", ONBUTTON_X + (ONBUTTON_W / 2), ONBUTTON_Y + (ONBUTTON_H / 2));
      break;
    case 3:
      tft.drawString("ON", ONBUTTON_X + (ONBUTTON_W / 2), ONBUTTON_Y + (ONBUTTON_H / 2));
      break;
    case 4:
      tft.drawString("CT", ONBUTTON_X + (ONBUTTON_W / 2), ONBUTTON_Y + (ONBUTTON_H / 2));
      break;
    case 5:
      tft.drawString("CT2", ONBUTTON_X + (ONBUTTON_W / 2), ONBUTTON_Y + (ONBUTTON_H / 2));
      break;
    case 6:
      tft.drawString("ON", ONBUTTON_X + (ONBUTTON_W / 2), ONBUTTON_Y + (ONBUTTON_H / 2));
      break;
    default:
      // statements
      break;
  }

}


void drawButtons() {

  tft.fillRect(TextBox_X, TextBox_Y, TextBox_W, 50, TFT_WHITE);
  //Line 1
  tft.fillRect(RedBUTTON_X, RedBUTTON_Y, RedBUTTON_W, 50, TFT_RED);
  tft.fillRect(GreenBUTTON_X, GreenBUTTON_Y, GreenBUTTON_W, 50, TFT_GREEN);
  tft.fillRect(BlueBUTTON_X, BlueBUTTON_Y, BlueBUTTON_W, 50, TFT_BLUE);
  tft.fillRect(CTBUTTON_X, CTBUTTON_Y, CTBUTTON_W, 50, TFT_WHITE);
  tft.fillRect(CT2BUTTON_X, CT2BUTTON_Y, CT2BUTTON_W, 50, TFT_WHITE);
  tft.fillRect(WhiteBUTTON_X, WhiteBUTTON_Y, WhiteBUTTON_W, 50, TFT_WHITE);

  //Line 2
  tft.fillRect(ZeroBUTTON_X, ZeroBUTTON_Y, ZeroBUTTON_W, 50, TFT_WHITE);
  tft.fillRect(OneBUTTON_X, OneBUTTON_Y, OneBUTTON_W, OneBUTTON_H, TFT_WHITE);
  tft.fillRect(TwoBUTTON_X, TwoBUTTON_Y, TwoBUTTON_W, TwoBUTTON_H, TFT_WHITE);
  tft.fillRect(ThreeBUTTON_X, ThreeBUTTON_Y, ThreeBUTTON_W, ThreeBUTTON_H, TFT_WHITE);
  tft.fillRect(FourBUTTON_X, FourBUTTON_Y, FourBUTTON_W, FourBUTTON_H, TFT_WHITE);
  tft.fillRect(FiveBUTTON_X, FiveBUTTON_Y, FiveBUTTON_W, FiveBUTTON_H, TFT_WHITE);
  tft.fillRect(BSBUTTON_X, BSBUTTON_Y, BSBUTTON_W, BSBUTTON_H, TFT_WHITE);

  //Line 3
  tft.fillRect(SixBUTTON_X, SixBUTTON_Y, SixBUTTON_W, SixBUTTON_H, TFT_WHITE);
  tft.fillRect(SevenBUTTON_X, SevenBUTTON_Y, SevenBUTTON_W, SevenBUTTON_H, TFT_WHITE);
  tft.fillRect(EightBUTTON_X, EightBUTTON_Y, EightBUTTON_W, EightBUTTON_H, TFT_WHITE);
  tft.fillRect(NineBUTTON_X, NineBUTTON_Y, NineBUTTON_W, NineBUTTON_H, TFT_WHITE);
  tft.fillRect(EnterBUTTON_X, EnterBUTTON_Y, EnterBUTTON_W, EnterBUTTON_H, TFT_WHITE);
  tft.setTextColor(TFT_BLACK);
  tft.setTextSize(FONT_SIZE);
  tft.setTextDatum(MC_DATUM);

  tft.drawString(String(pixelLength), TextBox_X + (TextBox_W / 2), TextBox_Y + (50 / 2));
  //tft.drawString("0", RedBUTTON_X + (RedBUTTON_W / 2), RedBUTTON_Y + (50 / 2));
  //tft.drawString("0", GreenBUTTON_X + (GreenBUTTON_W / 2), GreenBUTTON_Y + (50 / 2));
  //tft.drawString("0", BlueBUTTON_X + (BlueBUTTON_W / 2), BlueBUTTON_Y + (50 / 2));
  tft.drawString("CT", CTBUTTON_X + (CTBUTTON_W / 2), CTBUTTON_Y + (50 / 2));
  tft.drawString("C2", CT2BUTTON_X + (CT2BUTTON_W / 2), CT2BUTTON_Y + (50 / 2));
  tft.drawString("WH", WhiteBUTTON_X + (WhiteBUTTON_W / 2), WhiteBUTTON_Y + (50 / 2));


  tft.drawString("0", ZeroBUTTON_X + (ZeroBUTTON_W / 2), ZeroBUTTON_Y + (50 / 2));
  tft.drawString("1", OneBUTTON_X + (OneBUTTON_W / 2), OneBUTTON_Y + (50 / 2));
  tft.drawString("2", TwoBUTTON_X + (TwoBUTTON_W / 2), TwoBUTTON_Y + (50 / 2));
  tft.drawString("3", ThreeBUTTON_X + (ThreeBUTTON_W / 2), ThreeBUTTON_Y + (50 / 2));
  tft.drawString("4", FourBUTTON_X + (FourBUTTON_W / 2), FourBUTTON_Y + (50 / 2));
  tft.drawString("5", FiveBUTTON_X + (FiveBUTTON_W / 2), FiveBUTTON_Y + (50 / 2));
  tft.drawString("<", BSBUTTON_X + (BSBUTTON_W / 2), BSBUTTON_Y + (50 / 2));
  tft.drawString("6", SixBUTTON_X + (SixBUTTON_W / 2), SixBUTTON_Y + (50 / 2));
  tft.drawString("7", SevenBUTTON_X + (SevenBUTTON_W / 2), SevenBUTTON_Y + (50 / 2));
  tft.drawString("8", EightBUTTON_X + (EightBUTTON_W / 2), EightBUTTON_Y + (50 / 2));
  tft.drawString("9", NineBUTTON_X + (NineBUTTON_W / 2), NineBUTTON_Y + (50 / 2));
  tft.drawString("Ent", EnterBUTTON_X + (EnterBUTTON_W / 2), EnterBUTTON_Y + (50 / 2));
}






void setup() {
  Serial.begin(115200);
  EEPROM.begin(20);
  FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, NUM_LEDS);

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


  pixelLength = int(EEPROM.read(0));
  // Draw button
  drawONButton();
  drawButtons();


  pinMode(CYD_LED_GREEN, OUTPUT);
  pinMode(CYD_LED_RED, OUTPUT);
  pinMode(CYD_LED_BLUE, OUTPUT);

  digitalWrite(CYD_LED_RED, HIGH);
  digitalWrite(CYD_LED_GREEN, HIGH);
  digitalWrite(CYD_LED_BLUE, HIGH);

  for (int dot = 0; dot < NUM_LEDS; dot++)
  {

    leds[dot] = CRGB::Black;
  }
  FastLED.setBrightness(50);
  FastLED.show();



  Serial.println("Starting");

}

void checkRed() {
  if ((x > RedBUTTON_X) && (x < (RedBUTTON_X + RedBUTTON_W))) {
    if ((y > (RedBUTTON_Y)) && (y <= (RedBUTTON_Y + 50))) {
      Serial.println("Red button pressed");
      runCycle = 1;
      for (int dot = 0; dot < NUM_LEDS; dot++)
      {
        leds[dot] = CRGB::Black;
      }
      FastLED.setBrightness(25);
      FastLED.show();
      delay(500);
      buttonPressed = true;
      OKRunLight = true;
      drawONButton();
      x = 0;
      y = 0;
      pixelLength = 200;
      drawButtons();
    }
  }
}

void checkGreen() {
  if ((x > GreenBUTTON_X) && (x < (GreenBUTTON_X + GreenBUTTON_W))) {
    if ((y > (GreenBUTTON_Y)) && (y <= (GreenBUTTON_Y + GreenBUTTON_H))) {
      Serial.println("Green button pressed");
      runCycle = 2;
      for (int dot = 0; dot < NUM_LEDS; dot++)
      {
        leds[dot] = CRGB::Black;
      }
      FastLED.setBrightness(25);
      FastLED.show();
      delay(500);
      buttonPressed = true;
      OKRunLight = true;
      drawONButton();
      x = 0;
      y = 0;
      pixelLength = 200;
      drawButtons();
    }
  }
}

void checkBlue() {
  if ((x > BlueBUTTON_X) && (x < (BlueBUTTON_X + BlueBUTTON_W))) {
    if ((y > (BlueBUTTON_Y)) && (y <= (BlueBUTTON_Y + BlueBUTTON_H))) {
      Serial.println("Blue button pressed");
      runCycle = 3;
      for (int dot = 0; dot < NUM_LEDS; dot++)
      {
        leds[dot] = CRGB::Black;
      }
      FastLED.setBrightness(25);
      FastLED.show();
      delay(500);
      buttonPressed = true;
      OKRunLight = true;
      drawONButton();
      x = 0;
      y = 0;
      pixelLength = 200;
      drawButtons();
    }
  }
}

void checkCT() {
  if ((x > CTBUTTON_X) && (x < (CTBUTTON_X + CTBUTTON_W))) {
    if ((y > (CTBUTTON_Y)) && (y <= (CTBUTTON_Y + CTBUTTON_H))) {
      Serial.println("CT button pressed");
      runCycle = 4;
      for (int dot = 0; dot < NUM_LEDS; dot++)
      {
        leds[dot] = CRGB::Black;
      }
      FastLED.setBrightness(25);
      FastLED.show();
      delay(500);
      buttonPressed = true;
      OKRunLight = true;
      drawONButton();
      x = 0;
      y = 0;
      pixelLength = 200;
      drawButtons();
    }
  }
}

void checkCT2() {
  if ((x > CT2BUTTON_X) && (x < (CT2BUTTON_X + CT2BUTTON_W))) {
    if ((y > (CT2BUTTON_Y)) && (y <= (CT2BUTTON_Y + CT2BUTTON_H))) {
      Serial.println("CT2 button pressed");
      runCycle = 5;
      for (int dot = 0; dot < NUM_LEDS; dot++)
      {
        leds[dot] = CRGB::Black;
      }
      FastLED.setBrightness(25);
      FastLED.show();
      delay(500);
      buttonPressed = true;
      OKRunLight = true;
      drawONButton();
      x = 0;
      y = 0;
      pixelLength = int(EEPROM.read(0));
      drawButtons();
    }
  }
}

void checkWhite() {
  if ((x > WhiteBUTTON_X) && (x < (WhiteBUTTON_X + WhiteBUTTON_W))) {
    if ((y > (WhiteBUTTON_Y)) && (y <= (WhiteBUTTON_Y + WhiteBUTTON_H))) {
      Serial.println("White button pressed");
      runCycle = 6;
      for (int dot = 0; dot < NUM_LEDS; dot++)
      {
        leds[dot] = CRGB::Black;
      }
      FastLED.setBrightness(25);
      FastLED.show();
      delay(500);
      buttonPressed = true;
      OKRunLight = true;
      drawONButton();
      x = 0;
      y = 0;
      pixelLength = 200;
      drawButtons();
    }
  }
}

void checkZero() {
  if ((x > ZeroBUTTON_X) && (x < (ZeroBUTTON_X + ZeroBUTTON_W))) {
    if ((y > (ZeroBUTTON_Y)) &&  (y < (ZeroBUTTON_Y + 50))) {
      Serial.println("Zero button pressed");
      delay(250);
      if (tenValue > 0 ) {
        buttonValue = 0;
        tenValue ++;
        Serial.print("Value0: ");
        Serial.print(buttonValue);
        Serial.print(" | ");
        Serial.println(tenValue);
        buttonPressed = true;
        x = 0;
        y = 0;
      }
    }
  }
}

void checkOne() {
  if ((x > OneBUTTON_X) && (x < (OneBUTTON_X + OneBUTTON_W))) {
    if ((y > (OneBUTTON_Y)) && (y <= (OneBUTTON_Y + OneBUTTON_H))) {
      Serial.println("One button pressed");
      delay(250);
      buttonValue = 1;
      tenValue ++;
      Serial.print("Value1: ");
      Serial.print(buttonValue);
      Serial.print(" | ");
      Serial.println(tenValue);
      buttonPressed = true;
      x = 0;
      y = 0;
    }
  }
}

void checkTwo() {
  if ((x > TwoBUTTON_X) && (x < (TwoBUTTON_X + TwoBUTTON_W))) {
    if ((y > (TwoBUTTON_Y)) && (y <= (TwoBUTTON_Y + TwoBUTTON_H))) {
      Serial.println("Two button pressed");
      delay(250);
      buttonValue = 2;
      tenValue ++;
      Serial.print("Value2: ");
      Serial.print(buttonValue);
      Serial.print(" | ");
      Serial.println(tenValue);
      buttonPressed = true;
      x = 0;
      y = 0;
    }
  }
}

void checkThree() {
  if ((x > ThreeBUTTON_X) && (x < (ThreeBUTTON_X + ThreeBUTTON_W))) {
    if ((y > (ThreeBUTTON_Y)) && (y <= (ThreeBUTTON_Y + ThreeBUTTON_H))) {
      Serial.println("Three button pressed");
      delay(250);
      buttonValue = 3;
      tenValue ++;
      Serial.print("Value3: ");
      Serial.print(buttonValue);
      Serial.print(" | ");
      Serial.println(tenValue);
      buttonPressed = true;
      x = 0;
      y = 0;
    }
  }
}

void checkFour() {
  if ((x > FourBUTTON_X) && (x < (FourBUTTON_X + FourBUTTON_W))) {
    if ((y > (FourBUTTON_Y)) && (y <= (FourBUTTON_Y + FourBUTTON_H))) {
      Serial.println("Four button pressed");
      delay(250);
      buttonValue = 4;
      tenValue ++;
      Serial.print("Value4: ");
      Serial.print(buttonValue);
      Serial.print(" | ");
      Serial.println(tenValue);
      buttonPressed = true;
      x = 0;
      y = 0;
    }
  }
}

void checkFive() {
  if ((x > FiveBUTTON_X) && (x < (FiveBUTTON_X + FiveBUTTON_W))) {
    if ((y > (FiveBUTTON_Y)) && (y <= (FiveBUTTON_Y + FiveBUTTON_H))) {
      Serial.println("Five button pressed");
      delay(250);
      buttonValue = 5;
      tenValue ++;
      Serial.print("Value5: ");
      Serial.print(buttonValue);
      Serial.print(" | ");
      Serial.println(tenValue);
      buttonPressed = true;
      x = 0;
      y = 0;
    }
  }
}

void checkSix() {
  if ((x > SixBUTTON_X) && (x < (SixBUTTON_X + SixBUTTON_W))) {
    if ((y > (SixBUTTON_Y)) && (y <= (SixBUTTON_Y + SixBUTTON_H))) {
      Serial.println("Six button pressed");
      delay(250);
      buttonValue = 6;
      tenValue ++;
      Serial.print("Value6: ");
      Serial.print(buttonValue);
      Serial.print(" | ");
      Serial.println(tenValue);
      buttonPressed = true;
      x = 0;
      y = 0;
    }
  }
}

void checkSeven() {
  if ((x > SevenBUTTON_X) && (x < (SevenBUTTON_X + SevenBUTTON_W))) {
    if ((y > (SevenBUTTON_Y)) && (y <= (SevenBUTTON_Y + SevenBUTTON_H))) {
      Serial.println("Seven button pressed");
      delay(250);
      buttonValue = 7;
      tenValue ++;
      Serial.print("Value7: ");
      Serial.print(buttonValue);
      Serial.print(" | ");
      Serial.println(tenValue);
      buttonPressed = true;
      x = 0;
      y = 0;
    }
  }
}

void checkEight() {
  if ((x > EightBUTTON_X) && (x < (EightBUTTON_X + EightBUTTON_W))) {
    if ((y > (EightBUTTON_Y)) && (y <= (EightBUTTON_Y + EightBUTTON_H))) {
      Serial.println("Eight button pressed");
      delay(250);
      buttonValue = 8;
      tenValue ++;
      Serial.print("Value8: ");
      Serial.print(buttonValue);
      Serial.print(" | ");
      Serial.println(tenValue);
      buttonPressed = true;
      x = 0;
      y = 0;
    }
  }
}

void checkNine() {
  if ((x > NineBUTTON_X) && (x < (NineBUTTON_X + NineBUTTON_W))) {
    if ((y > (NineBUTTON_Y)) && (y <= (NineBUTTON_Y + NineBUTTON_H))) {
      Serial.println("Nine button pressed");
      delay(250);
      buttonValue = 9;
      tenValue ++;
      Serial.print("Value9: ");
      Serial.print(buttonValue);
      Serial.print(" | ");
      Serial.println(tenValue);
      buttonPressed = true;
      x = 0;
      y = 0;
    }
  }
}

void checkBS() {
  if ((x > BSBUTTON_X) && (x < (BSBUTTON_X + BSBUTTON_W))) {
    if ((y > (BSBUTTON_Y)) && (y <= (BSBUTTON_Y + BSBUTTON_H))) {
      Serial.println("BS button pressed");
      delay(500);
      BSPressed = true;
      buttonPressed = true;
      x = 0;
      y = 0;
    }
  }
}

void checkEnter() {
  if ((x > EnterBUTTON_X) && (x < (EnterBUTTON_X + EnterBUTTON_W))) {
    if ((y > (EnterBUTTON_Y)) && (y <= (EnterBUTTON_Y + EnterBUTTON_H))) {
      Serial.println("Enter button pressed");
      tenValue = 0;
      enterPressed  = true;
      delay(250);
      buttonPressed = true;
      x = 0;
      y = 0;
    }
  }
}


void checkButtonStatus() {
  if ((x > ONBUTTON_X) && (x < (ONBUTTON_X + ONBUTTON_W))) {
    if ((y > (ONBUTTON_Y)) && (y <= (ONBUTTON_Y + ONBUTTON_H))) {
      Serial.println("Button pressed");
      OKRunLight = !OKRunLight;
      if (OKRunLight == false) {
        turnOffOnce = true;
      }

      drawONButton();
      delay(200);
      x = 0;
      y = 0;
      //digitalWrite(CYD_LED_GREEN, HIGH);
    }
  }


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
    drawButtons();
  }

  if (enterPressed == true && skipForBS == false) {
    Serial.print("pixelLength: ");
    Serial.println(pixelLength);
    enterPressed = false;

    if (pixelLength < 255) {
      EEPROM.write(0, pixelLength);
      EEPROM.commit();
      delay(50);
    } else {
      EEPROM.write(0, 255);
      EEPROM.commit();
      delay(50);
    }

  }

  if (tenValue == 1 && skipForBS == false) {
    pixelLength = buttonValue;
    Serial.print("pixelLength: ");
    Serial.println(pixelLength);
    drawButtons();
  }

  if (tenValue == 2 && skipForBS == false) {
    pixelLength = (pixelLength * 10) + buttonValue ;
    Serial.print("pixelLength: ");
    Serial.println(pixelLength);
    drawButtons();
  }

  if (tenValue == 3 && skipForBS == false) {
    pixelLength = (pixelLength * 10) + buttonValue ;
    Serial.print("pixelLength: ");
    Serial.println(pixelLength);
    drawButtons();
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

  //printTouchToSerial(x, y, z);

  checkRed();
  checkGreen();
  checkBlue();
  checkCT();
  checkCT2();
  checkWhite();

  if (tenValue < 3) checkZero();
  if (tenValue < 3)checkOne();
  if (tenValue < 3)checkTwo();
  if (tenValue < 3)checkThree();
  if (tenValue < 3)checkFour();
  if (tenValue < 3)checkFive();
  if (tenValue < 3) checkSix();
  if (tenValue < 3)checkSeven();
  if (tenValue < 3)checkEight();
  if (tenValue < 3)checkNine();
  checkBS();
  checkEnter();
}




void runLightsRed() {
  // Mode 1; LED Red
  for (int dot = 0; dot < NUM_LEDS; dot++)
  {

    leds[dot] = CRGB::Red;
  }
  FastLED.setBrightness(25);
  FastLED.show();
  runCycle = 10;

}

void runLightsGreen() {
  // Mode 1; LED Red
  for (int dot = 0; dot < NUM_LEDS; dot++)
  {

    leds[dot] = CRGB::Green;
  }
  FastLED.setBrightness(25);
  FastLED.show();
  runCycle = 10;
}

void runLightsBlue() {
  // Mode 1; LED Red
  for (int dot = 0; dot < NUM_LEDS; dot++)
  {

    leds[dot] = CRGB::Blue;
  }
  FastLED.setBrightness(25);
  FastLED.show();
  runCycle = 10;
}

void runLightsWhite() {
  // Mode 1; LED Red
  for (int dot = 0; dot < NUM_LEDS; dot++)
  {

    leds[dot] = CRGB::White;
  }
  FastLED.setBrightness(22);
  FastLED.show();
  runCycle = 10;
}



void runLightsCount() {
  int testVal = 0;
  for (int dot = 0; dot < NUM_LEDS; dot++)
  {
    testVal = dot % 5;
    if (testVal == 0 && dot > 0) leds[dot] = CRGB::Red;
    testVal = dot % 20;
    if (testVal == 0 && dot > 0) leds[dot] = CRGB::Green;
    testVal = dot % 50;
    if (testVal == 0 && dot > 0) leds[dot] = CRGB::Blue;
    testVal = dot % 100;
    if (testVal == 0 && dot > 0) leds[dot] = CRGB::White;
  }
  FastLED.setBrightness(22);
  FastLED.show();
  runCycle = 10;
}

void runLightsCount2() {
  Serial.print("pixelLength: ");
  Serial.println(pixelLength);
  for (int dot = 0; dot < pixelLength + 1; dot++)
  {
    leds[dot] = CRGB::Red;
  }
  leds[pixelLength] = CRGB::White;
  FastLED.setBrightness(22);
  FastLED.show();
  runCycle = 10;
}

void turnLightsOff() {
  for (int dot = 0; dot < NUM_LEDS; dot++)
  {

    leds[dot] = CRGB::Black;
  }
  FastLED.setBrightness(25);
  FastLED.show();
  runCycle = 0;
}


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
    case 10:
      // wait here for next
      break;

    default:
      // statements
      break;
  }


}
