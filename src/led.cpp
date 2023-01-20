#include "Arduino.h"
#include "../include/led.h"


void Led::Initialize() const {
    pin_.Initialize();

    Serial.print(name_);
    Serial.println(" Initialized");
}

void Led::On() const {
    pin_.On(255);
}

void Led::Off() const {
   pin_.On(0);
   duty_cycle_ = 0;
}

void Led::Toggle() const {
    pin_.Toggle();
}

void Led::Pulse() const {
    if (duty_cycle_ <= 0) {
        pulse_up_ = true;
    } else if (duty_cycle_ >= MaxPulseValue) {
        pulse_up_ = false;
    }

    if (pulse_up_) {
        duty_cycle_ += PulseSpeed;
    } else {
        duty_cycle_ -= PulseSpeed;
    }
    pin_.On(duty_cycle_);
}