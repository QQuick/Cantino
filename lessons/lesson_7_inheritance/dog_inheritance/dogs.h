#pragma once

class Dog {
    public:
        Dog (char *name);
        void makeSound (); 
        void tellName () ;
    private:
        char *name; 
};

class PoliceDog: public Dog {
    public:
        PoliceDog (char *name);
        void grabBurglar () ;
};

