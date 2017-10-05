#include <cantino.h>
using namespace cantino;

bool switchBuiltinLed (bool aState, long aTime) {
    digitalWrite (LED_BUILTIN, aState);
    delay (aTime);
    return !aState;
}

int main () {
    pinMode (LED_BUILTIN, OUTPUT);

    bool state = true;
    while (true) {
        state = switchBuiltinLed (state, 500);
    }
    
    return 0;
}

