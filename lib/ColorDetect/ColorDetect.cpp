#include <ColorDetect.h>

COLOR_DETECT ColorDetect;

COLOR_DETECT::COLOR_DETECT()
    : color_values{
        {372, 147, 143},    //R
        {382, 256, 212},    //R+G
        {186, 174, 160},    //G
        {240, 216, 269},    //G+B
        {145, 114, 165},    //B
        {380, 154, 180},    //B+R
        {114,  72,  82},    //Black
        {379, 282, 317}     //White
    }{}

void COLOR_DETECT::setup(){
    pinMode(COLOR_DITECT_PIN_R, INPUT);
    pinMode(COLOR_DITECT_PIN_G, INPUT);
    pinMode(COLOR_DITECT_PIN_B, INPUT);

    detected_color = NO_COLOR;
}

Color COLOR_DETECT::read_color(){
    
    read_values[0] = analogRead(COLOR_DITECT_PIN_R);
    read_values[1] = analogRead(COLOR_DITECT_PIN_G);
    read_values[2] = analogRead(COLOR_DITECT_PIN_B);

    for(int i=0; i<8; i++){
        is_color[i] = true;
        for(int j=0; j<3; j++){
            if(read_values[j] <= color_values[i][j]+RANGE && read_values[j] >= color_values[i][j]-RANGE)
                is_color[i] &= true;
            else is_color[i] = false;
        }
    }

    detected_color = NO_COLOR;
    for(int i=0; i<8; i++){
        if(is_color[i]){
            switch(i){
                case 0:
                detected_color = RED;
                break;
                case 1:
                detected_color = YELLOW;
                break;
                case 2:
                detected_color = GREEN;
                break;
                case 3:
                detected_color = MAGENTA;
                break;
                case 4:
                detected_color = BLUE;
                break;
                case 5:
                detected_color = CYAN;
                break;
                case 6:
                detected_color = BLACK;
                break;
                case 7:
                detected_color = WHITE;
                break;
                default:
                detected_color = NO_COLOR;
                break;
            }
        }
    }

    // if(!is_light[0] && !is_light[1] && !is_light[2]) detected_color = BLACK;
    // if( is_light[0] && !is_light[1] && !is_light[2]) detected_color = RED;
    // if( is_light[0] &&  is_light[1] && !is_light[2]) detected_color = YELLOW;
    // if(!is_light[0] &&  is_light[1] && !is_light[2]) detected_color = GREEN;
    // if(!is_light[0] &&  is_light[1] &&  is_light[2]) detected_color = MAGENTA;
    // if(!is_light[0] && !is_light[1] &&  is_light[2]) detected_color = BLUE;
    // if( is_light[0] && !is_light[1] &&  is_light[2]) detected_color = CYAN;
    // if( is_light[0] &&  is_light[1] &&  is_light[2]) detected_color = WHITE;

    print_info();

    return detected_color;
}

void COLOR_DETECT::print_info(){
    // Serial.print("detected color: ");
    // Serial.print(detected_color);
    // Serial.print(" \n");
    Serial.print("read_values: ");
    Serial.print(read_values[0]);
    Serial.print(" ");
    Serial.print(read_values[1]);
    Serial.print(" ");
    Serial.print(read_values[2]);
    Serial.print(" \n");
}

