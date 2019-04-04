/********************************************
 * Exercise 1: AT Command Mode of HC-05 or  *
 *             HC-06 Bluetooth Module       *
 * Authors: Sergio Hidalgo, Winter Morejon, *
 *          Osiris Roman.                   *
 ********************************************/

#include <SoftwareSerial.h> //set digital pins for serial communication

SoftwareSerial wirelessNetworkYT(10, 11); //pin 10 as RX, pin 11 as TX

void setup(){
  Serial.begin(9600); //serial monitor communication at 9600 bps
  Serial.println("Done"); //write "Done" on the monitor
  wirelessNetworkYT.begin(38400); //Communication at 38400 bps
}

void loop(){
  if(wirelessNetworkYT.available()) //information available from module
  Serial.write(wirelessNetworkYT.read()); //read Bluetooth and send it to Arduino serial monitor

  if(Serial.available()) //information available from the serial monitor
  wirelessNetworkYT.write(Serial.read()); //read serial monitor and send to Bluetooth
}
