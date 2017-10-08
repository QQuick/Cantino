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

int const timeUnit = 50;
int const buzzerPin = 13;
int const frequencyOfStandardA = 440;
int const beepFrequency = 2 * 2 * frequencyOfStandardA; //  Each doubling is an octave up

char const *const morseCodes [] = {
    ".-",       // a
    "-...",     // b
    "-.-.",     // c
    "-..",      // d
    ".",        // e
    "..-.",     // f
    "--.",      // g
    "....",     // h
    "..",       // i
    ".---",     // j
    "-.-",      // k
    ".-..",     // l
    "--",       // m
    "-.",       // n
    "---",      // o
    ".--.",     // p
    "--.-",     // q
    ".-.",      // r
    "...",      // s
    "-",        // t
    "..-",      // u
    "...-",     // v
    ".--",      // w
    "-..-",     // x
    "-.--",     // y
    "--..",     // z

    "-----",    // 0
    ".----",    // 1
    "..---",    // 2
    "...--",    // 3
    "....-",    // 4
    ".....",    // 5
    "-....",    // 6
    "--...",    // 7
    "---..",    // 8
    "----."     // 9
};

void delayUnits (int duration) {
    delay (duration * timeUnit);
}

void beep (int duration) {
    tone (buzzerPin, beepFrequency);
    delayUnits (duration);
    noTone (buzzerPin);
    delayUnits (1);
}

void transmit (char aChar) {
    if (aChar == ' ') {
        delayUnits (4);  // 3 + 4 = 7
    }
    else {
        char const *morseCode = morseCodes [aChar - 'a'];
        
        for (int i = 0; morseCode [i]; i++) {
            int duration = morseCode [i] == '-' ? 3 : 1;
            beep (duration); 
            delayUnits (1);
        }

        delayUnits (2);  // 1 + 2 = 3
    }
}

int main () {
    pinMode (buzzerPin, OUTPUT);
    
    while (true) {
        char message [256];
        cout << "Message: ";
        cin >> message;

        for (int i = 0; message [i]; i++) {
            transmit (message [i]);
        }
    }
    
    return 0;
}

