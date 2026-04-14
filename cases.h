#pragma once 
 #include <Arduino.h>
 
  int setState(uint8_t sensorPattern); 
  uint8_t readSensors();
  enum {FOLLOW_LINE, LOST_LINE, CROSSROAD, TURN_LEFT, TURN_RIGHT};

  //sensor setup
  const uint8_t SENSOR_MAX = 1023;
  const uint8_t SENSOR_MIN = 0;

  // Sensor pins (left to right on array)
  const int sensorPins[5] = {2, 3, 4, 5, 6};


 

