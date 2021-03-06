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
#include "buzzers.h"

using namespace cantino;

Buzzer::Buzzer (char const *const label, int pinIndex, int frequency):
    Actuator (label, pinIndex),
    frequency (frequency)
{
}

void Buzzer::write (bool state) {
    Actuator::write (state);
    if (this->state) {
        tone (pinIndex, frequency);
    }
    else {
        noTone (pinIndex);
    }
}
