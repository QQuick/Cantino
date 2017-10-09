#include <cantino.h>
#include "dogs.h"

using namespace cantino;

int main () {
    Dog dog ("Cujo");   // Or: Dog dog = "Cujo"
    dog.makeSound ();
    dog.tellName ();
    cout << endl;
    
    Dog dog2 ("Fluffy");
    dog2.makeSound ();
    dog2.tellName ();
    cout << endl;

    PoliceDog dog3 ("Hector");
    dog3.makeSound ();
    dog3.tellName (); 
    dog3.grabBurglar ();   
    cout << endl;
}

