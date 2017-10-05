#include <cantino.h>
using namespace cantino;

struct Vector {
    float x, y, z;
};

Vector addVectors (Vector v1, Vector v2) {
    Vector v3;
    v3.x = v1.x + v2.x;
    v3.y = v1.y + v2.y;
    v3.z = v1.z + v2.z;
    return v3;
}

void showVector (Vector v) {
    cout << '(' << v.x << ", " << v.y << ", " << v.z << ')' << endl;
}

int main () {
    Vector speed1 = {1, 2, 3}, speed2 = {4, 6, 8}, totalSpeed;
    totalSpeed = addVectors (speed1, speed2);
    showVector (speed1);
    showVector (speed2);
    showVector (totalSpeed);
    return 0;
}

