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

Vector zeroVector;

int main () {
    Vector speed1 = {1, 2, 3}, speed2 = {2, 4, 6}, totalSpeed;
    totalSpeed = addVectors (speed1, speed2);
    
    showVector (speed1);
    showVector (speed2);
    showVector (totalSpeed);
    
    showVector (zeroVector);
    
    return 0;
}

