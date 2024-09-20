int menu_melody[] = {
  NOTE_D5, NOTE_B4, NOTE_D5, NOTE_CS5, NOTE_D5, NOTE_CS5, NOTE_A4, NOTE_A4, NOTE_FS5, NOTE_E5, NOTE_D5, NOTE_CS5, NOTE_D5, NOTE_CS5, NOTE_A4, NOTE_D5, NOTE_B4, NOTE_D5, NOTE_CS5, NOTE_D5, NOTE_CS5, NOTE_A4, NOTE_B4, NOTE_B4, NOTE_G4, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_A4, NOTE_D4, NOTE_D5, NOTE_B4, NOTE_D5, NOTE_CS5, NOTE_D5, NOTE_CS5, NOTE_A4, NOTE_A4, NOTE_FS5, NOTE_E5, NOTE_D5, NOTE_CS5, NOTE_D5, NOTE_CS5, NOTE_A4, NOTE_D5, NOTE_B4, NOTE_D5, NOTE_CS5, NOTE_D5, NOTE_CS5, NOTE_A4, NOTE_B4, NOTE_B4, NOTE_G4, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_A4, NOTE_D4, NOTE_D4, NOTE_FS4, NOTE_E4, NOTE_D4, NOTE_E4, NOTE_FS4, NOTE_D4, NOTE_D4, NOTE_FS4, NOTE_F4, NOTE_D4, NOTE_F4, NOTE_E4, NOTE_D5, NOTE_B4, NOTE_D5, NOTE_CS5, NOTE_D5, NOTE_CS5, NOTE_A4, NOTE_A4, NOTE_FS5, NOTE_E5, NOTE_D5, NOTE_CS5, NOTE_D5, NOTE_CS5, NOTE_A4, NOTE_D5, NOTE_B4, NOTE_D5, NOTE_CS5, NOTE_D5, NOTE_CS5, NOTE_A4, NOTE_B4, NOTE_B4, NOTE_G4, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_A4, NOTE_D4, NOTE_D5, NOTE_B4, NOTE_D5, NOTE_CS5, NOTE_D5, NOTE_CS5, NOTE_A4, NOTE_A4, NOTE_FS5, NOTE_E5, NOTE_D5, NOTE_CS5, NOTE_D5, NOTE_CS5, NOTE_A4, NOTE_D5, NOTE_B4, NOTE_D5, NOTE_CS5, NOTE_D5, NOTE_CS5, NOTE_A4, NOTE_B4, NOTE_B4, NOTE_G4, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_A4, NOTE_D4, NOTE_D4, NOTE_FS4, NOTE_E4, NOTE_D4, NOTE_E4, NOTE_FS4, NOTE_D4, NOTE_D4, NOTE_FS4, NOTE_F4, NOTE_D4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_A4, NOTE_CS5, NOTE_FS5, NOTE_E5, NOTE_D5, NOTE_A5
};

int menu_noteDurations[] {
  8,4,8,4,8,4,2,8,8,4,8,4,8,4,2,8,4,8,4,8,4,2,8,8,4,8,4,8,4,2,8,4,8,4,8,4,2,8,8,4,8,4,8,4,2,8,4,8,4,8,4,2,8,8,4,8,4,8,4,8,8,8,1,8,8,1,8,8,8,1,8,8,1,8,4,8,4,8,4,2,8,8,4,8,4,8,4,2,8,4,8,4,8,4,2,8,8,4,8,4,8,4,2,8,4,8,4,8,4,2,8,8,4,8,4,8,4,2,8,4,8,4,8,4,2,8,8,4,8,4,8,4,8,8,8,1,8,8,1,8,8,8,1,8,8,8,2,8,8,8,4,8,4
};

int car_melody[] {
  NOTE_A2,NOTE_B1,NOTE_C2,NOTE_D3
};

int car_noteDurations[] {
  16,8,8,16
};

int lost_melody[] {
  NOTE_D7,NOTE_D7,NOTE_A6,NOTE_D7,NOTE_B6
  //NOTE_A2,NOTE_B1,NOTE_C2,NOTE_D3
};

int lost_noteDurations[] {
  4,4,4,4,4
};

//------------------------------------------------------------------------------------------------------------------------------------------------------------------

void sound_menu() {
  int noteLength = sizeof(menu_noteDurations) / sizeof(int);
  if(buzzer.getState() == BUZZER_IDLE)
    buzzer.playMelody(menu_melody, menu_noteDurations, noteLength); // playing
}

int sound_car() {
  int noteLength = sizeof(car_noteDurations) / sizeof(int);
  if(buzzer.getState() == BUZZER_IDLE)
    buzzer.playMelody(car_melody, car_noteDurations, noteLength); // playing
}

int sound_lost() {
  int noteLength = sizeof(lost_noteDurations) / sizeof(int);
  if(buzzer.getState() == BUZZER_IDLE)
    buzzer.playMelody(lost_melody, lost_noteDurations, noteLength); // playing
}
