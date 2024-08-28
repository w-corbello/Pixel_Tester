



void checkTextBox() {
  if ((x > TextBox_X) && (x < (TextBox_X + TextBox_W))) {
    if ((y > (TextBox_Y)) && (y <= (TextBox_Y + 50))) {
      Serial.println("text box button pressed");
       if (runCycle == 15){
        rgbManOK = true;
        delay(250);
       }

    }
  }
}



void checkRed() {
  if ((x > RedBUTTON_X) && (x < (RedBUTTON_X + RedBUTTON_W))) {
    if ((y > (RedBUTTON_Y)) && (y <= (RedBUTTON_Y + 50))) {
      Serial.println("Red button pressed");
      runCycle = 1;
      for (int dot = 0; dot < maxPixels; dot++)
      {
        leds[dot] = CRGB::Black;
      }
      FastLED.setBrightness(0);
      FastLED.show();
      delay(250);
      buttonPressed = true;
      OKRunLight = true;
      drawONButton();
      x = 0;
      y = 0;
      pixelLength = maxPixels;
      drawButtonsScreenOne();

    }
  }
}

void checkGreen() {
  if ((x > GreenBUTTON_X) && (x < (GreenBUTTON_X + GreenBUTTON_W))) {
    if ((y > (GreenBUTTON_Y)) && (y <= (GreenBUTTON_Y + GreenBUTTON_H))) {
      Serial.println("Green button pressed");
      runCycle = 2;
      for (int dot = 0; dot < maxPixels; dot++)
      {
        leds[dot] = CRGB::Black;
      }
      FastLED.setBrightness(0);
      FastLED.show();
      delay(250);
      buttonPressed = true;
      OKRunLight = true;
      drawONButton();
      x = 0;
      y = 0;
      pixelLength = maxPixels;
      drawButtonsScreenOne();

    }
  }
}

void checkBlue() {
  if ((x > BlueBUTTON_X) && (x < (BlueBUTTON_X + BlueBUTTON_W))) {
    if ((y > (BlueBUTTON_Y)) && (y <= (BlueBUTTON_Y + BlueBUTTON_H))) {
      Serial.println("Blue button pressed");
      runCycle = 3;
      for (int dot = 0; dot < maxPixels; dot++)
      {
        leds[dot] = CRGB::Black;
      }
      FastLED.setBrightness(0);
      FastLED.show();
      delay(250);
      buttonPressed = true;
      OKRunLight = true;
      drawONButton();
      x = 0;
      y = 0;
      pixelLength = maxPixels;
      drawButtonsScreenOne();

    }
  }
}

void checkCT() {
  if ((x > CTBUTTON_X) && (x < (CTBUTTON_X + CTBUTTON_W))) {
    if ((y > (CTBUTTON_Y)) && (y <= (CTBUTTON_Y + CTBUTTON_H))) {
      Serial.println("CT button pressed");
      runCycle = 4;
      for (int dot = 0; dot < maxPixels; dot++)
      {
        leds[dot] = CRGB::Black;
      }
      FastLED.setBrightness(0);
      FastLED.show();
      delay(250);
      buttonPressed = true;
      OKRunLight = true;
      drawONButton();
      x = 0;
      y = 0;
      pixelLength = maxPixels;
      drawButtonsScreenOne();

    }
  }
}

void checkCT2() {
  if ((x > CT2BUTTON_X) && (x < (CT2BUTTON_X + CT2BUTTON_W))) {
    if ((y > (CT2BUTTON_Y)) && (y <= (CT2BUTTON_Y + CT2BUTTON_H))) {
      Serial.println("CT2 button pressed");
      runCycle = 5;
      for (int dot = 0; dot < maxPixels; dot++)
      {
        leds[dot] = CRGB::Black;
      }
      FastLED.setBrightness(0);
      FastLED.show();
      delay(250);
      buttonPressed = true;
      OKRunLight = true;
      drawONButton();
      x = 0;
      y = 0;
      pixelLength = int(EEPROM.read(0));
      drawButtonsScreenOne();

    }
  }
}

void checkWhite() {
  if ((x > WhiteBUTTON_X) && (x < (WhiteBUTTON_X + WhiteBUTTON_W))) {
    if ((y > (WhiteBUTTON_Y)) && (y <= (WhiteBUTTON_Y + WhiteBUTTON_H))) {
      Serial.println("White button pressed");
      runCycle = 6;
      for (int dot = 0; dot < maxPixels; dot++)
      {
        leds[dot] = CRGB::White;
      }
      FastLED.setBrightness(0);
      FastLED.show();
      delay(500);
      buttonPressed = true;
      OKRunLight = true;
      drawONButton();
      x = 0;
      y = 0;
      pixelLength = maxPixels;
      drawButtonsScreenOne();

    }
  }
}
//******************************************************************************************************

void checkZero() {
  if ((x > ZeroBUTTON_X) && (x < (ZeroBUTTON_X + ZeroBUTTON_W))) {
    if ((y > (ZeroBUTTON_Y)) &&  (y < (ZeroBUTTON_Y + 50))) {
      Serial.print("curScreen: ");
      Serial.println(curScreen);
      x = 0;
      y = 0;
      if (curScreen == 0) {
        runCycle = 7;
        OKRunLight = true;
        drawONButton();
        tft.fillRect(TextBox_X, TextBox_Y, TextBox_W, 50, TFT_WHITE);
        tft.drawString("6", TextBox_X + (TextBox_W / 2), TextBox_Y + (50 / 2));
        Serial.println("Find Order button pressed, screen 1");
        delay(250);
        x = 0;
        y = 0;
      } else if (curScreen == 1) {
        Serial.println("Zero button pressed, screen 2");
        delay(250);
        Serial.print("Value0: ");
        Serial.print(buttonValue);
        Serial.print(" | ");
        Serial.println(tenValue);
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
      } else {
        Serial.println("Zero button pressed, screen 3");
        delay(250);
        newColorOrder = true;
        colorOrder = 0;
        Serial.print("colorOrder: ");
        Serial.println(colorOrder);
        x = 0;
        y = 0;
      }
    }
  }
}

void checkOne() {
  if ((x > OneBUTTON_X) && (x < (OneBUTTON_X + OneBUTTON_W))) {
    if ((y > (OneBUTTON_Y)) && (y <= (OneBUTTON_Y + OneBUTTON_H))) {
      if (curScreen == 0) {
        runCycle = 8;
        OKRunLight = true;
        drawONButton();
        Serial.println("RGB button pressed, screen 1");
        delay(250);
        x = 0;
        y = 0;
      }  else if (curScreen == 1) {
        Serial.println("One button pressed, screen 2");
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
      } else {
        Serial.println("One button pressed, screen 3");
        delay(250);
        newColorOrder = true;
        colorOrder = 1;
        Serial.print("colorOrder: ");
        Serial.println(colorOrder);
        x = 0;
        y = 0;
      }
    }
  }
}

void checkTwo() {
  if ((x > TwoBUTTON_X) && (x < (TwoBUTTON_X + TwoBUTTON_W))) {
    if ((y > (TwoBUTTON_Y)) && (y <= (TwoBUTTON_Y + TwoBUTTON_H))) {
      if (curScreen == 0) {
        runCycle = 9;
        OKRunLight = true;
        Serial.println("Define order button pressed, screen 1");
        delay(250);
        curScreen = 2;
        getValForWhat = 4;
        tft.fillScreen(TFT_BLACK);
        drawButtonsScreenThree();
        drawONButton();
        tft.fillRect(ONBUTTON_X, ONBUTTON_Y, ONBUTTON_W, ONBUTTON_H, TFT_WHITE);  //TFT_GREEN
        tft.drawString("Cancel", ONBUTTON_X + (ONBUTTON_W / 2), ONBUTTON_Y + (ONBUTTON_H / 2));
        newColorOrder = true;
        x = 0;
        y = 0;
      } else if (curScreen == 1) {
        Serial.println("Two button pressed, screen 2");
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
      } else {
        Serial.println("Two button pressed, screen 3");
        delay(250);
        newColorOrder = true;
        colorOrder = 2;
        Serial.print("colorOrder: ");
        Serial.println(colorOrder);
        x = 0;
        y = 0;
      }
    }
  }
}

void checkThree() {
  if ((x > ThreeBUTTON_X) && (x < (ThreeBUTTON_X + ThreeBUTTON_W))) {
    if ((y > (ThreeBUTTON_Y)) && (y <= (ThreeBUTTON_Y + ThreeBUTTON_H))) {
      if (curScreen == 0) {
        // OKRunLight = true;
        // drawONButton();
        runCycle = 10;
        Serial.println("Intensity 2 button pressed, screen 1");
        getValForWhat = 1;
        delay(250);
        x = 0;
        y = 0;
      }  else if (curScreen == 1) {
        Serial.println("Three button pressed, screen 2");
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
      } else {
        Serial.println("Three button pressed, screen 3");
        delay(250);
        newColorOrder = true;
        colorOrder = 3;
        Serial.print("colorOrder: ");
        Serial.println(colorOrder);
        x = 0;
        y = 0;
      }
    }
  }
}

void checkFour() {
  if ((x > FourBUTTON_X) && (x < (FourBUTTON_X + FourBUTTON_W))) {
    if ((y > (FourBUTTON_Y)) && (y <= (FourBUTTON_Y + FourBUTTON_H))) {
      if (curScreen == 0) {
        // OKRunLight = true;
        // drawONButton();
        runCycle = 11;
        Serial.println("Max Length 4 button pressed, screen 1");
        getValForWhat = 2;
        delay(250);
        x = 0;
        y = 0;
      }  else if (curScreen == 1) {
        Serial.println("Four button pressed, screen 2");
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
      } else {
        Serial.println("Four button pressed, screen 3");
        delay(250);
        newColorOrder = true;
        colorOrder = 4;
        Serial.print("colorOrder: ");
        Serial.println(colorOrder);
        x = 0;
        y = 0;
      }
    }
  }
}


//check if ??? has been pressed or #5
void checkFive() {
  if ((x > FiveBUTTON_X) && (x < (FiveBUTTON_X + FiveBUTTON_W))) {
    if ((y > (FiveBUTTON_Y)) && (y <= (FiveBUTTON_Y + FiveBUTTON_H))) {
      if (curScreen == 0) {
        runCycle = 12;
        OKRunLight = true;
        drawONButton();
        Serial.println("Change Value for Count 2, 5 button pressed");
        getValForWhat = 3;
        delay(250);
        x = 0;
        y = 0;
      }  else if (curScreen == 1) {
        Serial.println("Five button pressed, screen 2");
        delay(250);
        buttonValue = 5;
        tenValue ++;
        Serial.print("Value5 : ");
        Serial.print(buttonValue);
        Serial.print(" | ");
        Serial.println(tenValue);
        buttonPressed = true;
        x = 0;
        y = 0;
      } else {
        Serial.println("Five button pressed, screen 3");
        delay(250);
        newColorOrder = true;
        colorOrder = 5;
        Serial.print("colorOrder: ");
        Serial.println(colorOrder);
        x = 0;
        y = 0;
      }
    }
  }
}


void checkBS() {
  if ((x > BSBUTTON_X) && (x < (BSBUTTON_X + BSBUTTON_W))) {
    if ((y > (BSBUTTON_Y)) && (y <= (BSBUTTON_Y + BSBUTTON_H))) {
      if (curScreen == 1) {
        Serial.println("BS button pressed");
        delay(250);
        BSPressed = true;
        buttonPressed = true;
        x = 0;
        y = 0;
      }
    }
  }
}



//******************************************************************************************************

void checkSix() {
  if ((x > SixBUTTON_X) && (x < (SixBUTTON_X + SixBUTTON_W))) {
    if ((y > (SixBUTTON_Y)) && (y <= (SixBUTTON_Y + SixBUTTON_H))) {
      if (curScreen == 0) {
        runCycle = 14;
        inOrderCount = 0;
        OKRunLight = true;
        drawONButton();
        pixelLength = int(EEPROM.read(0));
        drawButtonsScreenOne();
        Serial.println("Light in order, button pressed, screen 1");
        delay(250);
        x = 0;
        y = 0;
      } else if (curScreen == 1) {
        Serial.println("Six button pressed, screen 2");
        delay(250);
        buttonValue = 6;
        tenValue ++;
        Serial.print("Value6 : ");
        Serial.print(buttonValue);
        Serial.print(" | ");
        Serial.println(tenValue);
        buttonPressed = true;
        x = 0;
        y = 0;
      } else {
        Serial.println("Six button pressed, screen 3");
        delay(250);
        buttonValue = 6;
        tenValue ++;
        Serial.print("Value6 : ");
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

void checkSeven() {
  if ((x > SevenBUTTON_X) && (x < (SevenBUTTON_X + SevenBUTTON_W))) {
    if ((y > (SevenBUTTON_Y)) && (y <= (SevenBUTTON_Y + SevenBUTTON_H))) {
      if (curScreen == 0) {
        runCycle = 15;
        inOrderCount = 0;
        OKRunLight = true;
        drawONButton();
        pixelLength = int(EEPROM.read(0));
        drawButtonsScreenOne();
        Serial.println("Light in order, Manual, button pressed, screen 1");
        delay(250);
        x = 0;
        y = 0;
      } else if (curScreen == 1) {
        Serial.println("Seven button pressed, screen 2");
        delay(250);
        buttonValue = 7;
        tenValue ++;
        Serial.print("Value7 : ");
        Serial.print(buttonValue);
        Serial.print(" | ");
        Serial.println(tenValue);
        buttonPressed = true;
        x = 0;
        y = 0;
      } else {
        Serial.println("Seven button pressed, screen 3");
        delay(250);
        buttonValue = 7;
        tenValue ++;
        Serial.print("Value7 : ");
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

void checkEight() {
  if ((x > EightBUTTON_X) && (x < (EightBUTTON_X + EightBUTTON_W))) {
    if ((y > (EightBUTTON_Y)) && (y <= (EightBUTTON_Y + EightBUTTON_H))) {
      if (curScreen == 1) {
        Serial.println("Eight button pressed, screen 2");
        delay(250);
        buttonValue = 8;
        tenValue ++;
        Serial.print("Value8 : ");
        Serial.print(buttonValue);
        Serial.print(" | ");
        Serial.println(tenValue);
        buttonPressed = true;
        x = 0;
        y = 0;
      } else {
        Serial.println("Eight button pressed, screen 3");
        delay(250);
        buttonValue = 8;
        tenValue ++;
        Serial.print("Value8 : ");
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

void checkNine() {
  if ((x > NineBUTTON_X) && (x < (NineBUTTON_X + NineBUTTON_W))) {
    if ((y > (NineBUTTON_Y)) && (y <= (NineBUTTON_Y + NineBUTTON_H))) {
      if (curScreen == 1) {
        Serial.println("Nine button pressed, screen 2");
        delay(250);
        buttonValue = 9;
        tenValue ++;
        Serial.print("Value9 : ");
        Serial.print(buttonValue);
        Serial.print(" | ");
        Serial.println(tenValue);
        buttonPressed = true;
        x = 0;
        y = 0;
      } else {
        Serial.println("Nine button pressed, screen 3");
        delay(250);
        buttonValue = 9;
        tenValue ++;
        Serial.print("Value9 : ");
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


void checkEnter() {
  if ((x > EnterBUTTON_X) && (x < (EnterBUTTON_X + EnterBUTTON_W))) {
    if ((y > (EnterBUTTON_Y)) && (y <= (EnterBUTTON_Y + EnterBUTTON_H))) {
      Serial.println("Enter button pressed, screen 3");
      x = 0;
      y = 0;

      if (curScreen == 1) {
        Serial.println("Enter button pressed, screen 2");
        tenValue = 0;
        enterPressed  = true;
        delay(250);
        buttonPressed = true;
        x = 0;
        y = 0;
      } else if (curScreen == 2) {
        Serial.println("Enter button pressed, screen 3");
        Serial.print("Color order: ");
        Serial.println(colorOrderChange);
        EEPROM.write(2, colorOrderChange);
        EEPROM.commit();
        delay(100);
        curScreen = 0;
        x = 0;
        y = 0;
        ESP.restart();
      }
    }
  }
}



void checkButtonStatus() {
  if ((x > ONBUTTON_X) && (x < (ONBUTTON_X + ONBUTTON_W))) {
    if ((y > (ONBUTTON_Y)) && (y <= (ONBUTTON_Y + ONBUTTON_H))) {
      Serial.println("ON/OFF Button pressed");

      if (getValForWhat != 0) {
        ESP.restart();
      }


      if (OKRunLight == true) {
        OKRunLight = false;
        turnOffOnce = true;
      }

      if (curScreen > 0) {
        curScreen = 0;
        drawButtonsScreenOne();
      }
      drawONButton();
      delay(200);
      x = 0;
      y = 0;
      //digitalWrite(CYD_LED_GREEN, HIGH);
    }
  }


}
