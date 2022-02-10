#include <SoftwareSerial.h>
const char clean = "";
const int value = 4;
const int buffer = 64;
char Data[value] = "";
int vValue[buffer];
void setup() {
pinMode(LED_BUILTIN, OUTPUT);
digitalWrite(LED_BUILTIN, LOW);
Serial.begin(9600);
for(int i=0;i<value;i++){
  Data[i]="";
  }
}
char data = "";
void loop() {
if(Serial.available()>0){
 for(int i=0;i<value;i++){
  Data[i]=Serial.read();
  }
  }

for(int i=0;i<value;i++){
 while(isAlpha(Data[i]){
  
  }
  }
for(int i=0;i<value;i++){
  Serial.println(Data[i]);
  }
 for(int i=0;i<value;i++){
  Data[i]=clean;
  }
delay(1000);

}
