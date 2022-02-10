#include <SoftwareSerial.h>
#include <Servo.h>
Servo servo01;
Servo servo02;
Servo servo03;
Servo servo04;
Servo servo05;
Servo servo06;
String dataIn = "";
int state=0;
int servo1Pos, servo2Pos, servo3Pos, servo4Pos, servo5Pos, servo6Pos;
int servo1PPos, servo2PPos, servo3PPos, servo4PPos, servo5PPos, servo6PPos;
void setup(){
    pinMode(LED_BUILTIN, OUTPUT);
digitalWrite(LED_BUILTIN, LOW);
  servo01.attach(5);
  servo02.attach(6);
  servo03.attach(7);
  servo04.attach(8);
  servo05.attach(9);
  servo06.attach(10);
  Serial.begin(9600);
   // Robot arm initial position
  servo1PPos = 90;
  servo01.write(servo1PPos);
  servo2PPos = 150;
  servo02.write(servo2PPos);
  servo3PPos = 35;
  servo03.write(servo3PPos);
  servo4PPos = 140;
  servo04.write(servo4PPos);
  servo5PPos = 85;
  servo05.write(servo5PPos);
  servo6PPos = 80;
  servo06.write(servo6PPos);
  }
void loop(){
  //test if bluetooth is working 
    if(Serial.available()>0) {
state=Serial.read();
if(state == '0'){
  digitalWrite(LED_BUILTIN, LOW);
  Serial.println("LED: OFF");
  state = 0;
  }
else if(state == '1'){
 digitalWrite(LED_BUILTIN, HIGH);
 Serial.println("LED: ON");
 state = 0;}}

 if (Serial.available() > 0){
  dataIn = Serial.readString();
 if (dataIn == 'a'){
  
  servo1PPos = 80;
  servo01.write(servo1PPos);
  servo2PPos = 140;
  servo02.write(servo2PPos);
  servo3PPos = 25;
  servo03.write(servo3PPos);
  servo4PPos = 130;
  servo04.write(servo4PPos);
  servo5PPos = 75;
  servo05.write(servo5PPos);
  servo6PPos = 70;
  servo06.write(servo6PPos);
  
  }
 }
  
  }

    
    
    
   
