#include <MCUFRIEND_kbv.h>

// Assign human-readable names to some common 16-bit color values:
#define	BLACK   0x0000
#define	BLUE    0x001F
#define	RED     0xF800
#define	GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF
#define MOODBLUE 0x077F
#define MOODPINK 0xD81F

//declaring method for displaying a new question
void displayQuestion(MCUFRIEND_kbv tft, String question) {


  tft.fillScreen(BLACK);
  tft.setCursor(10, 30);
  tft.setTextColor(MOODBLUE);
  tft.println(question);

  Serial.println(question);
}

//declaring methods for displaying the thanks for voting screens
void displayVotedPositive(MCUFRIEND_kbv tft) {

  tft.fillScreen(MOODBLUE);
  tft.setCursor(10, 30);
  tft.setTextColor(MOODPINK);
            //"................  ...............  ...............  ...............  ..............."
  tft.println("Thank you for     voting!");
  delay(5000);
  tft.fillScreen(BLACK);
  tft.setCursor(10, 50);
  tft.setTextColor(WHITE);
            //"................  ...............  ...............  ...............  ..............."
  tft.println("your AD could be  HERE ;)");
}

void displayVotedNegative(MCUFRIEND_kbv tft) {

  tft.fillScreen(MOODPINK);
  tft.setCursor(10, 30);
  tft.setTextColor(MOODBLUE);
            //"................  ...............  ...............  ...............  ..............."
  tft.println("Thank you for     voting!");
  delay(5000);
  tft.fillScreen(BLACK);
  tft.setCursor(10, 50);
  tft.setTextColor(WHITE);
            //"................  ...............  ...............  ...............  ..............."
  tft.println("SOS! They're      making me write  loading screen   quotes again     -an unnamed dev");

}

//declaring method for displaying welcome screen
void displayWelcomeScreen(MCUFRIEND_kbv tft) {


  tft.fillScreen(MOODBLUE);
  tft.setCursor(10, 30);
  tft.setTextColor(MOODPINK);
  tft.setTextSize(5);
  tft.println("Hello SEDI");
  tft.setCursor(10, 70);
  tft.setTextColor(WHITE);
  tft.setTextSize(4);
  tft.println("I am MoodPod");
  tft.setTextSize(3);
  tft.setCursor(10, 110);
            //"................  ...............  ...............  ...............  ..............."
  tft.println("Welcome to the    FINAL Show...    ... lean back    and enyoy! ;)");
}