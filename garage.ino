#include <Servo.h>
int IRSensor = 2;
int servo = 9;
Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
int x=0;
void setup() {
  pinMode(IRSensor, INPUT); // sensor pin Input
  myservo.attach(servo);  // attaches the servo on pin 9 to the servo object
}
void loop() {
 if(x==0)
 {
  myservo.write(0);
  x++;
 }
  int statusSensor = digitalRead(IRSensor);
  if (statusSensor == 1)
  {
    if (pos != 0)
    {
      for (pos = 95; pos >= 0; pos -= 1) { // goes from 0 degrees to 180 degrees
        //in steps of 1 degree
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(15);                      // waits 15ms for the servo to reach the position
      }
      pos=0;
    }
  }
  else
  {
    //delay(2000);
    if (pos == 0)
    {
      for (; pos <= 95; pos += 1) { // goes from 180 degrees to 0 degrees
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15ms for the servo to reach the position
      }
    
    delay(3000);
    }
  }
}
