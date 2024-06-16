#include <Led.h>

LED Led;

void LED::setup(){
    pinMode(LED_PIN_R, OUTPUT);
    pinMode(LED_PIN_G, OUTPUT);
    pinMode(LED_PIN_B, OUTPUT);

    color = NO_COLOR;
}

void LED::shine(Color color_){
    color = color_;
    switch(color){
        case NO_COLOR:
        digitalWrite(LED_PIN_R, LOW);
        digitalWrite(LED_PIN_G, LOW);
        digitalWrite(LED_PIN_B, LOW);
        break;

        case RED:
        digitalWrite(LED_PIN_R, HIGH);
        digitalWrite(LED_PIN_G, LOW);
        digitalWrite(LED_PIN_B, LOW);
        break;

        case YELLOW:
        digitalWrite(LED_PIN_R, HIGH);
        digitalWrite(LED_PIN_G, HIGH);
        digitalWrite(LED_PIN_B, LOW);
        break;

        case GREEN:
        digitalWrite(LED_PIN_R, LOW);
        digitalWrite(LED_PIN_G, HIGH);
        digitalWrite(LED_PIN_B, LOW);
        break;
        
        case MAGENTA:
        digitalWrite(LED_PIN_R, LOW);
        digitalWrite(LED_PIN_G, HIGH);
        digitalWrite(LED_PIN_B, HIGH);
        break;
        
        case BLUE:
        digitalWrite(LED_PIN_R, LOW);
        digitalWrite(LED_PIN_G, LOW);
        digitalWrite(LED_PIN_B, HIGH);
        break;
        
        case CYAN:
        digitalWrite(LED_PIN_R, HIGH);
        digitalWrite(LED_PIN_G, LOW);
        digitalWrite(LED_PIN_B, HIGH);
        break;
        
        case BLACK:
        digitalWrite(LED_PIN_R, HIGH);
        digitalWrite(LED_PIN_G, HIGH);
        digitalWrite(LED_PIN_B, HIGH);
        break;
        
        case WHITE:
        digitalWrite(LED_PIN_R, LOW);
        digitalWrite(LED_PIN_G, LOW);
        digitalWrite(LED_PIN_B, LOW);
        break;
        
        default:
        Serial.println("color not correct!");
        digitalWrite(LED_PIN_R, LOW);
        digitalWrite(LED_PIN_G, LOW);
        digitalWrite(LED_PIN_B, LOW);
        break;
        
    }
    // print_info();
}

void LED::print_info(){
    Serial.print("LED color: ");
    Serial.print(color);
    Serial.print(" \n");
}