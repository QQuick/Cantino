.. code-block:: python

    #include "cantino.h"

    using namespace cantino;

    int main () {
        SerialStream console (Serial);
        const int nrOfTimers = 2;
        const int period = 2000;
        Timer timers [nrOfTimers];
        Oneshot oneshots1 [nrOfTimers];
        Oneshot oneshots2 [nrOfTimers];
        int resetTimes [] = {2 * period, 3 * period};
        
        while (true) {
            Timer::tick ();

            for (int timerIndex = 0; timerIndex < nrOfTimers; timerIndex++) {
                timers [timerIndex] .resetIf ((timers [timerIndex] > resetTimes [timerIndex]));
                if (!timers [timerIndex]) {
                    console << (timerIndex ? "+++++ " : "----- ") << endl;
                }
                
                oneshots1 [timerIndex] .triggerIf (timers [timerIndex] > period);
                if (oneshots1 [timerIndex]) {
                    console << (timerIndex ? "+ " : "- ") << endl;                
                }
                
                oneshots2 [timerIndex] .triggerIf (timers [timerIndex] > 2 * period);
                if (oneshots2 [timerIndex]) {
                    console << (timerIndex ? "++ " : "-- ") << endl;                
                }                        
            }
        }
        
        return 0;
    }

