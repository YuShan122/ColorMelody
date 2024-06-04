#ifndef _BUZZER_H
#define _BUZZER_H

#include <Arduino.h>
#include <State.h>

#define BUZZER_PIN 3

class BUZZER{
    public:
    void setup();
    void bee(Color color_);

    private:
    double frequency;
    Color color;
    void print_info();
};

extern BUZZER Buzzer;


#endif