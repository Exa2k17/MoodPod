#include "arduino_secrets.h"
// Wire Slave Receiver
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Receives data as an I2C/TWI slave device
// Refer to the "Wire Master Writer" example for use with this

// Created 29 March 2006

// This example code is in the public domain.


#include <Wire.h>
#include <MCUFRIEND_kbv.h>
#include "questionHandler.h"
#include "displayHandler.h"
MCUFRIEND_kbv tft;


// initalize transmissionCurrent
int transmissionCurrent = 255;
int transmissionOld = 255;


void setup()
{
  Serial.begin(9600);           // start serial for output
  // preparing tft for transmission
  tft.reset();
  uint16_t identifier = tft.readID();
  Serial.print("ID = 0x");
  Serial.println(identifier, HEX);
  if (identifier == 0xEFEF) identifier = 0x9486;
  tft.begin(identifier);


  Wire.begin(4);                // join i2c bus with address #4
  Wire.onReceive(receiveEvent); // register event

  //setting basic parameters of tft
  tft.setRotation(3);
  tft.fillScreen(BLACK);
  tft.setCursor(10, 30);
  tft.setTextColor(MOODBLUE);
  tft.setTextSize(3);


  delay(3000);
}

//initializing tft apsect ratios
char *msg[] = { "PORTRAIT", "LANDSCAPE", "PORTRAIT_REV", "LANDSCAPE_REV" };
uint8_t aspect;



void loop()
{

  //checking for transmission code
  //transmissionCurrent = 0 -> next Question
  //                      6 -> voted positive
  //                      7 -> voted negative
  //                      8 -> welcome screen

  if (transmissionCurrent != transmissionOld) {
    // if the state has changed, increment the counter
    switch (transmissionCurrent) {
      case 6 :
        displayVotedPositive(tft);
        break;
      case 7 :
        displayVotedNegative(tft);
        break;
        case 8 :
        displayWelcomeScreen(tft);
        break;
      default:
        String question = getQuestion(transmissionCurrent);
        displayQuestion(tft, question);
        break;
    }
  }
  transmissionOld = transmissionCurrent;



  delay(50);
}

//handling incoming transmission
void receiveEvent(int howMany)
{
  byte w;
  if (Wire.available())
  {
    w = Wire.read();
  }

  transmissionCurrent = w;


}
