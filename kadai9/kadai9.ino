#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  myservo.attach(22,500,2400);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  // put your main code here, to run repeatedly:
  int incomingByte;

  if(Serial.available()>0){
    incomingByte = Serial.read();
    switch(incomingByte){
      case '0':
        myservo.write(0);
        Serial.write(incomingByte);
        delay(1000);
        break;
      case '1':
        myservo.write(45);
        Serial.write(incomingByte);
        delay(1000);
        break;
      case '2':
        myservo.write(90);
        Serial.write(incomingByte);
        delay(1000);
        break;               
    }
  }
  delay(15);
}
