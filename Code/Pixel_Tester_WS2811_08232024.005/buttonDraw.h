// Draw button frame
void drawFrame() {
  tft.drawRect(But_FRAME_X, But_FRAME_Y, But_FRAME_W, But_FRAME_H, TFT_BLACK);
}

// Draw a ON/Off button
void drawONButton() {
  Serial.print("RunCycle: ");
  Serial.println(runCycle);
  switch (runCycle) {
    case 0:
      tft.fillRect(ONBUTTON_X, ONBUTTON_Y, ONBUTTON_W, ONBUTTON_H, TFT_WHITE);  //TFT_RED
      tft.fillRect(Info_X, Info_Y, Info_W, Info_H, TFT_WHITE);  //
      break;
    case 1:
      tft.fillRect(ONBUTTON_X, ONBUTTON_Y, ONBUTTON_W, ONBUTTON_H, TFT_RED);  //TFT_RED
      tft.fillRect(Info_X, Info_Y, Info_W, Info_H, TFT_WHITE);  //
      break;
    case 2:
      tft.fillRect(ONBUTTON_X, ONBUTTON_Y, ONBUTTON_W, ONBUTTON_H, TFT_GREEN);  //TFT_GREEN
      tft.fillRect(Info_X, Info_Y, Info_W, Info_H, TFT_WHITE);  //
      break;
    case 3:
      tft.fillRect(ONBUTTON_X, ONBUTTON_Y, ONBUTTON_W, ONBUTTON_H, TFT_BLUE);  //TFT_GREEN
      tft.fillRect(Info_X, Info_Y, Info_W, Info_H, TFT_WHITE);  //
      break;
    case 4:
      tft.fillRect(ONBUTTON_X, ONBUTTON_Y, ONBUTTON_W, ONBUTTON_H, TFT_WHITE);  //TFT_GREEN
      tft.fillRect(Info_X, Info_Y, Info_W, Info_H, TFT_WHITE);  //
      break;
    case 5:
      tft.fillRect(ONBUTTON_X, ONBUTTON_Y, ONBUTTON_W, ONBUTTON_H, TFT_WHITE);  //TFT_GREEN
      tft.fillRect(Info_X, Info_Y, Info_W, Info_H, TFT_WHITE);  //
      break;
    case 6:
      tft.fillRect(ONBUTTON_X, ONBUTTON_Y, ONBUTTON_W, ONBUTTON_H, TFT_WHITE);  //TFT_GREEN
      tft.fillRect(Info_X, Info_Y, Info_W, Info_H, TFT_WHITE);  //
      break;
    case 7:
      tft.fillRect(ONBUTTON_X, ONBUTTON_Y, ONBUTTON_W, ONBUTTON_H, TFT_WHITE);  //TFT_GREEN
      tft.fillRect(Info_X, Info_Y, Info_W, Info_H, TFT_WHITE);  //
      break;
    case 8:
      tft.fillRect(ONBUTTON_X, ONBUTTON_Y, ONBUTTON_W, ONBUTTON_H, TFT_WHITE);  //TFT_GREEN
      tft.fillRect(Info_X, Info_Y, Info_W, Info_H, TFT_WHITE);  //
      break;
    case 9:
      tft.fillRect(ONBUTTON_X, ONBUTTON_Y, ONBUTTON_W, ONBUTTON_H, TFT_WHITE);  //TFT_GREEN
      tft.fillRect(Info_X, Info_Y, Info_W, Info_H, TFT_WHITE);  //
      break;
    case 10:
      tft.fillRect(ONBUTTON_X, ONBUTTON_Y, ONBUTTON_W, ONBUTTON_H, TFT_WHITE);  //TFT_GREEN
      tft.fillRect(Info_X, Info_Y, Info_W, Info_H, TFT_WHITE);  //
      break;
    case 11:
      tft.fillRect(ONBUTTON_X, ONBUTTON_Y, ONBUTTON_W, ONBUTTON_H, TFT_WHITE);  //TFT_GREEN
      tft.fillRect(Info_X, Info_Y, Info_W, Info_H, TFT_WHITE);  //
      break;
    default:
      tft.fillRect(ONBUTTON_X, ONBUTTON_Y, ONBUTTON_W, ONBUTTON_H, TFT_WHITE);  //TFT_RED
      tft.fillRect(Info_X, Info_Y, Info_W, Info_H, TFT_WHITE);  //
      break;
  }


  drawFrame();
  tft.setTextColor(TFT_BLACK);
  tft.setTextSize(FONT_SIZE);
  tft.setTextDatum(MC_DATUM);

  switch (runCycle) {
    case 0:
      tft.drawString("OFF", ONBUTTON_X + (ONBUTTON_W / 2), ONBUTTON_Y + (ONBUTTON_H / 2));
      tft.drawString(" ", Info_X + (Info_W / 2), Info_Y + (Info_H / 2));
      break;
    case 1:
      tft.drawString("ON", ONBUTTON_X + (ONBUTTON_W / 2), ONBUTTON_Y + (ONBUTTON_H / 2));
      tft.drawString("Red", Info_X + (Info_W / 2), Info_Y + (Info_H / 2));
      break;
    case 2:
      tft.drawString("ON", ONBUTTON_X + (ONBUTTON_W / 2), ONBUTTON_Y + (ONBUTTON_H / 2));
      tft.drawString("Green", Info_X + (Info_W / 2), Info_Y + (Info_H / 2));
      break;
    case 3:
      tft.drawString("ON", ONBUTTON_X + (ONBUTTON_W / 2), ONBUTTON_Y + (ONBUTTON_H / 2));
      tft.drawString("Blue", Info_X + (Info_W / 2), Info_Y + (Info_H / 2));
      break;
    case 4:
      tft.drawString("ON", ONBUTTON_X + (ONBUTTON_W / 2), ONBUTTON_Y + (ONBUTTON_H / 2));
      tft.drawString("Count", Info_X + (Info_W / 2), Info_Y + (Info_H / 2));
      break;
    case 5:
      tft.drawString("ON", ONBUTTON_X + (ONBUTTON_W / 2), ONBUTTON_Y + (ONBUTTON_H / 2));
      tft.drawString("Count 2", Info_X + (Info_W / 2), Info_Y + (Info_H / 2));
      break;
    case 6:
      tft.drawString("ON", ONBUTTON_X + (ONBUTTON_W / 2), ONBUTTON_Y + (ONBUTTON_H / 2));
      tft.drawString("White", Info_X + (Info_W / 2), Info_Y + (Info_H / 2));
      break;
    case 7:
      tft.drawString("ON", ONBUTTON_X + (ONBUTTON_W / 2), ONBUTTON_Y + (ONBUTTON_H / 2));
      tft.drawString("RGGBBB", Info_X + (Info_W / 2), Info_Y + (Info_H / 2));
      break;
    case 8:
      tft.drawString("ON", ONBUTTON_X + (ONBUTTON_W / 2), ONBUTTON_Y + (ONBUTTON_H / 2));
      tft.drawString("RGB Run", Info_X + (Info_W / 2), Info_Y + (Info_H / 2));
      break;
    case 9:
      tft.drawString("ON", ONBUTTON_X + (ONBUTTON_W / 2), ONBUTTON_Y + (ONBUTTON_H / 2));
      tft.drawString("Chk Ord", Info_X + (Info_W / 2), Info_Y + (Info_H / 2));
      break;
    case 10:
      tft.drawString("OFF", ONBUTTON_X + (ONBUTTON_W / 2), ONBUTTON_Y + (ONBUTTON_H / 2));
      tft.drawString("Int", Info_X + (Info_W / 2), Info_Y + (Info_H / 2));
      break;
    case 11:
      tft.drawString("OFF", ONBUTTON_X + (ONBUTTON_W / 2), ONBUTTON_Y + (ONBUTTON_H / 2));
      tft.drawString("Length", Info_X + (Info_W / 2), Info_Y + (Info_H / 2));
      break;
    case 12:
      tft.drawString("OFF", ONBUTTON_X + (ONBUTTON_W / 2), ONBUTTON_Y + (ONBUTTON_H / 2));
      tft.drawString("Cnt 2", Info_X + (Info_W / 2), Info_Y + (Info_H / 2));
      break;
    default:
      tft.drawString("OFF", ONBUTTON_X + (ONBUTTON_W / 2), ONBUTTON_Y + (ONBUTTON_H / 2));
      tft.drawString(" ", Info_X + (Info_W / 2), Info_Y + (Info_H / 2));
      break;
  }

}


void drawButtonsScreenOne() {
  Serial.println("Screen 1");
  //tft.fillScreen(TFT_BLACK);
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
  //tft.fillRect(BSBUTTON_X, BSBUTTON_Y, BSBUTTON_W, BSBUTTON_H, TFT_WHITE);

  //Line 3
  //tft.fillRect(SixBUTTON_X, SixBUTTON_Y, SixBUTTON_W, SixBUTTON_H, TFT_WHITE);
  //tft.fillRect(SevenBUTTON_X, SevenBUTTON_Y, SevenBUTTON_W, SevenBUTTON_H, TFT_WHITE);
  //tft.fillRect(EightBUTTON_X, EightBUTTON_Y, EightBUTTON_W, EightBUTTON_H, TFT_WHITE);
  //tft.fillRect(NineBUTTON_X, NineBUTTON_Y, NineBUTTON_W, NineBUTTON_H, TFT_WHITE);
  //tft.fillRect(EnterBUTTON_X, EnterBUTTON_Y, EnterBUTTON_W, EnterBUTTON_H, TFT_WHITE);

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


  tft.drawString("Ord", ZeroBUTTON_X + (ZeroBUTTON_W / 2), ZeroBUTTON_Y + (50 / 2));
  tft.drawString("RGB", OneBUTTON_X + (OneBUTTON_W / 2), OneBUTTON_Y + (50 / 2));
  tft.drawString("??", TwoBUTTON_X + (TwoBUTTON_W / 2), TwoBUTTON_Y + (50 / 2));
  tft.drawString("Int", ThreeBUTTON_X + (ThreeBUTTON_W / 2), ThreeBUTTON_Y + (50 / 2));
  tft.drawString("Max", FourBUTTON_X + (FourBUTTON_W / 2), FourBUTTON_Y + (50 / 2));
  tft.drawString("Ct2", FiveBUTTON_X + (FiveBUTTON_W / 2), FiveBUTTON_Y + (50 / 2));
  //tft.drawString("", BSBUTTON_X + (BSBUTTON_W / 2), BSBUTTON_Y + (50 / 2));

  //tft.drawString("", SixBUTTON_X + (SixBUTTON_W / 2), SixBUTTON_Y + (50 / 2));
  //tft.drawString("", SevenBUTTON_X + (SevenBUTTON_W / 2), SevenBUTTON_Y + (50 / 2));
  //tft.drawString("", EightBUTTON_X + (EightBUTTON_W / 2), EightBUTTON_Y + (50 / 2));
  //tft.drawString("", NineBUTTON_X + (NineBUTTON_W / 2), NineBUTTON_Y + (50 / 2));
  //tft.drawString("", EnterBUTTON_X + (EnterBUTTON_W / 2), EnterBUTTON_Y + (50 / 2));
}


void drawButtonsScreenTwo() {
  Serial.println("Screen 2");
  //tft.fillScreen(TFT_BLACK);
  tft.fillRect(TextBox_X, TextBox_Y, TextBox_W, 50, TFT_WHITE);
  //Line 1
  //tft.fillRect(RedBUTTON_X, RedBUTTON_Y, RedBUTTON_W, 50, TFT_RED);
  //tft.fillRect(GreenBUTTON_X, GreenBUTTON_Y, GreenBUTTON_W, 50, TFT_GREEN);
  //tft.fillRect(BlueBUTTON_X, BlueBUTTON_Y, BlueBUTTON_W, 50, TFT_BLUE);
  //tft.fillRect(CTBUTTON_X, CTBUTTON_Y, CTBUTTON_W, 50, TFT_WHITE);
  //tft.fillRect(CT2BUTTON_X, CT2BUTTON_Y, CT2BUTTON_W, 50, TFT_WHITE);
  //tft.fillRect(WhiteBUTTON_X, WhiteBUTTON_Y, WhiteBUTTON_W, 50, TFT_WHITE);

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
  tft.drawString("Cng Ord", Info_X + (Info_W / 2), Info_Y + (Info_H / 2));
  //tft.drawString("0", RedBUTTON_X + (RedBUTTON_W / 2), RedBUTTON_Y + (50 / 2));
  //tft.drawString("0", GreenBUTTON_X + (GreenBUTTON_W / 2), GreenBUTTON_Y + (50 / 2));
  //tft.drawString("0", BlueBUTTON_X + (BlueBUTTON_W / 2), BlueBUTTON_Y + (50 / 2));
  //tft.drawString("CT", CTBUTTON_X + (CTBUTTON_W / 2), CTBUTTON_Y + (50 / 2));
  //tft.drawString("C2", CT2BUTTON_X + (CT2BUTTON_W / 2), CT2BUTTON_Y + (50 / 2));
  //tft.drawString("WH", WhiteBUTTON_X + (WhiteBUTTON_W / 2), WhiteBUTTON_Y + (50 / 2));


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


  switch (getValForWhat) {
    case 0:
      // do nothing
      break;
    case 1:// max intensity of pixels
      tft.fillRect(Info_X, Info_Y, Info_W, Info_H, TFT_WHITE);  //
      tft.drawString("Int", Info_X + (Info_W / 2), Info_Y + (Info_H / 2));
      break;
    case 2:  // max length of pixels
      tft.fillRect(Info_X, Info_Y, Info_W, Info_H, TFT_WHITE);  //
      tft.drawString("Stn Len", Info_X + (Info_W / 2), Info_Y + (Info_H / 2));
      break;
    case 3: // change count length pixels
      tft.fillRect(Info_X, Info_Y, Info_W, Info_H, TFT_WHITE);  //
      tft.drawString("Ct2 Len", Info_X + (Info_W / 2), Info_Y + (Info_H / 2));
      break;
    default:
      // statements
      break;
  }


}


void drawButtonsScreenThree() {
  Serial.println("Screen 3");
  // tft.fillScreen(TFT_BLACK);
  tft.fillRect(TextBox_X, TextBox_Y, TextBox_W, 50, TFT_WHITE);
  //Line 1
  //tft.fillRect(RedBUTTON_X, RedBUTTON_Y, RedBUTTON_W, 50, TFT_RED);
  //tft.fillRect(GreenBUTTON_X, GreenBUTTON_Y, GreenBUTTON_W, 50, TFT_GREEN);
  //tft.fillRect(BlueBUTTON_X, BlueBUTTON_Y, BlueBUTTON_W, 50, TFT_BLUE);
  //tft.fillRect(CTBUTTON_X, CTBUTTON_Y, CTBUTTON_W, 50, TFT_WHITE);
  //tft.fillRect(CT2BUTTON_X, CT2BUTTON_Y, CT2BUTTON_W, 50, TFT_WHITE);
  //tft.fillRect(WhiteBUTTON_X, WhiteBUTTON_Y, WhiteBUTTON_W, 50, TFT_WHITE);

  //Line 2
  tft.fillRect(ZeroBUTTON_X, ZeroBUTTON_Y, ZeroBUTTON_W, 50, TFT_WHITE);
  tft.fillRect(OneBUTTON_X, OneBUTTON_Y, OneBUTTON_W, OneBUTTON_H, TFT_WHITE);
  tft.fillRect(TwoBUTTON_X, TwoBUTTON_Y, TwoBUTTON_W, TwoBUTTON_H, TFT_WHITE);
  tft.fillRect(ThreeBUTTON_X, ThreeBUTTON_Y, ThreeBUTTON_W, ThreeBUTTON_H, TFT_WHITE);
  tft.fillRect(FourBUTTON_X, FourBUTTON_Y, FourBUTTON_W, FourBUTTON_H, TFT_WHITE);
  tft.fillRect(FiveBUTTON_X, FiveBUTTON_Y, FiveBUTTON_W, FiveBUTTON_H, TFT_WHITE);
  //tft.fillRect(BSBUTTON_X, BSBUTTON_Y, BSBUTTON_W, BSBUTTON_H, TFT_WHITE);

  //Line 3
  //tft.fillRect(SixBUTTON_X, SixBUTTON_Y, SixBUTTON_W, SixBUTTON_H, TFT_WHITE);
  //tft.fillRect(SevenBUTTON_X, SevenBUTTON_Y, SevenBUTTON_W, SevenBUTTON_H, TFT_WHITE);
  //tft.fillRect(EightBUTTON_X, EightBUTTON_Y, EightBUTTON_W, EightBUTTON_H, TFT_WHITE);
  //tft.fillRect(NineBUTTON_X, NineBUTTON_Y, NineBUTTON_W, NineBUTTON_H, TFT_WHITE);
  tft.fillRect(EnterBUTTON_X, EnterBUTTON_Y, EnterBUTTON_W, EnterBUTTON_H, TFT_WHITE);
  tft.setTextColor(TFT_BLACK);
  tft.setTextSize(FONT_SIZE);
  tft.setTextDatum(MC_DATUM);

  tft.drawString(colorOrderProfile, TextBox_X + (TextBox_W / 2), TextBox_Y + (50 / 2));
  //tft.drawString("0", RedBUTTON_X + (RedBUTTON_W / 2), RedBUTTON_Y + (50 / 2));
  //tft.drawString("0", GreenBUTTON_X + (GreenBUTTON_W / 2), GreenBUTTON_Y + (50 / 2));
  //tft.drawString("0", BlueBUTTON_X + (BlueBUTTON_W / 2), BlueBUTTON_Y + (50 / 2));
  //tft.drawString("CT", CTBUTTON_X + (CTBUTTON_W / 2), CTBUTTON_Y + (50 / 2));
  //tft.drawString("C2", CT2BUTTON_X + (CT2BUTTON_W / 2), CT2BUTTON_Y + (50 / 2));
  //tft.drawString("WH", WhiteBUTTON_X + (WhiteBUTTON_W / 2), WhiteBUTTON_Y + (50 / 2));


  tft.drawString("0", ZeroBUTTON_X + (ZeroBUTTON_W / 2), ZeroBUTTON_Y + (50 / 2));
  tft.drawString("1", OneBUTTON_X + (OneBUTTON_W / 2), OneBUTTON_Y + (50 / 2));
  tft.drawString("2", TwoBUTTON_X + (TwoBUTTON_W / 2), TwoBUTTON_Y + (50 / 2));
  tft.drawString("3", ThreeBUTTON_X + (ThreeBUTTON_W / 2), ThreeBUTTON_Y + (50 / 2));
  tft.drawString("4", FourBUTTON_X + (FourBUTTON_W / 2), FourBUTTON_Y + (50 / 2));
  tft.drawString("5", FiveBUTTON_X + (FiveBUTTON_W / 2), FiveBUTTON_Y + (50 / 2));
  //tft.drawString("<", BSBUTTON_X + (BSBUTTON_W / 2), BSBUTTON_Y + (50 / 2));
  //tft.drawString("6", SixBUTTON_X + (SixBUTTON_W / 2), SixBUTTON_Y + (50 / 2));
  //tft.drawString("7", SevenBUTTON_X + (SevenBUTTON_W / 2), SevenBUTTON_Y + (50 / 2));
  //tft.drawString("8", EightBUTTON_X + (EightBUTTON_W / 2), EightBUTTON_Y + (50 / 2));
  //tft.drawString("9", NineBUTTON_X + (NineBUTTON_W / 2), NineBUTTON_Y + (50 / 2));
  tft.drawString("Ent", EnterBUTTON_X + (EnterBUTTON_W / 2), EnterBUTTON_Y + (50 / 2));
}
