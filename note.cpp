#include "note.h"
#include "arduino.h"

Note::Note(int _motor_pin, int _encoder_pin) {
  motor_pin = _motor_pin;
  encoder_pin = _encoder_pin;
  pulse_count = 0;
}

void Note::play(int duration) {
  long start_time = millis();
  long end_time = start_time + duration;
  int reading = digitalRead(encoder_pin);
  int last_reading = reading;
  digitalWrite(motor_pin, HIGH);
  while (pulse_count < PULSES_PER_ROTATION) {
    reading = digitalRead(encoder_pin);
    if (reading == HIGH && last_reading == LOW) {
      pulse_count++;  
      delay(PULSE_DEBOUNCE_DELAY);
      Serial.println(pulse_count);
    }
    last_reading = reading;
  }
  digitalWrite(motor_pin, LOW);
  pulse_count = 0;
  // Check for overshoot until it's time for the next note.
  while (millis() < end_time) {
    reading = digitalRead(encoder_pin);
    if (reading == HIGH && last_reading == LOW) {
      pulse_count++;  
      delay(PULSE_DEBOUNCE_DELAY);
      Serial.println(pulse_count);
    }
    last_reading = reading;
  }
}

