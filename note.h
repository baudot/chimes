#ifndef __note__
#define __note__

#define PULSES_PER_ROTATION   128
#define PULSE_DEBOUNCE_DELAY  5

class Note {
  public :
    Note(int motor_pin, int encoder_pin);
    void play(int duration);
  private:
    int motor_pin;
    int encoder_pin;
    int pulse_count;
};

#endif
