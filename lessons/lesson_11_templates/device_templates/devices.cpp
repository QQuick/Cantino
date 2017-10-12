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

using namespace cantino;

Device::Device (int pinIndex):
    pinIndex (pinIndex)
{
}

Device::operator bool () {
    return read ();
}

Sensor::Sensor (int pinIndex):
    Device (pinIndex)
{
    pinMode (this->pinIndex, INPUT);
}

Actuator::Actuator (int pinIndex):
    Device (pinIndex),
    state (false)
{
    pinMode (this->pinIndex, OUTPUT);
}

void Actuator::operator () (bool state) {
    write (state);
}

bool Actuator::read () {
    return state;
}

void Actuator::write (bool state) {
    cout << "ac write" << endl;
    this->state = state;
}

