#include <cantino.h>
#include <Servo.h>

using namespace cantino;

int main () {
    int const servoPin = 8;
     
    Servo servo;  
     
    int servoAngle = 0;   // servo position in degrees
    
    Serial.begin(9600);  
    servo.attach (servoPin);

 
    while (true) {
        //control the servo's direction and the position of the motor
        servo.write (45);      // Turn SG90 servo Left to 45 degrees
        delay(1000);          // Wait 1 second
        servo.write(90);      // Turn SG90 servo back to 90 degrees (center position)
        delay(1000);          // Wait 1 second
        servo.write(135);     // Turn SG90 servo Right to 135 degrees
        delay(1000);          // Wait 1 second
        servo.write(90);      // Turn SG90 servo back to 90 degrees (center position)
        delay(1000);
        //end control the servo's direction and the position of the motor


       //control the servo's speed  
       //if you change the delay value (from example change 50 to 10), the speed of the servo changes
        for (servoAngle = 0; servoAngle < 180; servoAngle++) { //move the micro servo from 0 degrees to 180 degrees
            servo.write (servoAngle);              
            delay(50);                  
        }
    
        for (servoAngle = 180; servoAngle > 0; servoAngle--) { //now move back the micro servo from 0 degrees to 180 degrees                                
            servo.write (servoAngle);          
            delay(10);      
        }
        //end control the servo's speed

        for (int i = 0; i < 5; i++) {
            cout<< "Give angle: ";
            cin >> servoAngle;
            servo.write (servoAngle);
        }
    }
    return 0;
}
