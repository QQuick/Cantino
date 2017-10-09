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

using namespace cantino;

Switch::Switch (char const *const label, int pinIndex):
    Sensor (label, pinIndex)
{
    pinMode (this->pinIndex, INPUT_PULLUP);
}

bool Switch::read () {
    return !digitalRead (pinIndex);
}

