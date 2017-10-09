#include <cantino.h>

using namespace cantino;

// === Class declarations, may be in dogs.h

class Dog {
    public:
        Dog (char *name);
        void makeSound (); 
        void tellName () ;
    private:
        char *name; 
};

// === Method definitions, may be in dogs.cpp

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

// === Main program, may be in separate file

int main () {
    Dog dog ("Cujo");   // Or: Dog dog = "Cujo"
    dog.makeSound ();
    dog.tellName ();
    cout << endl;
    
    Dog dog2 ("Fluffy");
    dog2.makeSound ();
    dog2.tellName ();
    cout << endl;
}

