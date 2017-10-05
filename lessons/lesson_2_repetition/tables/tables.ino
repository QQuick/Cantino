#include <cantino.h>
using namespace cantino;

int main () {
    const int tableNr = 3;
    
    for (int lineNr = 1; lineNr <= 10; lineNr++) {
        cout << lineNr << " x " << tableNr << " = " << lineNr * tableNr << endl;
    }
    
    return 0;
}

