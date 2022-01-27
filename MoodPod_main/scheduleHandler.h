#include "questionHandler.h"


// declaring variables for scheduler
bool intervalOld;
bool intervalCurrent;

//test for time to gather next question
void handleSchedule() {
  intervalCurrent = scheduler.isActive();
  if (intervalCurrent != intervalOld) {
    if (intervalCurrent) {
      //new timeinterval starts
      if (vote != 0) {
        
        //Ping slave mega to display next question
      Wire.beginTransmission(4); // transmit to device #4
      category = getQuestionCategory();
      Wire.write(category);
      Wire.endTransmission();
        vote = 0;
        
      }

    } else {


    }
  }
  intervalOld = intervalCurrent;
  
  
}

