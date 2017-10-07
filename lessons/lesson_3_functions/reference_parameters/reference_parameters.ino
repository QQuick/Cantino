#include <cantino.h>
using namespace cantino;

bool toggleBuiltinLed (bool &aState, long aTime) {
    digitalWrite (LED_BUILTIN, aState);
    delay (aTime);
    aState = !aState;
}

int main () {
    pinMode (LED_BUILTIN, OUTPUT);

    bool state = true;
    while (true) {
        toggleBuiltinLed (state, 500);
    }
    
    return 0;
}

