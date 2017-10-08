/*
Copyright 2017 Jacques de Hooge, GEATEC engineering, www.geatec.com

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

  http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

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

