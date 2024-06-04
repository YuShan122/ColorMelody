#include <ColorDetect.h>

COLOR_DETECT ColorDetect;

void COLOR_DETECT::setup(){
    pinMode(COLOR_DITECT_PIN_R, INPUT);
    pinMode(COLOR_DITECT_PIN_G, INPUT);
    pinMode(COLOR_DITECT_PIN_B, INPUT);

    threshold[0] = 512;
    threshold[1] = 512;
    threshold[2] = 512;

    detected_color = NO_COLOR;
}

Color COLOR_DETECT::read_color(){
    
    read_values[0] = analogRead(COLOR_DITECT_PIN_R);
    read_values[1] = analogRead(COLOR_DITECT_PIN_G);
    read_values[2] = analogRead(COLOR_DITECT_PIN_B);

    for(int i=0; i<3; i++){
        if(read_values[i] > threshold[i]) is_light[i] = true;
        else is_light[i] = false;
    }

    print_info();

    if(!is_light[0] && !is_light[1] && !is_light[2]) detected_color = BLACK;
    if( is_light[0] && !is_light[1] && !is_light[2]) detected_color = RED;
    if( is_light[0] &&  is_light[1] && !is_light[2]) detected_color = YELLOW;
    if(!is_light[0] &&  is_light[1] && !is_light[2]) detected_color = GREEN;
    if(!is_light[0] &&  is_light[1] &&  is_light[2]) detected_color = MAGENTA;
    if(!is_light[0] && !is_light[1] &&  is_light[2]) detected_color = BLUE;
    if( is_light[0] && !is_light[1] &&  is_light[2]) detected_color = CYAN;
    if( is_light[0] &&  is_light[1] &&  is_light[2]) detected_color = WHITE;

    return detected_color;
}

void COLOR_DETECT::print_info(){
    Serial.print("detected color: ");
    Serial.print(detected_color);
    Serial.print(" \n");
    Serial.print("read_values: ");
    Serial.print(read_values[0]);
    Serial.print(" ");
    Serial.print(read_values[1]);
    Serial.print(" ");
    Serial.print(read_values[2]);
    Serial.print(" \n");
    Serial.print("is_light: ");
    Serial.print(is_light[0]);
    Serial.print(" ");
    Serial.print(is_light[1]);
    Serial.print(" ");
    Serial.print(is_light[2]);
    Serial.print(" \n");
}

