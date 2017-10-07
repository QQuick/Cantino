#include <cantino.h>
using namespace cantino;

const int dimension = 3;

void addVectors (float *const v1, float *const v2, float *const v3) {
    for (int i = 0; i < dimension; i++) {
        v3 [i] = v1 [i] + v2 [i];
    }
}

void showVector (float *v) {
    cout << '(';
    for (int i = 0; i < dimension; i++) {
        cout << v [i];
        if (i < dimension - 1) {
            cout << ", ";
        }
    }
    cout << endl;
}

int main () {
    float speed1 [dimension];
    float speed2 [dimension];
    float totalSpeed [dimension];

    for (int i = 0; i < dimension; i++) {
        speed1 [i] = i + 1;
        speed2 [i] = 2 * i + 2;
    }
    
    addVectors (speed1, speed2, totalSpeed);
    showVector (speed1);
    showVector (speed2);
    showVector (totalSpeed);
    return 0;
}

