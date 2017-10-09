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
    cout << "Type 0 to quit!" << endl;
        for (int tableNr = 1; tableNr <= 10; tableNr++) {
            for (int lineNr = 1; lineNr <= 10; lineNr++) {
                int answer;
                do {
                    cout << lineNr << " x " << tableNr << " = ";
                    cin >> answer;
                    if (answer == 0) {
                        cout << "Program quit by user" << endl;
                        return 0;
                    }
                } while (answer != lineNr * tableNr);
            }
            cout << endl;
        }
    cout << "Program terminated" << endl;
    return 0;
}

