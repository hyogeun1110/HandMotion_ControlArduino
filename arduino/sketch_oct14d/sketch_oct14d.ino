#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

SoftwareSerial mySoftwareSerial(10, 11); // RX, TX
DFRobotDFPlayerMini myDFPlayer;
void printDetail(uint8_t type, int value);

void setup()
{
  mySoftwareSerial.begin(9600);
  Serial.begin(9600);
  
  Serial.println();
  Serial.println(F("DFRobot DFPlayer Mini Demo"));
  Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));
  
  if (!myDFPlayer.begin(mySoftwareSerial)) {  //Use softwareSerial to communicate with mp3.
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while(true);
  }
  Serial.println(F("DFPlayer Mini online."));
  
  myDFPlayer.volume(30);  //Set volume value. From 0 to 30
}
char originSign = '9';

void loop()
{
  while (Serial.available() > 0){ // Serial.available()는 아두이노가 받은 데이터가 있는지 확인하는 명령어.
    char sign = Serial.read();
    if(sign == '6' && sign != originSign){
        myDFPlayer.play(1);  //Play the first mp3
        originSign = '6';
    }
    else if(sign == '7' && sign != originSign){
        myDFPlayer.play(2);  //Play the second mp3
        originSign = '7';
    }
    else if(sign == '8' && sign != originSign){
      myDFPlayer.stop();
      originSign = '8';
    }
    else if(sign == '8' && sign != originSign){
      myDFPlayer.stop();
      originSign = '8';
    }
    else if(sign == '0' && sign != originSign){
      myDFPlayer.stop();
      originSign = '0';
    }
   }
}
