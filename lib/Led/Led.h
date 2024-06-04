#ifndef _LED_H
#define _LED_H

#include <Arduino.h>
#include <State.h>

#define LED_PIN_R 4
#define LED_PIN_G 5
#define LED_PIN_B 6

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
