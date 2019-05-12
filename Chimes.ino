/*
 * For the Make Apr2019 Live Build
 */

// NewPing is a classic arduino library for inexpensive rangefinders.
// If you've never downloaded it, you'll need to go into the Arduino menu
// at Sketch->Include Library->Manage Libraries and download it there. 
#include "note.h"

#define D_MOTOR               2
#define D_ENCODER             3
#define E_MOTOR               A4
#define E_ENCODER             4
#define F_MOTOR               6
#define F_ENCODER             7
#define A_MOTOR               8
#define A_ENCODER             9
#define PIR                   A3

Note d4(D_MOTOR, D_ENCODER);
Note e4(E_MOTOR, E_ENCODER);
Note f4(F_MOTOR, F_ENCODER);
Note a5(A_MOTOR, A_ENCODER);


void setup() {
  Serial.begin(9600);
  pinMode(D_MOTOR, OUTPUT);
  pinMode(E_MOTOR, OUTPUT);
  pinMode(F_MOTOR, OUTPUT);
  pinMode(A_MOTOR, OUTPUT);
  pinMode(D_ENCODER, INPUT);
  pinMode(E_ENCODER, INPUT);
  pinMode(F_ENCODER, INPUT);
  pinMode(A_ENCODER, INPUT);
}

void loop() {
  if (digitalRead(PIR)) {
    Serial.println("Person detected.");
    // Start playing if someone gets within a foot of the rangefinder.
    play_song();
    // Don't play again if the person is still standing in front of the sensor.
    while (digitalRead(PIR)) ;
    Serial.println("Person no longer present, resetting.");
  }
}

void play_song() {
  d4.play(1000);
  d4.play(500);
  a5.play(250);
  a5.play(250);
  a5.play(750);
  a5.play(500);
  e4.play(750);
  f4.play(250);
  e4.play(500);
  d4.play(3000);
}

