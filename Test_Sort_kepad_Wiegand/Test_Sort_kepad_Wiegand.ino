// Code by chad elish
// www.hackpgh.org www.nationofmakers.us
// Thank you to Steve and Geno for the help.
// Also thank you to MonkeyBoard.

#include <Wiegand.h>
String buttontotal; // Total values of buttons pressed
WIEGAND wg;

void setup() {
  Serial.begin(9600);

  // default Wiegand Pin 2 and Pin 3 see image on README.md
  // for non UNO board, use wg.begin(pinD0, pinD1) where pinD0 and pinD1
  // are the pins connected to D0 and D1 of wiegand reader respectively.
  wg.begin();
}

void loop()
{
  char typew; // Defines if a button was pressed or a card was scanned
  int button = 100; // Last Button Pressed... set to a high number so last else if statment doesn't run
  if (wg.available())
  {
    // Serial.print(wg.getWiegandType());
    typew = (wg.getWiegandType());
  }
  if (typew == 26) // Type 26 is a card scan
  {
    Serial.print("Card = ");
    Serial.println(wg.getCode());
    buttontotal = ""; // clears out keypad presses
  }
  else if (typew == 4) // Type 4 is a button press
  {
    button = wg.getCode();
  }
  if (button == 27)
  {
    buttontotal = ""; // clears out keypad presses
    Serial.println("Keypad Cleared");
  }
  else if (button == 13) // Type 4 is ENT
  {
    Serial.print("Final Code = ");
    Serial.println(buttontotal);
    buttontotal = ""; // clears out keypad presses
    Serial.println("Keypad Cleared");
  }
  else if (button <= 9) // Check
  {
  Serial.print("Number = ");
  Serial.println(button);
  buttontotal += button;
  Serial.print("Button Total = ");
  Serial.println(buttontotal);
  }
}