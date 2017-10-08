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

int main () {
    pinMode (LED_BUILTIN, OUTPUT);
    bool again = true;
    
    while (again) { // Control loop
        for (int i = 0; i < 3; i++) {
            digitalWrite (LED_BUILTIN, true);
            delay (500);
            digitalWrite (LED_BUILTIN, false);
            delay (500);
        }
        
        cout << "Blink again <y/n>? ";
        char answer;
        cin >> answer;
        again = answer == 'y';
    }
    
    cout << "Program terminated" << endl;
    return 0;
}

