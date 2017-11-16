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

#pragma once

#include <arduino.h>

namespace cantino {

// ====== Streams

struct SerialStream {
    HardwareSerial *serial;
    char conversionBuffer [16];

    SerialStream (HardwareSerial &serial);
    
    void read (char *const chars, bool breakOnBlank = true);
    SerialStream &operator>> (char *const chars);
    SerialStream &operator>> (bool &aBool);
    SerialStream &operator>> (char &aChar);
    SerialStream &operator>> (unsigned char &aUChar);
    SerialStream &operator>> (int &anInt);
    SerialStream &operator>> (unsigned int &aUInt);
    SerialStream &operator>> (long &aLong);
    SerialStream &operator>> (unsigned long &aULong);
    SerialStream &operator>> (float &aFloat);
    
    SerialStream &operator<< (char const *const chars);
    SerialStream &operator<< (bool aBool);
    SerialStream &operator<< (char aChar);
    SerialStream &operator<< (unsigned char aUChar);
    SerialStream &operator<< (int anInt);
    SerialStream &operator<< (unsigned int aUInt);
    SerialStream &operator<< (long aLong);
    SerialStream &operator<< (unsigned long aULong);
    SerialStream &operator<< (float aFloat);
};

extern char const endl;

#ifndef noCinCout
extern SerialStream cin, cout;
#endif

// ====== Timers

struct Timer {
    static long currentTime;
    long startTime;

    Timer ();
    static void tick ();
    void resetIf (bool condition);
    operator int ();
};

// ====== Oneshots

struct Oneshot {
    byte state;

    Oneshot ();
    void triggerIf (bool condition);
    operator bool ();
};

}

// ====== Main

extern void setup ();
extern void loop ();

#define main __main__
extern int main ();

