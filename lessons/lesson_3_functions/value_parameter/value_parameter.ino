#include <cantino.h>
using namespace cantino;

void switchBuiltinLed (bool aState, long aTime) {
    digitalWrite (LED_BUILTIN, aState);
    delay (aTime);
}

int main () {
    pinMode (LED_BUILTIN, OUTPUT);

    bool state = true;
    while (true) { // Endless control loop
        switchBuiltinLed (state, 500);
        state = !state;
    }
    
    return 0;
}

