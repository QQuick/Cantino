#include <cantino.h>
using namespace cantino;

int main () {
    cout << "How old are you? ";
    int age;
    cin >> age;

    if (age < 18) {
        cout << "Sorry, " << age << " years is too young to smoke sigars!" << endl;
    }
    else if (age < 40) {
        cout << "Sorry, " << age << " years is too old for a pacifier!" << endl;
    }
    else if (age < 60) {
        cout << "At " << age << " you may have acquired some wisdom..." << endl;
    }
    else {
        cout << "Programming in C++ is fun at any age!" << endl;
    }
    
    return 0;
}

