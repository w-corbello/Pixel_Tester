void runLightsRed() {
  // Mode 1; LED Red
  Serial.println("runLightsRed");
  Serial.print("maxPixels: ");
  Serial.println(maxPixels);
  for (int dot = 0; dot < maxPixels+1; dot++)
  {
    leds[dot] = CRGB::Red;
  }
  FastLED.setBrightness(brightLevel);
  FastLED.show();
  runCycle = 19;
  tft.fillRect(TextBox_X, TextBox_Y, TextBox_W, 50, TFT_WHITE);
  pixelLength = maxPixels;
  tft.drawString(String(pixelLength), TextBox_X + (TextBox_W / 2), TextBox_Y + (50 / 2));
}

void runLightsGreen() {
  // Mode 2; LED Green
  for (int dot = 0; dot < maxPixels+1; dot++)
  {
    leds[dot] = CRGB::Green;
  }
  FastLED.setBrightness(brightLevel);
  FastLED.show();
  runCycle = 19;
}

void runLightsBlue() {
  // Mode 3; LED Blue
  for (int dot = 0; dot < maxPixels+1; dot++)
  {
    leds[dot] = CRGB::Blue;
  }
  FastLED.setBrightness(brightLevel);
  FastLED.show();
  runCycle = 19;
  tft.fillRect(TextBox_X, TextBox_Y, TextBox_W, 50, TFT_WHITE);
  pixelLength = maxPixels;
  tft.drawString(String(pixelLength), TextBox_X + (TextBox_W / 2), TextBox_Y + (50 / 2));
}



void runLightsCount() {
  // Mode 4; Count
  int testVal = 0;
  for (int dot = 0; dot < maxPixels+1; dot++)
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


  FastLED.setBrightness(brightLevel);
  FastLED.show();
  runCycle = 19;
  tft.fillRect(TextBox_X, TextBox_Y, TextBox_W, 50, TFT_WHITE);
  pixelLength = maxPixels;
  tft.drawString(String(pixelLength), TextBox_X + (TextBox_W / 2), TextBox_Y + (50 / 2));
}

void runLightsCount2() {
  // Mode 5; LED White
  Serial.print("pixelLength: ");
  Serial.println(pixelLength);
  for (int dot = 0; dot < pixelLength + 1; dot++)
  {
    leds[dot] = CRGB::Red;
  }
  leds[pixelLength] = CRGB::White;
  FastLED.setBrightness(brightLevel);
  FastLED.show();
  runCycle = 19;
  tft.fillRect(TextBox_X, TextBox_Y, TextBox_W, 50, TFT_WHITE);
  pixelLength = int(EEPROM.read(0));
  tft.drawString(String(pixelLength), TextBox_X + (TextBox_W / 2), TextBox_Y + (50 / 2));
}

void runLightsWhite() {
  // Mode 6; Count to preset length
  for (int dot = 0; dot < maxPixels+1; dot++)
  {
    leds[dot] = CRGB::White;
  }
  if (brightLevel > 250) brightLevel = brightLevel / 3;
  FastLED.setBrightness(brightLevel);
  FastLED.show();
  runCycle = 19;
  tft.fillRect(TextBox_X, TextBox_Y, TextBox_W, 50, TFT_WHITE);
  pixelLength = maxPixels;
  tft.drawString(String(pixelLength), TextBox_X + (TextBox_W / 2), TextBox_Y + (50 / 2));
}



void runLightsFind() {
  // Mode 7; LED Find order
  Serial.println("runLightsFind: ");
  for (int dot = 0; dot < maxPixels + 1; dot++)
  {
    leds[dot] = CRGB::Black;
  }
  leds[0] = CRGB::Red;
  leds[1] = CRGB::Red;
  leds[2] = CRGB::Green;
  leds[3] = CRGB::Green;
  leds[4] = CRGB::Blue;
  leds[5] = CRGB::Blue;
  leds[6] = CRGB::Blue;
  FastLED.setBrightness(brightLevel);
  FastLED.show();
  runCycle = 19;
  tft.fillRect(TextBox_X, TextBox_Y, TextBox_W, 50, TFT_WHITE);
  tft.drawString("6", TextBox_X + (TextBox_W / 2), TextBox_Y + (50 / 2));
}




void runLightsRGB() {
  // Mode 8; LED RGBRGBRGB....
  Serial.print("runLightsRGB: ");
  Serial.println(curColor);
  switch (curColor) {
    case 0:
      for (int dot = 1; dot < maxPixels + 1; dot++) {
        leds[dot] = CRGB::Red;
        leds[0] = CRGB::Red;
        int x = dot % 2;
        if (x == 0 && dot > 0)leds[dot] = CRGB::Green;
        x = dot % 3;
        if (x == 0 && dot > 0)leds[dot] = CRGB::Blue;
      }
      break;
    case 1:
      for (int dot = 1; dot < maxPixels + 1; dot++) {
        leds[dot] = CRGB::Green;
        leds[0] = CRGB::Green;
        int x = dot % 2;
        if (x == 0 && dot > 0)leds[dot] = CRGB::Blue;
        x = dot % 3;
        if (x == 0 && dot > 0)leds[dot] = CRGB::Red;
      }
      break;
    case 2:
      for (int dot = 1; dot < maxPixels + 1; dot++) {
        leds[dot] = CRGB::Blue;
        leds[0] = CRGB::Blue;
        int x = dot % 2;
        if (x == 0 && dot > 0)leds[dot] = CRGB::Red;
        x = dot % 3;
        if (x == 0 && dot > 0)leds[dot] = CRGB::Green;
      }
      break;
    default:
      // statements
      break;
  }
  FastLED.setBrightness(brightLevel);
  FastLED.show();
  rgbRunOK = false;
  runCycle = 8;
  curColor++;
  if (curColor == 3) {
    curColor = 0;
  }
  tft.fillRect(TextBox_X, TextBox_Y, TextBox_W, 50, TFT_WHITE);
  pixelLength = maxPixels;
  tft.drawString(String(pixelLength), TextBox_X + (TextBox_W / 2), TextBox_Y + (50 / 2));
}



void runLightsWhat() {
  Serial.print("define order: ");
  Serial.println(colorOrder);
  switch (colorOrder) {
    case 0:                   //RGB
      leds[0] = CRGB::Red;
      leds[1] = CRGB::Red;
      leds[2] = CRGB::Green;
      leds[3] = CRGB::Green;
      leds[4] = CRGB::Blue;
      leds[5] = CRGB::Blue;
      leds[6] = CRGB::Blue;
      colorOrderProfile = "RGB";
      colorOrderChange = 0;
      break;
    case 1:                   //RBG
      leds[0] = CRGB::Red;
      leds[1] = CRGB::Red;
      leds[2] = CRGB::Blue;
      leds[3] = CRGB::Blue;
      leds[4] = CRGB::Green;
      leds[5] = CRGB::Green;
      leds[6] = CRGB::Green;
      colorOrderProfile = "RBG";
      colorOrderChange = 1;
      break;
    case 2:                   //GBR
      leds[0] = CRGB::Green;
      leds[1] = CRGB::Green;
      leds[2] = CRGB::Blue;
      leds[3] = CRGB::Blue;
      leds[4] = CRGB::Red;
      leds[5] = CRGB::Red;
      leds[6] = CRGB::Red;
      colorOrderProfile = "GBR";
      colorOrderChange = 2;
      break;
    case 3:                   //GRB
      leds[0] = CRGB::Green;
      leds[1] = CRGB::Green;
      leds[2] = CRGB::Red;
      leds[3] = CRGB::Red;
      leds[4] = CRGB::Blue;
      leds[5] = CRGB::Blue;
      leds[6] = CRGB::Blue;
      colorOrderProfile = "GRB";
      colorOrderChange = 3;
      break;
    case 4:                   //BRG
      leds[0] = CRGB::Blue;
      leds[1] = CRGB::Blue;
      leds[2] = CRGB::Red;
      leds[3] = CRGB::Red;
      leds[4] = CRGB::Green;
      leds[5] = CRGB::Green;
      leds[6] = CRGB::Green;
      colorOrderProfile = "BRG";
      colorOrderChange = 4;
      break;
    case 5:                   //BGR
      leds[0] = CRGB::Blue;
      leds[1] = CRGB::Blue;
      leds[2] = CRGB::Green;
      leds[3] = CRGB::Green;
      leds[4] = CRGB::Red;
      leds[5] = CRGB::Red;
      leds[6] = CRGB::Red;
      colorOrderProfile = "BGR";
      colorOrderChange = 5;
      break;
    default:
      // statements
      break;
  }
  FastLED.setBrightness(brightLevel);
  FastLED.show();
  drawButtonsScreenThree();
  runCycle = 9;
  newColorOrder = false;
}
