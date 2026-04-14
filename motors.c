#include "motors.h"

void followLine(uint8_t pattern)
{
  switch (pattern) {
    case 0b00100:
      forward();
      break;

    case 0b01000:
    case 0b01100:
      turnLeft();
      break;

    case 0b00110:
    case 0b00010:
      turnRight();
      break;
    
    case 0b00000:
      stopMotors();
      break;

    default:
      forward();
      break;
  }

  delay(10);  // tiny delay for stability
}

void forward()
{
  digitalWrite(L1, HIGH);
  digitalWrite(L2, LOW);
  analogWrite(L_PWM, PWM_VAL_L);

  digitalWrite(R1, HIGH);
  digitalWrite(R2, LOW);
  analogWrite(R_PWM, PWM_VAL_R);
}

void turnLeft()
{
  digitalWrite(L1, LOW);
  digitalWrite(L2, LOW);
  analogWrite(L_PWM, 0);

  digitalWrite(R1, HIGH);
  digitalWrite(R2, LOW);
  analogWrite(R_PWM, PWM_VAL_R);
}

void turnRight()
{
  digitalWrite(L1, HIGH);
  digitalWrite(L2, LOW);
  analogWrite(L_PWM, PWM_VAL_L);

  digitalWrite(R1, LOW);
  digitalWrite(R2, LOW);
  analogWrite(R_PWM, 0);
}

void stopMotors() 
{
  digitalWrite(L1, LOW);
  digitalWrite(L2, LOW);
  analogWrite(L_PWM, 0);

  digitalWrite(R1, LOW);
  digitalWrite(R2, LOW);
  analogWrite(R_PWM, 0);
}

