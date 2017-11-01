/*
  Happy birthday

  Circuit:
  - 8 ohm speaker on digital pin 8

  Based on toneMelody by Tom Igoe (http://www.arduino.cc/en/Tutorial/Tone)

  Made by Mathias Brandal Vagnes (https://github.com/vagnes)
  
*/

#include "pitches.h"

// Notes in the melody:
int melody[] = {
  NOTE_C4, NOTE_C4, NOTE_D4, NOTE_C4, NOTE_F4, NOTE_E4, NOTE_C4, NOTE_C4, NOTE_D4, NOTE_C4, NOTE_G4, NOTE_F4, NOTE_C4, NOTE_C4, NOTE_C5, NOTE_A4, NOTE_F4, NOTE_E4, NOTE_D4, NOTE_AS4, NOTE_AS4, NOTE_A4, NOTE_F4, NOTE_G4, NOTE_F4  
};

// Note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 16, 4, 4, 4, 2, 4, 16, 4, 4, 4, 2, 4, 16, 4, 4, 4, 4, 4, 4, 16, 4, 4, 4, 2,
};

void setup() {
  // Iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 25; thisNote++) {

    // To calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 2000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);

    // To distinguish the notes, set a minimum time between them.
    // The note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.25;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
  }
}

void loop() {
  // No need to repeat the melody.
  // One time is totally enough.
  // Trust me.
}
