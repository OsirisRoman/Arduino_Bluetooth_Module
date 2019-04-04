/*************************************************
 * Exercise 3. Remote Controlled LED Using HC-05 *
 *             Bluetooth, Arduino and Mobile     *
 *             Phone App                         *
 * Authors: Sergio Hidalgo, Winter Morejon,      *
 *          Osiris Roman.                        *
 *************************************************/

#include<SoftwareSerial.h> // 'set digital pins for serial communication'
SoftwareSerial wirelessNetworkYT(10, 11); // 'pin 10 as RX, pin 11 as TX'
char DAT = 0;    // 'variable to store received character'
int REDLED = 2; // 'Red LED to digital pin number 2'
int GREENLED = 3; // 'Green LED with digital pin number 3'
bool stateR = false;
bool stateG = false;
void setup(){
wirelessNetworkYT.begin(38400);// ' Serial communication between Arduino and the module at 38400 bps'
pinMode(REDLED,OUTPUT); // 'pin 2 as output'
pinMode(GREENLED,OUTPUT); // 'pin 3 as output'
}
void loop(){
if (wirelessNetworkYT.available()){ // ' if there is information available from module'
  DAT = wirelessNetworkYT.read(); // 'stores in DATO the character received from module'
  if( DAT == '1' ){// ' if the character received is number 1'
    if (!stateR){
      stateR=true;
      digitalWrite(REDLED, HIGH); // turn on red LED
    }else{
      stateR=false;
      digitalWrite(REDLED, LOW); // turn off red LED
    }
  } 
  if ( DAT == '2' ) // ' if the character received is number 2'
    if (!stateG){
      stateG=true;
      digitalWrite(GREENLED, HIGH); // turn on green LED
    }else{
      stateG=false;
      digitalWrite(GREENLED, LOW); // turn off green LED
    }
  }
}
