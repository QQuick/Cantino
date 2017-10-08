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
#include "ultrasound_sensors.h"

using namespace cantino;

UltrasoundSensor::UltrasoundSensor (int triggerPin, int echoPin, float switchDistance):
    triggerPin (triggerPin), echoPin (echoPin), switchDistance (switchDistance)
{
    pinMode (triggerPin, OUTPUT);
    pinMode (echoPin, INPUT);
}

bool UltrasoundSensor::read () {
    return getDistance () < switchDistance;
}

float UltrasoundSensor::getDistance () {
    digitalWrite (triggerPin, false);
    delayMicroseconds (2);
    digitalWrite (triggerPin, true);
    delayMicroseconds (10);
    digitalWrite (triggerPin, false);
    return echoToDistanceFactor * pulseIn (echoPin, true);
}

float const UltrasoundSensor::soundSpeedInAir = 340;
float const UltrasoundSensor::echoToDistanceFactor = soundSpeedInAir * 1e-6 / 2;


