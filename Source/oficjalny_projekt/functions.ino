void(* resetFunc) (void) = 0;

void _GAME_OVER() {
    buzzer.stop();

    holes[0][0] = 0;
    holes[0][1] = 0;
    holes[1][0] = 0;
    holes[1][1] = 0;
    holes[2][0] = 0;
    holes[2][1] = 0;
    
    lcd.LCDClear(0x00);
    if(!mute) sound_lost();
    lcd.LCDInit(!CONFIG_LCD_inverse, CONFIG_LCD_contrast, CONFIG_LCD_bias);
    lcd.LCDFont(1);
    lcd.LCDgotoXY(10, 2);
    
    lcd.LCDString("GAME OVER");

    if(!mute) {
      for(int i=0; i<50; i+=1) {
        buzzer.loop();
        delay(100);
      }
    }
    else //delay(4000);

    lcd.LCDClear(0x00);
    lcd.LCDInit(CONFIG_LCD_inverse, CONFIG_LCD_contrast, CONFIG_LCD_bias);
    
    game_over=false;
    started_game=false;
    init_menu=false;
    init_start_game=false;
}


void MUTE() {
  mute = !mute;
  buzzer.stop();
}

void generate_holes() {
  if(score_tmp > 20) {
    holes_speed = 1;
    _holes_timeupdate();
    max_holes = 2;
    
  }
  if(score_tmp > 20) {
    holes_speed = 3;
    
  }
  else if(score_tmp > 10) {
    holes_speed = 2;
    
  }
  else if(score_tmp > 1) {
    holes_speed = 1;
    _holes_timeupdate();
  }
  else if(score_tmp > 0) {
    max_holes = 1;
  }

  if(score_tmp < 3) {
    max_holes = 1;
    holes_speed = 0;
    _holes_timeupdate();
  }
  else if(score_tmp < 12) {
    holes_speed = 1;
    _holes_timeupdate();
  }
  else if(score_tmp < 20) {
    holes_speed = 2;
    _holes_timeupdate();
  }
  else if(score_tmp < 30) {
    holes_speed = 2;
    max_holes = 1;
    _holes_timeupdate();
  }

  if(_holes_gettime() < holes_speed) {
      
      if(holes[0][0] != 0) {
        if(holes[0][1] > 1) holes[0][1]--;
        else if(car_position == 1) game_over=true;
        else holes[0][0] = 0;
      }
      if(holes[1][0] != 0) {
        if(holes[1][1] > 1) holes[1][1]--;
        else if(car_position == 2) game_over=true;
        else holes[1][0] = 0;
      }
      if(holes[2][0] != 0) {
        if(holes[2][1] > 1) holes[2][1]--;
        else if(car_position == 3) game_over=true;
        else holes[2][0] = 0;
      }

      _holes_timeupdate();
  }
  if(_holes_count() < max_holes)
      _generate_holes();
}

void _generate_holes() {
  int r = random(0, 3);
  holes[r][0] = 1;
  holes[r][1] = 5;
}

void _holes_timeupdate() {
  rt.updateTime();
  time_lh.Second = rt.seconds;
  time_lh.Hour = rt.hours;
  time_lh.Minute = rt.minutes;
  time_lh.Day = rt.dayofmonth;
  time_lh.Month = rt.month;
  time_lh.Year = rt.year;
  time_lh_unix =  makeTime(time_lh);
}

int _holes_gettime() {
  return (time_now_unix - time_lh_unix);
}

int _holes_count() {
  int c=0;
  if(holes[0][0] != 0) c++;
  if(holes[1][0] != 0) c++;
  if(holes[2][0] != 0) c++;
  return c;
}
