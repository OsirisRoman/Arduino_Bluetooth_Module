/*******************************************
 * Exercise 5: Voice Controlled LEDs Using *
 *             HC-05 Bluetooth Arduino and *
 *             Mobile Phone App            *
 * Authors: Sergio Hidalgo, Winter Morejon,*
 *          Osiris Roman.                  *
 *******************************************/

#include<SoftwareSerial.h> // 'set digital pins for serial communication'
SoftwareSerial wirelessNetworkYT(10, 11); // 'pin 10 as RX, pin 11 as TX'
char DAT = 0;    // 'variable to store received character'
int redLed = 3; // 'Red LED to digital pin number 3'
int whiteLed = 2; // 'White LED with digital pin number 2'
int blueLed = 4; // 'Blue LED with digital pin number 4'
int yellowLed = 5; // 'Yellow LED with digital pin number 5'
int greenLed = 6; // 'Green LED with digital pin number 6'
bool stateW = false;
bool stateR = false;
bool stateB = false;
bool stateY = false;
bool stateG = false;

void setup(){
wirelessNetworkYT.begin(38400);// ' Serial communication between Arduino and the module at 38400 bps'
Serial.begin(9600);
Serial.println("LISTO");
pinMode(redLed,OUTPUT); // 'pin 3 as output'
pinMode(whiteLed,OUTPUT); // 'pin 2 as output'
pinMode(blueLed,OUTPUT); // 'pin 4 as output'
pinMode(yellowLed,OUTPUT); // 'pin 5 as output'
pinMode(greenLed,OUTPUT); // 'pin 6 as output'
digitalWrite(whiteLed, LOW); // turn off white LED
digitalWrite(redLed, LOW); // turn off red LED
digitalWrite(blueLed, LOW); // turn off blue LED
digitalWrite(yellowLed, LOW); // turn off yellow LED
digitalWrite(greenLed, LOW); // turn off green LED
}
void loop(){
  if (wirelessNetworkYT.available()){ // ' if there is information available from module'
    DAT = wirelessNetworkYT.read(); // 'stores in DAT the character received from module'
    Serial.println(DAT);
    if( DAT == '1' ){// ' if the character received is number 1'
      DAT=0;
      if (!stateW){
        stateW=true;
        digitalWrite(whiteLed, HIGH); // turn on white LED
      }else{
        stateW=false;
        digitalWrite(whiteLed, LOW); // turn off white LED
      }
    }
    if( DAT == '2' ){// ' if the character received is number 2'
      DAT=0;
      if (!stateR){
        stateR=true;
        digitalWrite(redLed, HIGH); // turn on red LED
      }else{
        stateR=false;
        digitalWrite(redLed, LOW); // turn off red LED
      }
    }
    if( DAT == '3' ){// ' if the character received is number 3'
      DAT=0;
      if (!stateB){
        stateB=true;
        digitalWrite(blueLed, HIGH); // turn on blue LED
      }else{
        stateB=false;
        digitalWrite(blueLed, LOW); // turn off blue LED
      }
    }
    if( DAT == '4' ){// ' if the character received is number 4'
      DAT=0;
      if (!stateY){
        stateY=true;
        digitalWrite(yellowLed, HIGH); // turn on yellow LED
      }else{
        stateY=false;
        digitalWrite(yellowLed, LOW); // turn off yellow LED
      }
    }
    if( DAT == '5' ){// ' if the character received is number 5'
      DAT=0;
      if (!stateG){
        stateG=true;
        digitalWrite(greenLed, HIGH); // turn on green LED
      }else{
        stateG=false;
        digitalWrite(greenLed, LOW); // turn off green LED
      }
    }
  } 
}
