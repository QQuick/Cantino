#include <cantino.h>
using namespace cantino;

int const timeUnit = 50;
int const buzzerPin = 11;
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

