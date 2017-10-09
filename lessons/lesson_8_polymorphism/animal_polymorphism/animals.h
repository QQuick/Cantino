class Animal {
    public:
        virtual void speak () = 0;
};

class Dog: public Animal {
    public:
        void speak ();
};

class Cat: public Animal {
    public:
        void speak ();
};

