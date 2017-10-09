#include <cantino.h>
#include "vectors.h"

using namespace cantino;

int main () {
    Vector
        v0 (1, 2, 3),
        v1 (10, 20, 30),
        v2;

    v2 = v0 + v1;

    cout << v0 << endl << v1 << endl << v2 << endl;

    v0 [1] = 777;
    cout << v0 [1] << endl << v0 << endl;
    
    return 0;
}

