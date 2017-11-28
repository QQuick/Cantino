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

#if defined (_VARIANT_ARDUINO_DUE_X_)
#include <avr/dtostrf.h>
#endif

#include "cantino.h"

namespace cantino {

// ====== Streams

SerialStream::SerialStream (HardwareSerial &serial):
    serial (&serial),
    echo (true)
{}

void SerialStream::setecho (bool echo) {
    this->echo = echo;
}

void SerialStream::read (char *const chars, bool breakOnBlank) {
    for (int index = 0; ; index++) {
        while (!serial->available ()) {     // Wait for input
        }
        chars [index] = serial->read ();    // Read next char
        if (echo) {                         // If echoing is on
            serial->print (chars [index]);  // Give back the char via the serial port
        }
        if (chars [index] == '\n' or chars [index] == '\v' or (breakOnBlank and chars [index] == ' ')) {
            chars [index] = (char) 0;
            break;
        }
        while (serial->available ()) {   // Clear Serial's internal buffer
        }
    }
}

SerialStream &SerialStream::operator>> (char *const chars) {
    read (chars);
    return *this;
}

SerialStream &SerialStream::operator>> (bool &aBool) {
     read (conversionBuffer);
     aBool = strcmp (conversionBuffer, "true") == 0;
     return *this;
}

SerialStream &SerialStream::operator>> (char &aChar) {   
     read (conversionBuffer);
     aChar = conversionBuffer [0];
     return *this;
}

SerialStream &SerialStream::operator>> (unsigned char &aUChar) {
    read (conversionBuffer);
    aUChar = atoi (conversionBuffer);
    return *this;
}

SerialStream &SerialStream::operator>> (int &anInt) {
     read (conversionBuffer);
     anInt = atoi (conversionBuffer);
     return *this;    
}

SerialStream &SerialStream::operator>> (unsigned int &aUInt) {
    read (conversionBuffer);
    aUInt = atol (conversionBuffer);
    return *this;
}

SerialStream &SerialStream::operator>> (long &aLong) {
     read (conversionBuffer);
     aLong = atol (conversionBuffer);
     return *this;    
}

SerialStream &SerialStream::operator>> (unsigned long &aULong) {
     read (conversionBuffer);
     aULong = atol (conversionBuffer);  // Will overflow
     return *this;
}

SerialStream &SerialStream::operator>> (float &aFloat) {
     read (conversionBuffer);
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

SerialStream &SerialStream::operator<< (unsigned char aUChar) {
    return (*this) << int (aUChar);
}

SerialStream &SerialStream::operator<< (int anInt) {
    itoa (anInt, conversionBuffer, 10);
    return (*this) << conversionBuffer;
}

SerialStream &SerialStream::operator<< (unsigned int aUInt) {
    return (*this) << long (aUInt);
}

SerialStream &SerialStream::operator<< (long aLong) {
    ltoa (aLong, conversionBuffer, 10);
    return (*this) << conversionBuffer;
}

SerialStream &SerialStream::operator<< (unsigned long aULong) {
    return (*this) << long (aULong);
}

SerialStream &SerialStream::operator<< (float aFloat) {
    dtostrf (aFloat, 0, 10, conversionBuffer);
    return (*this) << conversionBuffer;
}

void getline (SerialStream &serialStream, char *const chars) {
    serialStream.read (chars, false);
}

char const endl = '\n';
char const flush = '\v';

#ifndef noCinCout
SerialStream cin (Serial), cout (Serial);
#endif

// ====== Timers

long Timer::currentTime = 0;

Timer::Timer () {
    resetIf (true);
}

void Timer::tick () {
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


