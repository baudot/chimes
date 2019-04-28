#include "note.h"
#include "arduino.h"

Note::Note(int _motor_pin, int _encoder_pin) {
  motor_pin = _motor_pin;
  encoder_pin = _encoder_pin;
}

void Note::play(int duration) {
  long start_time = millis();
  long end_time = start_time + duration;
  int reading = digitalRead(encoder_pin);
  int last_reading = reading;
  int pulse_count = 0;
  digitalWrite(motor_pin, HIGH);
  while (pulse_count < PULSES_PER_ROTATION) {
    reading = digitalRead(encoder_pin);
    if (reading == HIGH && last_reading == LOW) {
      pulse_count++;  
      delay(PULSE_DEBOUNCE_DELAY);
    }
    last_reading = reading;
  }
  digitalWrite(motor_pin, LOW);
  while (millis() < end_time) ;
}

