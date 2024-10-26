#include "pitches.h"

/* 
  Play Song with Piezo Speaker
  Plays "Twinkle, Twinkle, Little Star".
*/

// notes of the melody followed by the duration.
// a quarter note is 250 ms, eighth note is 125 ms, etc.
int melody[] = {
  NOTE_C4, NOTE_C4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_G4,
  NOTE_F4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_D4, NOTE_D4, NOTE_C4
};

int noteDurations[] = {
  4, 4, 4, 4, 4, 4, 2,
  4, 4, 4, 4, 4, 4, 2
};

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 5 as an output for the piezo speaker
  pinMode(5, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  for (int thisNote = 0; thisNote < 14; thisNote++) {
    // calculate the note duration
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(5, melody[thisNote], noteDuration);

    // wait for the note to play
    delay(noteDuration);

    // stop the tone for a brief interval between notes
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
  }
}
