void IR_CONTROL() {
  if (ir.decode(&irr)){
    switch (irr.value) {
      case IRC_RESET:
        //digitalWrite(PIN_RESET,LOW);
        resetFunc(); 
      break;
      
      case IRC_MUTE:
        mute=!mute;
        buzzer.stop();
      break;

      case IRC_MANUAL_LIGHT_ENABLE:
        display_manual_light_enable = !display_manual_light_enable;
        DISPLAY_SET_LIGHT(!display_light);
      break;

      case IRC_MANUAL_LIGHT_SET:
        if(display_manual_light_enable)
          DISPLAY_SET_LIGHT(!display_light);
      break;

      case IRC_TOP:
        if(started_game && car_position > 1) car_position--;
      break;

      case IRC_BOT:
        if(started_game && car_position < 3) car_position++;
      break;

      case IRC_START:
        if(!started_game) started_game=!started_game;
      break;

      default:
      break;
    }  
    //Serial.println(irr.value);
    ir.resume();
  }
}
