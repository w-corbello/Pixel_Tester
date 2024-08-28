// Touchscreen pins
#define XPT2046_IRQ 36   // T_IRQ
#define XPT2046_MOSI 32  // T_DIN
#define XPT2046_MISO 39  // T_OUT
#define XPT2046_CLK 25   // T_CLK
#define XPT2046_CS 33    // T_CS



#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240
#define FONT_SIZE 2


//Display Text Box

#define TextBox_X 10            //10
#define TextBox_Y 10            //120
#define TextBox_W 90            //50
#define TextBox_H 50            /50


// Info location position and size
#define Info_X 110
#define Info_Y 10
#define Info_W 100
#define Info_H 50

// Button position and size
#define FRAME_X 10
#define FRAME_Y 80
#define FRAME_W 90
#define FRAME_H 50



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

// White zone size
#define WhiteBUTTON_X (CT2BUTTON_X + CT2BUTTON_W + 2)
#define WhiteBUTTON_Y FRAME_Y
#define WhiteBUTTON_W (FRAME_W / 2)
#define WhiteBUTTON_H FRAME_H


//****************************************************************



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
#define But_FRAME_X 230
#define But_FRAME_Y 10
#define But_FRAME_W 90
#define But_FRAME_H 50

// Red zone size
#define ONBUTTON_X But_FRAME_X
#define ONBUTTON_Y But_FRAME_Y
#define ONBUTTON_W But_FRAME_W
#define ONBUTTON_H But_FRAME_H





// RGB LED Pins
#define CYD_LED_BLUE  17
#define CYD_LED_RED   4
#define CYD_LED_GREEN 16









// Touchscreen coordinates: (x, y) and pressure (z)
int x, y, z;

int buttonValue = 0;
int pixelLength = 0;
int tenValue = 0;
int i_bright = 0;

int runCycle = 0;
int colorOrder = 0;
int colorOrderChange = 0;
int curScreen = 0;
int curColor = 0;
int inOrderCount = 0;


int brightLevel = 0;
int maxPixels = 0;

int getValForWhat = 0;

int waitInOrderTim = 0;
int waitOneSec = 0;


bool BSPressed = false;
bool enterPressed = false;
bool buttonPressed = false;
bool buttonState = false;
bool newColorOrder = false;

bool rgbRunOK = false;
bool rgbManOK = false;
bool OKRunLight = false;
bool turnOffOnce = false;

//time
unsigned long current_time = millis();
unsigned long timeNow = 0;
unsigned long timeLast = 0;
unsigned long startTime = 0;
unsigned long endTime = 0;
int secondsSince = 0;
bool newNTP  = true;

String colorOrderProfile = "";
//time
