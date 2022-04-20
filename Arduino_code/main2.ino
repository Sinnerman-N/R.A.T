#include <SoftwareSerial.h>
#include <Servo.h>

Servo servo01;
Servo servo02;
Servo servo03;
Servo servo04;
Servo servo05;
Servo servo06;

const char clean = "";
const int value = 4;
//const int value1 = 3;
int z = 0;
char Data[value] = "";
//int msData[value1];
int motorSpeed = 5;
int m = 0;

int servo1Pos = 90, servo2Pos = 160, servo3Pos = 90, servo4Pos = 140, servo5Pos = 85, servo6Pos = 80;
const int servo1PosS = 90, servo2PosS = 160, servo3PosS = 90 , servo4PosS = 140, servo5PosS = 85, servo6PosS = 80;

void setup() {

  Serial.begin(9600);
  for (int i = 0; i < value; i++) {
    Data[i] = "";
  }

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

  servo01.attach(5); //waist
  servo02.attach(6); //shoulder
  servo03.attach(7);//elbow
  servo04.attach(8); //wrist roll
  servo05.attach(9); //wrist pitch
  servo06.attach(10); //gripper

  servo01.write(servo1PosS);
  servo02.write(servo2PosS);
  servo03.write(servo3PosS);
  servo04.write(servo4PosS);
  servo05.write(servo5PosS);
  servo06.write(servo6PosS);

}

void loop() {
  if (Serial.available() > 0) {


    for (int i = 0; i < value; i++) {
      Data[i] = Serial.read();
    }
    if (Data[z] == 'g' && Data[z + 1] == 'p') {
      servo6Pos += motorSpeed;

      if (servo6Pos > 179) {
        servo6Pos = 180;
      }
      servo06.write(servo6Pos);
    }
    else if (Data[z] == 'r' && Data[z + 1] == 'p') {
      servo5Pos += motorSpeed;
      if (servo5Pos > 179) {
        servo5Pos = 180;
      }
      servo05.write(servo5Pos);
    }
    else if (Data[z] == 'p' && Data[z + 1] == 'p') {
      servo4Pos += motorSpeed;
      if (servo4Pos > 179) {
        servo4Pos = 180;
      }
      servo04.write(servo4Pos);
    }
    else if (Data[z] == 'e' && Data[z + 1] == 'p') {
      servo3Pos += motorSpeed;
      if (servo3Pos > 179) {
        servo3Pos = 180;
      }
      servo03.write(servo3Pos);
    }
    else if (Data[z] == 's' && Data[z + 1] == 'p') {
      servo2Pos += motorSpeed;
      if (servo2Pos > 179) {
        servo2Pos = 180;
      }
      servo02.write(servo2Pos);
    }
    else if (Data[z] == 'w' && Data[z + 1] == 'p') {
      servo1Pos += motorSpeed;
      if (servo1Pos > 179) {
        servo1Pos = 180;
      }
      servo01.write(servo1Pos);
    }
    //___________________________________________
    else if (Data[z] == 'g' && Data[z + 1] == 'n') {
      servo6Pos -= motorSpeed;
      if (servo6Pos < 0) {
        servo6Pos = 0;
      }
      servo06.write(servo6Pos);
    }
    else if (Data[z] == 'r' && Data[z + 1] == 'n') {
      servo5Pos -= motorSpeed;
      if (servo5Pos < 0) {
        servo5Pos = 0;
      }
      servo05.write(servo5Pos);
    }
    else if (Data[z] == 'p' && Data[z + 1] == 'n') {
      servo4Pos -= motorSpeed;
      if (servo4Pos < 0) {
        servo4Pos = 0;
      }
      servo04.write(servo4Pos);
    }
    else if (Data[z] == 'e' && Data[z + 1] == 'n') {
      servo3Pos -= motorSpeed;
      if (servo3Pos < 0) {
        servo3Pos = 0;
      }
      servo03.write(servo3Pos);
    }
    else if (Data[z] == 's' && Data[z + 1] == 'n') {
      servo2Pos -= motorSpeed;
      if (servo2Pos < 0) {
        servo2Pos = 0;
      }
      servo02.write(servo2Pos);
    }
    else if (Data[z] == 'w' && Data[z + 1] == 'n') {
      servo1Pos -= motorSpeed;
      if (servo1Pos < 0) {
        servo1Pos = 0;
      }
      servo01.write(servo1Pos);
    }
    //_________________________________________
    else if (Data[z] == 'g' && Data[z + 1] == 's') {
      servo06.write(servo6PosS);
    }
    else if (Data[z] == 'r' && Data[z + 1] == 's') {
      servo05.write(servo5PosS);
    }
    else if (Data[z] == 'p' && Data[z + 1] == 's') {
      servo04.write(servo4PosS);
    }
    else if (Data[z] == 'e' && Data[z + 1] == 's') {
      servo03.write(servo3PosS);
    }
    else if (Data[z] == 's' && Data[z + 1] == 's') {
      servo02.write(servo2PosS);
    }
    else if (Data[z] == 'w' && Data[z + 1] == 's') {
      servo01.write(servo1PosS);
    }
    else if (Data[z] == 'r' && Data[z + 1] == 'a') {
      servo01.write(servo1PosS);
      servo02.write(servo2PosS);
      servo03.write(servo3PosS);
      servo04.write(servo4PosS);
      servo05.write(servo5PosS);
      servo06.write(servo6PosS);
    }
    //__________________________________________________
    else if (isDigit(Data[z])) {
      if (isDigit(Data[z]) && isDigit(Data[z + 1])) {
        motorSpeed = int(Data[z]-48) * 10 + int((Data[z + 1]-48));
      }
      else if (isDigit(Data[z]) && isDigit(Data[z + 1]) && isDigit(Data[z + 2])) {
        motorSpeed = 100;
      }
      else{
        motorSpeed = int(Data[z]-48 );
      }
    }


  }


//  for (int i = 0; i < value; i++) {
//    Serial.println(Data[i]);
//  }
  //Serial.println(servo2Pos);
  //Serial.println(motorSpeed);
  for (int i = 0; i < value; i++) {
    Data[i] = clean;

  }

  delay(100);
}
