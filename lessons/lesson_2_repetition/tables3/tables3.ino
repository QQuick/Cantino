#include <cantino.h>
using namespace cantino;

int main () {   
    cout << "Type 0 to quit!" << endl;
    
    for (int tableNr = 1; tableNr <= 10; tableNr++) {
        for (int lineNr = 2; lineNr <= 10; lineNr++) {
            int answer = -1;

            do {
                cout << lineNr << " x " << tableNr << " = ";
                
                if (answer == 0) {
                    break;
                }
                
                cin >> answer;
            } while (answer != lineNr * tableNr);
            
            if (answer == 0) {
                break;
            }
        }
        cout << endl;
    }
    return 0;
}

