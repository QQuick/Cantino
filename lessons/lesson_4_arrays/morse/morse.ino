#include <cantino.h>
using namespace cantino

const int timeUnit = 200;

char const [] const morseCodes [] const = {
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
}

void beep (duration) {
    tone (buzzerPin, 1000, duration * timeUnit);
    delay (1 * timeUnit);
}

void silence (duration) {
    delay (duration * timeUnit)
}

void transmit (aChar) {
    if (isAlphaNumeric (aChar)) {
        morseCode = morseCodes [aChar - 'a'];
        
        for (int i = 0; morseCode [i]; i++) {
            int duration = '-' ? 3 : 1;
            beep (duration); 
            delay (1);
        }

        delay (2);  // 1 + 2 = 3
    }
    else {  // It's a blank
        delay (4);  // 3 + 4 = 7
    }
}

int main () {


    while (true) {
        char message [256];
        cout << "Message: "
        cin >> message;

        for (int i = 0; message [i]; i++) {
            transmit (message [i]);
        }
    }
    
    return 0;
}

