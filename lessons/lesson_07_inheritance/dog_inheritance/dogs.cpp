#include <cantino.h>
#include "dogs.h"

using namespace cantino;

Dog::Dog (char *name): 
    name (name)
{
}

void Dog::makeSound () {
    cout << "Wraff!" << endl;
}

void Dog::tellName () {
    cout  << "My name is " << name << endl;
}

PoliceDog::PoliceDog (char *name):
    Dog (name)
{
}

void PoliceDog::grabBurglar () {
    cout << "Got you!!" << endl;
}

