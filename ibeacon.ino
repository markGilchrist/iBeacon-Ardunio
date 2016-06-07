#include <string.h>
#include <SoftwareSerial.h>
using namespace std;

  int bluetoothTx = 2;
  int bluetoothRx = 3;
  SoftwareSerial bluetooth(bluetoothTx, bluetoothRx); 
  int baudrate[8] ={4800,9600,14400,19200,28800,38400,57600,115200};
  int i = 1;

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);
  while(!Serial){}
  
  Serial.write("AT sent");
  call("AT+NAME?");
  call("AT+NAME?");
  call("AT+RENEW");
  call("AT+RESET");
  call("AT");

  call("AT+MARJ0x1234");
  call("AT+MINO0xFA01");
  call("AT+ADVI5");
  call("AT+ADTY3");
  call("AT+NAMEiBeacon2");
  call("AT+IBEA1");
  call("AT+DELO2");
  call("AT+PWRM1");
 // call("AT");
  call("AT+RESET");
  //call("AT+NAME?");
  
}

void loop(){

  while(Serial.available())
  {
    char toSend = (char)Serial.read();
    bluetooth.print(toSend);
    Serial.print(toSend);
  }
  while (bluetooth.available()) {
     Serial.write(bluetooth.read());
   }

}

void call(char *str){
  delay(500);
  bluetooth.write(str);
  delay(500);
  while (bluetooth.available()) {
     Serial.write(bluetooth.read());
   }
  delay(100);
  Serial.println("");
}
