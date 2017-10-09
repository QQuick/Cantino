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

Device::Device (char const *const label, int pinIndex):
    label (label),
    pinIndex (pinIndex)
{
}

void Device::report () {
    cout << label << ":" << (read () ? 1:0) << ' ';
}

Sensor::Sensor (char const *const label, int pinIndex):
    Device (label, pinIndex)
{
    pinMode (this->pinIndex, INPUT);
}

Actuator::Actuator (char const *const label, int pinIndex):
    Device (label, pinIndex),
    state (false)
{
    pinMode (this->pinIndex, OUTPUT);
}

bool Actuator::read () {
    return state;
}

void Actuator::write (bool state) {
    this->state = state;
}