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
    int const ledPins [] = {9, 10, 11, 12};
    
    int const nrOfTracks = sizeof (ledPins) / sizeof (int);
    int const nrOfSteps = 8;
    
    bool sequenceTable [nrOfTracks][nrOfSteps] = {};

    for (int trackIndex = 0; trackIndex < nrOfTracks; trackIndex++) {
        pinMode (ledPins [trackIndex], OUTPUT);
    }

    cout << "Program your sequencer" << endl;
    
    for (int trackIndex = 0; trackIndex < nrOfTracks; trackIndex++) {
        cout << "Enter sequence of " << nrOfSteps << " zeros or ones for track " << trackIndex << ": ";
        char values [nrOfSteps + 1];
        cin >> values;
        for (int stepIndex = 0; stepIndex < nrOfSteps; stepIndex++) {
            sequenceTable [trackIndex][stepIndex] = (values [stepIndex] == '1');
        }
    };

    cout << "Contents of sequence table:" << endl;

    for (int trackIndex = 0; trackIndex < nrOfTracks; trackIndex++) {
        for (int stepIndex = 0; stepIndex < nrOfSteps; stepIndex++) {
            cout << sequenceTable [trackIndex][stepIndex] << ' '; 
        }
        cout << endl;
    }
    
    cout << "Sequencing started" << endl;

    while (true) {
        for (int stepIndex = 0; stepIndex < nrOfSteps; stepIndex++) {
            for (int trackIndex = 0; trackIndex < nrOfTracks; trackIndex++) {
                digitalWrite (ledPins [trackIndex], sequenceTable [trackIndex][stepIndex]);
            }
            delay (1000);
        }        
    }
    
    cout << "Program terminated" << endl;
    
    return 0;
}

