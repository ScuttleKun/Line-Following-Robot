#include "cases.h":

int setState(uint8_t sensorPattern) {
  int state; 
  if (sensorPattern == 0b00000) {
    state = LOST_LINE;
  }
  else if (sensorPattern == 0b11111) {
    state = CROSSROAD;
  }
  else if(sensorPattern = 0b11100){
    state = TURN_LEFT;
  }
  else if(sensorPattern = 0b00111){
    state = TURN_RIGHT;
  }
  else {
        state = FOLLOW_LINE;
  }

  return state;
}


uint8_t readSensors() {

    uint8_t pattern = 0;

    for (int i = 0; i < 5; i++) {
        pattern <<= 1;                      // shift existing bits left
        pattern |= map(analogRead(sensorPins[i]), SENSOR_MIN, SENSOR_MAX, LOW, HIGH); // add new bit (0 or 1)
    }
    return pattern;
}

