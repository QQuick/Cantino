#include <cantino.h>
using namespace cantino;

int main () {   
    for (int tableNr = 1; tableNr <= 10; tableNr++) {
        for (int lineNr = 1; lineNr <= 10; lineNr++) {
            cout << lineNr << " x " << tableNr << " = " << lineNr * tableNr << endl;
        }
        cout << endl;
    }
    
    return 0;
}

