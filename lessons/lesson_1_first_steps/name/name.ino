#include <cantino.h>
using namespace cantino;

int main () {
    cout << "What's your name? ";
    char name [32];
    cin >> name;
    cout << "Hi, " << name << ", this is your Arduino speaking!" << endl;
    return 0;
}

