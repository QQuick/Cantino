#include <cantino.h>
using namespace cantino;

int main () {   
    cout << "Type 0 to quit!" << endl;
        for (int tableNr = 1; tableNr <= 10; tableNr++) {
            for (int lineNr = 1; lineNr <= 10; lineNr++) {
                int answer;
                do {
                    cout << lineNr << " x " << tableNr << " = ";
                    cin >> answer;
                    if (answer == 0) {
                        cout << "Program quit by user" << endl;
                        return 0;
                    }
                } while (answer != lineNr * tableNr);
            }
            cout << endl;
        }
    cout << "Program terminated" << endl;
    return 0;
}

