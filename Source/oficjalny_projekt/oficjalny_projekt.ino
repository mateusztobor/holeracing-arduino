//DEFINE PINS
#define PIN_LCD_RST         2     //LCD RST PIN
#define PIN_LCD_CE          3     //LCD CE PIN
#define PIN_LCD_DC          4     //LCD DC PIN
#define PIN_LCD_DIN         5     //LCD DIN PIN
#define PIN_LCD_CLK         6     //LCD CLOCK PIN
#define PIN_LCD_LIG         7     //LCD LIGHT PIN
#define PIN_LIGHT_SENSOR    0     //LIGHT SENSOR PIN
#define PIN_BUZZER          8     //BUZZER PIN
#define PIN_IR_RECEIVER     9     //IR RECEIVER PIN
#define PIN_RTC_CLK         12
#define PIN_RTC_DAT         11
#define PIN_RTC_RST         10

//CONFIG
#define CONFIG_LCD_inverse  false
#define CONFIG_LCD_contrast 0xBF // default is 0xBF set in LCDinit, Try 0xB1 - 0xBF if your display is too dark/dim
#define CONFIG_LCD_bias 0x13 // LCD bias mode 1:48: Try 0x12 , 0x13 or 0x14

//IR CONTROL CODES
#define IRC_RESET 16711935
#define IRC_MUTE 16744575
#define IRC_MANUAL_LIGHT_ENABLE 16728255
#define IRC_MANUAL_LIGHT_SET 16736415
#define IRC_START 16746615
#define IRC_TOP 16756815
#define IRC_BOT 16754775

//LOAD LIBS
#include <Arduino.h>
#include "TimeLib.h"
#include <NOKIA5110_TEXT.h> //LCD
#include <ezBuzzer.h>       //SOUND
#include <IRremote.h>       //IR
#include <virtuabotixRTC.h> //REAL TIME

//CREATING OBJECTS
NOKIA5110_TEXT lcd(PIN_LCD_RST, PIN_LCD_CE, PIN_LCD_DC, PIN_LCD_DIN, PIN_LCD_CLK);
ezBuzzer buzzer(PIN_BUZZER);
IRrecv ir(PIN_IR_RECEIVER);
decode_results irr;
virtuabotixRTC rt(PIN_RTC_CLK, PIN_RTC_DAT, PIN_RTC_RST);

void setup() {
  Serial.begin(9600);
  //seconds, minutes, hours, day of the week, day of the month, month, year
  //rt.setDS1302Time(00, 59, 18, 1, 4, 4, 2022);

  //DISPLAY
  pinMode(PIN_LCD_LIG, OUTPUT);
  DISPLAY_SET_LIGHT(0);
  lcd.LCDInit(CONFIG_LCD_inverse, CONFIG_LCD_contrast, CONFIG_LCD_bias); // init  the LCD
  lcd.LCDClear(0x00);
  lcd.LCDFont(1);
  
  //IR
  ir.enableIRIn();
  //ir.blink13(false);
  
  //BUZZER
  pinMode(PIN_BUZZER, OUTPUT);//buzzer
  

  //welcome screen
  DISPLAY_SET_LIGHT(1);
  bmp_load();
  lcd.LCDClear(0x00);//hole Racing
  DISPLAY_SET_LIGHT(0);
} 
bool mute = false;
bool display_light = false;
bool display_manual_light_enable = false;
bool init_menu = false;
bool started_game = false;
bool init_start_game = false; //always false on start
bool game_over = false;
int car_position = 2;
int holes[3][2] = {{0,0},  //level 1
                   {0,0},  //level 2
                   {0,0}}; //level 3
bool anim = true;
char score[5];
int score_tmp;

//time for score
tmElements_t time_start;
time_t time_start_unix=0;
tmElements_t time_now;
time_t time_now_unix=0;
tmElements_t time_lh;
time_t time_lh_unix=0;

int holes_speed=0;
int max_holes=0;

void loop() {
  buzzer.loop();
  IR_CONTROL();
  DISPLAY_LIGHT();
  
  
  if(started_game) {
    if(game_over) _GAME_OVER();
    else {
      //INIT START GAME
      if(!init_start_game) {
        buzzer.stop();
        car_position = 2;
        _score_set_timestart();//set timer start
        lcd.LCDFont(6);
        init_start_game = true;
      }
      lcd.LCDClear(0x00);
      draw_car();
      if(!mute) sound_car();
      anim = !anim;
      _score();
      generate_holes();
      draw_holes();
      delay(70);
    }
  } else {
    if(!init_menu) {
      bmp_menu();
      init_menu=!init_menu;
    }
    if(!mute) sound_menu();
  }

}
