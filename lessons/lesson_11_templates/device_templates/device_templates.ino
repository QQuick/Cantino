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

#include "stack.h"

using namespace cantino;

/*
It would have been nice to have destructors switching all actuators off at the end.
However it appears that virtual destructors aren't always called in a multilevel class hierachy on the Arduino.
Of course they could be switched off explicitly, but that doesn't serve any eduational purpose.
*/

int main () {   
    int const frequencyOfStandardA = 440;

    Stack <Sensor> sensors;
    sensors.push (new Switch (2), "sw");
    sensors.push (new UltrasoundSensor (4, 3, 0.2), "us"); 
    
    Stack <Actuator> actuators;
    actuators.push (new Buzzer (13, 4 * frequencyOfStandardA), "bz");
    actuators.push (new Led (9), "ld_y1");
    actuators.push (new Led (10), "ld_gr");
    actuators.push (new Led (11), "ld_y2");
    actuators.push (new Led (12), "ld_re");

    for (int i = 0; i < 100; i++) {
        (* actuators ["bz"]) (* sensors ["sw"]);
        (* actuators ["ld_y1"]) (* sensors ["sw"]);
        (* actuators ["ld_y2"]) (* sensors ["sw"]);
        
        (* actuators ["ld_gr"]) (* sensors ["us"]);
        (* actuators ["ld_re"]) (* sensors ["us"]);

        delay (100);
    }

    while (sensors.size != 0) {
        delete sensors.pop ();
    }

    while (actuators.size !=0) {
        delete actuators.pop ();
    }

    return 0;
}

