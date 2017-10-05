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

