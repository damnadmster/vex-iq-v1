// поставить библиотеку DFRobotDFPlayerMini
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"
#include "Arduino.h"

SoftwareSerial mySoftwareSerial(10, 11); // RX, TX
DFRobotDFPlayerMini myDFPlayer;


void setup () {
  mySoftwareSerial.begin(9600);
  myDFPlayer.begin(mySoftwareSerial);

  //set volume
  myDFPlayer.volume(30);

  //play first list
  myDFPlayer.play(2);

}

void loop () {
}
