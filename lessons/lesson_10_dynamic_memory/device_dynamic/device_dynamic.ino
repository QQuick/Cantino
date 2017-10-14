/*
Copyright 2017 Jacques de Hooge, GEATEC engineering, www.geatec.com

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

  http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#include <cantino.h>

#include "devices.h"
#include "switches.h"
#include "ultrasound_sensors.h"
#include "leds.h"
#include "buzzers.h"

using namespace cantino;

int main () {   
    int const frequencyOfStandardA = 440;

    Sensor * sensors [] = {
        new Switch (2),
        new UltrasoundSensor (4, 3, 0.2) 
    };
    
    const int nrOfSensors = sizeof (sensors) / sizeof (Sensor *);
    
    Actuator * actuators [] = {
        new Buzzer (13, 4 * frequencyOfStandardA),
        new Led (9),
        new Led (10),
        new Led (11),
        new Led (12),
    };
    
    const int nrOfActuators = sizeof (actuators) / sizeof (Actuator *);

    for (int index = 0; index < 10000; index++) {
        for (int actuatorIndex = 0; actuatorIndex < nrOfActuators; actuatorIndex++) {
             (* actuators [actuatorIndex]) (* sensors [actuatorIndex % nrOfSensors]);
        }
    }

    for (int sensorIndex = 0; sensorIndex < nrOfSensors; sensorIndex++) {
        delete sensors [sensorIndex];
    }

    for (int actuatorIndex = 0; actuatorIndex < nrOfActuators; actuatorIndex++) {
        delete actuators [actuatorIndex];
    }

    return 0;
}

