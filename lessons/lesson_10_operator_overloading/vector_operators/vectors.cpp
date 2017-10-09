#include <cantino.h>
#include "vectors.h"

using namespace cantino;

Vector::Vector () {                         // Parameterless constructor creates zero vector
    for (int index = 0; index < size; index++) {
        components [index] = 0;
    }    
}

Vector::Vector (float x, float y, float z) {
    components [0] = x;
    components [1] = y;
    components [2] = z;
}

Vector::Vector (float components [size]) {  // Component constructor
    for (int index = 0; index < size; index++) {
        this->components [index] = components [index];
    }
}

Vector::Vector (Vector &vector):            // Copy constructor calls component constructor
    Vector (vector.components)
{
}
    
Vector Vector::operator+ (Vector &vector) {
    Vector result;
    for (int index = 0; index < size; index++) {
        result.components [index] = components [index] + vector.components [index];
    }
    return result;                  // Will call copy constructor rather than passing local var, since result is a temporary var
}                                   // Using move constructor is more efficient but also more complicated

Vector &Vector::operator= (const Vector &vector) {
    for (int index = 0; index < size; index++) {
        components [index] = vector.components [index];
    }
    return *this;
}


SerialStream &operator<< (SerialStream &serialStream, Vector &vector) {
    serialStream << '(';
    for (int index = 0; index < vector.size; index++) {
        serialStream << vector.components [index];
        if (index < vector.size - 1) {
            serialStream << ", ";
        }
    }
    serialStream << ')';
}


