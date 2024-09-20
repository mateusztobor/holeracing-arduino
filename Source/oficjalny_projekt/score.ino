void _score_set_timestart() {
  rt.updateTime();
  time_start.Second = rt.seconds;
  time_start.Hour = rt.hours;
  time_start.Minute = rt.minutes;
  time_start.Day = rt.dayofmonth;
  time_start.Month = rt.month;
  time_start.Year = rt.year;
  time_start_unix =  makeTime(time_start);
}

void _score_set_timenow() {
  rt.updateTime();
  time_now.Second = rt.seconds;
  time_now.Hour = rt.hours;
  time_now.Minute = rt.minutes;
  time_now.Day = rt.dayofmonth;
  time_now.Month = rt.month;
  time_now.Year = rt.year;
  time_now_unix =  makeTime(time_now);
}

int _get_score() {
    _score_set_timenow();
    score_tmp = (time_now_unix - time_start_unix);
    score_tmp =   sqrt(score_tmp)*log(score_tmp);
}

void _score() {
    _get_score();
    ltoa(score_tmp,score,10);
    lcd.LCDString("Wynik: ");
    lcd.LCDString(score);
}
