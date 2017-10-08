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

#include "switches.h"
#include "ultrasound_sensors.h"
#include "leds.h"
#include "buzzers.h"

using namespace cantino;

int main () {
    int const frequencyOfStandardA = 440;
    
    Switch aSwitch (2);
    UltrasoundSensor ultrasoundSensor (3, 4, 0.2);
    Led greenLed (11), redLed (12);
    Buzzer buzzer (13, 4 * frequencyOfStandardA);
    
    while (true) {
        greenLed.write (aSwitch.read ());
        redLed.write (!greenLed.read ());
        buzzer.write (ultrasoundSensor.read ()); 
    }
     
    return 0;
}

