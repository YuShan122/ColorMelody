#ifndef _COLOR_DETECT_H
#define _COLOR_DETECT_H

#include <Arduino.h>
#include <State.h>

#define COLOR_DITECT_PIN_R A0
#define COLOR_DITECT_PIN_G A1
#define COLOR_DITECT_PIN_B A2

#define RANGE 15

class COLOR_DETECT{
    public:
    COLOR_DETECT();
    void setup();
    Color read_color();

    private:
    void print_info();
    int read_values[3];
    bool is_color[8];
    Color detected_color;
    int color_values[8][3];
    
};

extern COLOR_DETECT ColorDetect;

#endif 