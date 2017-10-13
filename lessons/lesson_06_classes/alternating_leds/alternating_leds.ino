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

using namespace cantino;

//  Class declarations

class Led {
    public:
        Led (int pinIndex);
        void write (bool state);
        bool read ();
    private:
        int aPinIndex;
        bool aState;
};

// Method definitions

Led::Led (int pinIndex) {
    aPinIndex = pinIndex;
    aState = false;
    pinMode (aPinIndex, OUTPUT);
}

void Led::write (bool state) {
    aState = state;
    digitalWrite (aPinIndex, aState);
}

bool Led::read () {
    return aState;
}

// Object instantiations and use

int main () {
    Led led0 (10), led1 (12);
    static bool toggle = false;

    while (true) {
        led0.write (toggle);
        led1.write (!led0.read ());
        toggle = !toggle;
        delay (500);
    }
    
    return 0;
}

