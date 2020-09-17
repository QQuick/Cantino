C++ course for the Arduino
==========================

C++ is an excellent language for real time control applications.
It allows for clean program structure and is just as efficient and close to the metal as C.
Discover how concepts like encapsulation and polymorphism allow you to enhance your designs,
while the generated code becomes more compact than ever before.

**Many C++ courses are about writing GUI-oriented software, meant to be run on a PC.
This one's about writing fast, flexible Arduino applications with a tiny memory footprint.**

Cantino comes with a microscopic library that allows the use *main*, *cin* en *cout* in the familiar Arduino Genuino IDE.
To keep Cantino accessible to anyone, an absolute minimum of peripheral hardware is used in the examples.

Cantino doesn't assume any previous programming knowledge and can be used as a first time course in any curriculum.
To complete it successfully you only need two things: curiosity and persistence.
You'll be a C++ programmer after that, so let's get started...

Jacques de Hooge


Remark: To use only the library, just download:

https://github.com/QQuick/Cantino/tree/master/library/cantino.zip

You can install it from the Arduino IDE as follows:

- Go to https://github.com/QQuick/Cantino/blob/master/library/cantino.zip and click "download"
- Install it from the Arduino IDE: Sketch->Include Library->Add .ZIP Library
- Include it from the Arduino IDE: Sketch->Include Library->Include Library->cantino (Under "Contributed libraries")

At he top of your program you need to add:

*#include <cantino.h>*

Your Arduino program can then be structured just like a normal C or C++ pogram,
i.e. with an *int main ()* function.

For C++ you can also use a subset of console streams, as demonstrated in the lessons.
