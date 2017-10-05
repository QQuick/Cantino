#include <cantino.h>
using namespace cantino;

int main () {
    cout << "How old are you? ";
    int age;
    cin >> age;

    if (age < 18) {
        cout << "Sorry, " << age << " years is too young to smoke sigars!" << endl;
    }
    else {
        cout << "Sorry, " << age << " years is too old for a pacifier!" << endl;
    }
    
    return 0;
}

