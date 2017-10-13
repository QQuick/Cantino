#include <cantino.h>
#include <software_servo_modified.h> 

using namespace cantino;

int main () {
    const int pinServo = A0;
    int speed = 1;
    int limits[2] = {30,150};    // set limitations (min/max: 0->180)
    boolean refresh = false;    // toggle refresh on/off

    SoftwareServo servo;  // create servo object to control a servo 

    // attaches the servo on pin to the servo object
    servo.attach (pinServo);  

    // init angle of servo inbetween two limitations
    servo.write ((limits [1] - limits [0]) / 2); 

    while (true) {
        // refresh angle
        int angle = servo.read ();
    
        // change direction when limits
        if (angle >= limits [1] || angle <= limits [0]) {
            speed = -speed;
        }
    
        servo.write (angle + speed);   
    
        // set refresh one time / 2
        refresh = !refresh;
        if (refresh) {
            SoftwareServo::refresh ();
        }
    
        cout << "Angle: " << angle << endl;
    }

    return 0;
} 

