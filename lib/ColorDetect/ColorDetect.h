#ifndef _COLOR_DETECT_H
#define _COLOR_DETECT_H

#include <Arduino.h>
#include <State.h>

#define COLOR_DITECT_PIN_R A0
#define COLOR_DITECT_PIN_G A1
#define COLOR_DITECT_PIN_B A3


class COLOR_DETECT{
    public:
    void setup();
    Color read_color();

    private:
    void print_info();
    int read_values[3];
    bool is_light[3];
    int threshold[3];
    Color detected_color;
    
};

extern COLOR_DETECT ColorDetect;

#endif 