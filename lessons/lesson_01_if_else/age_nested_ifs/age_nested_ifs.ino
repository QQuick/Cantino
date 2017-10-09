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

int main () {
    cout << "How old are you? ";
    int age;
    cin >> age;

    if (age < 18) {
        cout << "Sorry, " << age << " years is a bit young to smoke sigars!" << endl;
        if (age < 6) {
            cout << "Come to think of it, you may not yet be able to read this at all..." << endl;
        }
        else {
            cout << "You probably can read this." << endl;
        }
    }
    else if (age < 40) {
        cout << "Sorry, " << age << " years is way too old for a pacifier!" << endl;
        if (age < 30) {
            cout << "Don't drink too much, braincells are an important asset." << endl;
        }
        else {
            cout << "Life may be busy, don't forget to keep in touch with your friends!" << endl;
        }
    }
    else if (age < 60) {
        cout << "At " << age << " you may have acquired some wisdom..." << endl;
    }
    else {
        cout << "Programming in C++ is fun at any age!" << endl;
    }
    
    return 0;
}

