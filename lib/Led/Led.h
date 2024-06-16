#ifndef _LED_H
#define _LED_H

#include <Arduino.h>
#include <State.h>

#define LED_PIN_R A3
#define LED_PIN_G A5
#define LED_PIN_B A4

class LED{
    public:
    void setup();
    void shine(Color color_);

    private:
    void print_info();
    Color color;
};

extern LED Led;

#endif
