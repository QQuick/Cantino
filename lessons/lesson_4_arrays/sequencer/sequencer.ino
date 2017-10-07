#include <cantino.h>
using namespace cantino;

int main () {
    int const ledPins [] = {4, 5, 6, 7};
    
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

