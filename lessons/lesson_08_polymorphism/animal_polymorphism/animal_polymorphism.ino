#include <cantino.h>
#include "animals.h"

using namespace cantino;

int main () {
    const int nrOfAnimals = 9;
    Animal *animals [nrOfAnimals];

    for (int index = 0; index < nrOfAnimals; index++) {
        if (index % 3 == 0) {
            animals [index] = new Dog ();
        }
        else {
            animals [index] = new Cat ();
        }
    }

    for (int index = 0; index < nrOfAnimals; index++) {
        animals [index] ->speak ();
    }

    for (int index = 0; index < nrOfAnimals; index++) {
        delete animals [index];
    }    
}

