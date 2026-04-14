#pragma once
#include <Arduino.h>
// motor speed vals
const uint8_t PWM_VAL_R = 0;
const uint8_t PWM_VAL_L = 0; 

// motor pwm pins 
const uint8_t L1 = 0;
const uint8_t L2 = 0; 
const uint8_t L_PWM = 1;

const uint8_t R1 = 0;
const uint8_t R2 = 0; 
const uint8_t R_PWM = 1; 

// Line-following logic
void followLine(uint8_t pattern);

// Motor control functions
void forward();
void turnLeft();
void turnRight();
void stopMotors();
