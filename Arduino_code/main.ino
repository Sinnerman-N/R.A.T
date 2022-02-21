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
int motorSpeed = 10;

int servo1Pos = 90, servo2Pos = 0, servo3Pos = 35, servo4Pos = 140, servo5Pos = 85, servo6Pos = 80;
const int servo1PosS = 50, servo2PosS = 90, servo3PosS = 60, servo4PosS = 60, servo5PosS = 0, servo6PosS = 80;

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
      servo06.write(servo6Pos + motorSpeed);
    }
    else if (Data[z] == 'r' && Data[z + 1] == 'p') {
      servo05.write(servo5Pos + motorSpeed);
    }
    else if (Data[z] == 'p' && Data[z + 1] == 'p') {
      servo04.write(servo4Pos + motorSpeed);
    }
    else if (Data[z] == 'e' && Data[z + 1] == 'p') {
      servo03.write(servo3Pos + motorSpeed);
    }
    else if (Data[z] == 's' && Data[z + 1] == 'p') {
      servo02.write(servo2Pos + motorSpeed);
    }
    else if (Data[z] == 'w' && Data[z + 1] == 'p') {
      servo01.write(servo1Pos + motorSpeed);
    }
    //___________________________________________
    else if (Data[z] == 'g' && Data[z + 1] == 'n') {
      servo06.write(servo6Pos - motorSpeed);
    }
    else if (Data[z] == 'r' && Data[z + 1] == 'n') {
      servo05.write(servo5Pos - motorSpeed);
    }
    else if (Data[z] == 'p' && Data[z + 1] == 'n') {
      servo04.write(servo4Pos - motorSpeed);
    }
    else if (Data[z] == 'e' && Data[z + 1] == 'n') {
      servo03.write(servo3Pos - motorSpeed);
    }
    else if (Data[z] == 's' && Data[z + 1] == 'n') {
      servo02.write(servo2Pos - motorSpeed);
    }
    else if (Data[z] == 'w' && Data[z + 1] == 'n') {
      servo01.write(servo1Pos - motorSpeed);
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
    else if (isAscii(Data[z])) {

      
        }
    }
  

  //  for (int i = 0; i < value; i++) {
  //    Serial.println(Data[i]);
  //  }
Serial.println(motorSpeed);
  for (int i = 0; i < value; i++) {
    Data[i] = clean;
  }
  delay(200);
}
