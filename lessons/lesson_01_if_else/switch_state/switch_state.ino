/*
This program features 2 statemachines.
One has 2 states, the other 3.
They each run at their own pace.

Note that state machines don't have to cycle through a fixed sequence of states.
They can go through states in arbitrary, dynamically determined order.
Also state transitions do not need to be triggered by elapsed time intervals.
The may also be caused by external triggers, like sensor signals changing.
*/

#include <cantino.h>

using namespace cantino;

int main () {

    // ====== Yellow blinking traffic light
    
    int const yellowBlinkLed = 9;
    int const buzzer = 13;
    
    pinMode (yellowBlinkLed, OUTPUT);
    pinMode (buzzer, OUTPUT);
    
    int const blinkTime = 281;
    
    int const offBlinkState = 0;
    int const onBlinkState = 1;
    
    int oldBlinkState = onBlinkState;
    int blinkState = offBlinkState;
    
    // ====== Green, yellow and red phase traffic light
    
    int const greenPhaseLed = 10;
    int const yellowPhaseLed = 11;
    int const redPhaseLed = 12;
    
    pinMode (greenPhaseLed, OUTPUT);
    pinMode (yellowPhaseLed, OUTPUT);
    pinMode (redPhaseLed, OUTPUT);
    
    int const phaseTime = 1021;
    
    int const greenPhaseState = 0;
    int const yellowPhaseState = 1;
    int const redPhaseState = 2;
    
    int oldPhaseState = redPhaseState;
    int phaseState = greenPhaseState;
    
    // ====== Initialize start time
    
    long startBlinkTime = millis ();
    long startPhaseTime = startBlinkTime;
        
    // ====== Main control loop
    
    while (true) {
        // ====== Read out clock only once in the main loop, so there's only one unique time
    
        long currentTime = millis ();
        
        // ====== Separate state machine for the LED, has 2 states
        
        switch (blinkState) {
            case offBlinkState:
                if (blinkState != oldBlinkState) {
                    // This part only done once after state transition
                    tone (buzzer, 1000);
                    oldBlinkState = blinkState;
                }
                
                // Transition condition continuously monitored
                if (currentTime - startBlinkTime > blinkTime) {
                    noTone (buzzer);
                    blinkState = onBlinkState;
                }
                
                break;
                
            case onBlinkState:
                if (blinkState != oldBlinkState) {
                    // This part only done once after state transition
                    digitalWrite (yellowBlinkLed, true);
                    oldBlinkState = blinkState;
                }
                
                // Transition condition continuously monitored
                if (currentTime - startBlinkTime > 2 * blinkTime) {
                    digitalWrite (yellowBlinkLed, false);
                    blinkState = offBlinkState;
                    startBlinkTime = currentTime;             
                }
                
                break;
        }
    
        // ====== Separate state machine for the phase, has 3 states
        
        switch (phaseState) {
            case greenPhaseState:
                if (phaseState != oldPhaseState) {
                    // This part only done once after state transition   
                    digitalWrite (greenPhaseLed, true);
                    oldPhaseState = phaseState;
                }
                
                // Transition condition continuously monitored
                if (currentTime - startPhaseTime > 2 * phaseTime) {
                    digitalWrite (greenPhaseLed, false);
                    phaseState = yellowPhaseState;
                }
                
                break;
                
            case yellowPhaseState:
                if (phaseState != oldPhaseState) {
                    // This part only done once after state transition   
                    digitalWrite (yellowPhaseLed, true);
                    oldPhaseState = phaseState;
                }
                
                // Transition condition continuously monitored
                if (currentTime - startPhaseTime > 3 * phaseTime) {
                    digitalWrite (yellowPhaseLed, false);
                    phaseState = redPhaseState;
                }
                
                break;
                
            case redPhaseState:
                if (phaseState != oldPhaseState) {
                    // This part only done once after state transition   
                    digitalWrite (redPhaseLed, true);
                    oldPhaseState = phaseState;
                }
                
                // Transition condition continuously monitored
                if (currentTime - startPhaseTime > 5 * phaseTime) {
                    digitalWrite (redPhaseLed, false);
                    phaseState = greenPhaseState;
                    startPhaseTime = currentTime;
                }
                
                break;
        }

        cout << blinkState << ' ' << phaseState << endl;

        // ====== Small delay IN ONE PLACE ONLY to grant e.g. serial I/O some processor time
    
        delay (50);
    }
    return 0;
}

