#include <SoftwareSerial.h>


int state=0;
int n;
void setup() {
pinMode(LED_BUILTIN, OUTPUT);
digitalWrite(LED_BUILTIN, LOW);
Serial.begin(9600);

}

void loop() {
 if(Serial.available()>0) {
state=Serial.read();}
if(state == '0'){
  digitalWrite(LED_BUILTIN, LOW);
  Serial.println("LED: OFF");
  state = 0;
  }
else if(state == '1'){
 digitalWrite(LED_BUILTIN, HIGH);
 Serial.println("LED: ON");
 state = 0;
}

  
}
