
#include "motors.h"
#include "cases.h"

int state = FOLLOW_LINE;

int sensorPattern; 

void setup() {
    // Sensor inputs
    for (int i = 0; i < 5; i++) {
        pinMode(sensorPins[i], INPUT);
    }

    // Motor outputs
    pinMode(L_PWM, OUTPUT);
    pinMode(R_PWM, OUTPUT);
}


void loop() {

    // 1. Read all 5 sensors and compress into a bit-pattern
    sensorPattern = readSensors();   // function not written here
    state = setState(sensorPattern);
    switch (state) {

        case FOLLOW_LINE:
            followLine(sensorPattern); 
            break;

        case LOST_LINE:
            // Robot lost the line — continue last direction
            // until sensors reacquire the line
            // (Function not implemented here)
            // lostLineBehavior();
            break;

        case CROSSROAD:
            // Robot reached a crossroad — go straight briefly
            // (Function not implemented here)
            // crossroadBehavior();
            break;

        case TURN_LEFT:
            //do turn left stuff
            break; 

        case TURN_RIGHT: 
            //
            break; 
    }
}




