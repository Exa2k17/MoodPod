bool buttonCurrentN;
bool buttonCurrentP;

bool buttonOldN;
bool buttonOldP;

void handleButtons(int buttonPinN, int buttonPinP) {
  // compare the buttonState to its previous state
  if (vote == 0) {
    buttonCurrentN = digitalRead(buttonPinN);
    buttonCurrentP = digitalRead(buttonPinP);
    if (buttonCurrentN != buttonOldN) {
      // if the state has changed, increment the counter
      if (buttonCurrentN == LOW) {
        // if the current state is LOW then the button went from off to on:
        byte b = 7;
        Wire.beginTransmission(4); // transmit to device #4
        Wire.write(b);
        Wire.endTransmission();
        vote = 2;
        incrementCategoryVotes();
        
        //incrementing negative votes
        votedN = votedN+1;
        
        // calculating stresslevel
        float total = votedN + votedP;
        stressLevel = votedN / total * 100;
      }
    }
    buttonOldN = buttonCurrentN;

    if (buttonCurrentP != buttonOldP) {
      // if the state has changed, increment the counter
      if (buttonCurrentP == LOW) {
        // if the current state is LOW then the button went from off to on:
        byte b = 6;
        Wire.beginTransmission(4); // transmit to device #4
        Wire.write(b);
        Wire.endTransmission();
        vote = 1;
        incrementCategoryVotes();
        //incrementing positive votes
        votedP = votedP+1;
        
        // calculating stresslevel
        float total = votedN + votedP;
        stressLevel = votedN / total * 100;
      }
    }
    buttonOldP = buttonCurrentP;

  }


}