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

#include <arduino.h>

#include "cantino.h"

namespace cantino {

// ====== Streams

SerialStream::SerialStream (HardwareSerial &serial):
    serial (&serial)
{}

SerialStream &SerialStream::operator>> (char *const chars) {
    for (int index = 0; ; index++) {
        while (!serial->available ()) {  // Wait for input
        }
        chars [index] = serial->read ();
        serial->print (chars [index]);
        if (chars [index] == '\n') {
            chars [index] = (char) 0;
            break;
        }
        while (serial->available ()) {   // Clear Serial's internal buffer
        }
    }
    return *this;
}

SerialStream &SerialStream::operator>> (bool &aBool) {
     (*this) >> conversionBuffer;
     aBool = strcmp (conversionBuffer, "true") == 0;
     return *this;
}

SerialStream &SerialStream::operator>> (char &aChar) {   
     (*this) >> conversionBuffer;
     aChar = conversionBuffer [0];
     return *this;
}

SerialStream &SerialStream::operator>> (unsigned char &anUChar) {
    return (*this) >> int (anUChar);
}

SerialStream &SerialStream::operator>> (int &anInt) {
     (*this) >> conversionBuffer;
     anInt = atoi (conversionBuffer);
     return *this;    
}

SerialStream &SerialStream::operator>> (unsigned int &anUInt) {
    return (*this) >> long (anUInt);
}

SerialStream &SerialStream::operator>> (long &aLong) {
     (*this) >> conversionBuffer;
     aLong = atol (conversionBuffer);
     return *this;    
}

SerialStream &SerialStream::operator>> (unsigned long &anULong) {
     return (*this) >> long (anULong);    
}

SerialStream &SerialStream::operator>> (float &aFloat) {
     (*this) >> conversionBuffer;
     aFloat = atof (conversionBuffer);
     return *this;    
}
SerialStream &SerialStream::operator<< (char const *const chars) {
    serial->write (chars);
    serial->flush ();
    return *this;
}

SerialStream &SerialStream::operator<< (bool aBool) {
    return (*this) << (aBool ? "true" : "false");
}

SerialStream &SerialStream::operator<< (char aChar) {
    conversionBuffer [0] = aChar;
    conversionBuffer [1] = 0;
    return (*this) << conversionBuffer;
}

SerialStream &SerialStream::operator<< (unsigned char anUChar) {
    return (*this) << int (anUChar);
}

SerialStream &SerialStream::operator<< (int anInt) {
    itoa (anInt, conversionBuffer, 10);
    return (*this) << conversionBuffer;
}

SerialStream &SerialStream::operator<< (unsigned int anUInt) {
    return (*this) << long (anUInt);
}

SerialStream &SerialStream::operator<< (long aLong) {
    ltoa (aLong, conversionBuffer, 10);
    return (*this) << conversionBuffer;
}

SerialStream &SerialStream::operator<< (unsigned long anULong) {
    return (*this) << long (anULong);
}

SerialStream &SerialStream::operator<< (float aFloat) {
    dtostrf (aFloat, 0, 10, conversionBuffer);
    return (*this) << conversionBuffer;
}

char const endl = '\n';

#ifndef noCinCout
SerialStream cin (Serial), cout (Serial);
#endif

// ====== Timers

static long Timer::currentTime = 0;

Timer::Timer () {
    resetIf (true);
}

static void Timer::tick () {
    currentTime = millis ();
}

void Timer::resetIf (bool condition) {
    if (condition) {
        startTime = currentTime;
    }
}

Timer::operator int () {
    return currentTime - startTime;
}

// ====== Oneshots

Oneshot::Oneshot () {
    state = 0;
}

void Oneshot::triggerIf (bool condition) {
    state <<= 1;
    if (condition) {
        state |= 1;
    }
}

Oneshot::operator bool () {
    return (state & 3) == 1;
}

}

// ====== Main

void setup () {
    Serial.begin (9600);
    __main__ ();
}

void loop () {
    exit (0);
}


