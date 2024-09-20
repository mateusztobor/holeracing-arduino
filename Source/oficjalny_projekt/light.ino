int GET_LIGHT_SENSOR_VALUE() {
  return analogRead(PIN_LIGHT_SENSOR);
}

void DISPLAY_SET_LIGHT(bool set) {
  if(set) {
      digitalWrite(PIN_LCD_LIG,LOW);
      display_light = true;
  } else {
      digitalWrite(PIN_LCD_LIG,HIGH);
      display_light = false;
  }
}

void DISPLAY_AUTO_LIGHT() {
  if(display_light) {
    if(GET_LIGHT_SENSOR_VALUE() >= 25)
      DISPLAY_SET_LIGHT(0);
  } else {
    if(GET_LIGHT_SENSOR_VALUE() <= 15)
      DISPLAY_SET_LIGHT(1);
  }
}

void DISPLAY_LIGHT() {
     if(!display_manual_light_enable)
      DISPLAY_AUTO_LIGHT();
}
