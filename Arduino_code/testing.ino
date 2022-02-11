#include <SoftwareSerial.h>
const char clean = "";
const int value = 4;
char Data[value] = "";
void setup() {
pinMode(LED_BUILTIN, OUTPUT);
digitalWrite(LED_BUILTIN, LOW);
Serial.begin(9600);
for(int i=0;i<value;i++){
  Data[i]="";
  }
}
void loop() {
if(Serial.available()>0){
 for(int i=0;i<value;i++){
  Data[i]=Serial.read();
  }
  }
int z=0;
while(z<1){
  if(Data[z]=='g'){
    if(Data[z+1]=='p'){digitalWrite(LED_BUILTIN, HIGH);}
    else if(Data[z+1]=='n'){digitalWrite(LED_BUILTIN, LOW);}
    }
    z++;
  }
 for(int i=0;i<value;i++){
  Serial.println(Data[i]);
  }
 for(int i=0;i<value;i++){
  Data[i]=clean;
  }
delay(1000);
}
