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

#include <cantino.h>

using namespace cantino;

class Device {
    friend SerialStream &operator<< (SerialStream &serialStream, Device &device);
    
    public:
        virtual bool read () = 0;        
        operator bool ();

    protected:
        Device (char const* const label, int pinIndex);

        char const *const label;
        int pinIndex;
};

class Sensor: public Device {
    public:
        Sensor (char const *const label, int pinIndex);
};

class Actuator: public Device {
    public:
        Actuator (char const *const label, int pinIndex);
        virtual bool read ();
        void operator () (bool state);

    protected:
        virtual void write (bool state);
        
        bool state;
};

SerialStream &operator<< (SerialStream &serialStream, Device &device);

