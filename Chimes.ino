/*
 * For the Make Apr2019 Live Build
 */

#include <NewPing.h>
#include "note.h"

#define D_MOTOR               2
#define D_ENCODER             3
#define E_MOTOR               4
#define E_ENCODER             5
#define F_MOTOR               6
#define F_ENCODER             7
#define A_MOTOR               8
#define A_ENCODER             9
#define ULTRASONIC_TRIGGER    10
#define ULTRASONIC_ECHO       11

NewPing sonar(ULTRASONIC_TRIGGER, ULTRASONIC_ECHO, 100);
Note d4(D_MOTOR, D_ENCODER);
Note e4(E_MOTOR, E_ENCODER);
Note f4(F_MOTOR, F_ENCODER);
Note a5(A_MOTOR, A_ENCODER);

int distance;

void setup() {
  Serial.begin(9600);
}

void loop() {
  distance = sonar.ping_cm();
  if (distance != 0 && distance < 30) {
    play_song();
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

