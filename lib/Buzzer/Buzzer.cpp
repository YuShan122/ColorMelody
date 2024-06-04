#include <Buzzer.h>

BUZZER Buzzer;

void BUZZER::setup(){
    pinMode(BUZZER_PIN, OUTPUT);
}

void BUZZER::bee(Color color_){
    color = color_;
    switch(color){
        case NO_COLOR:
        noTone(BUZZER_PIN);
        break;

        case RED:
        tone(BUZZER_PIN, 262);
        break;

        case YELLOW:
        tone(BUZZER_PIN, 294);
        break;

        case GREEN:
        tone(BUZZER_PIN, 330);
        break;

        case MAGENTA:
        tone(BUZZER_PIN, 349);
        break;

        case BLUE:
        tone(BUZZER_PIN, 392);
        break;

        case CYAN:
        tone(BUZZER_PIN, 440);
        break;

        case BLACK:
        tone(BUZZER_PIN, 494);
        break;

        case WHITE:
        noTone(BUZZER_PIN);
        break;

    }
}

void BUZZER::print_info(){
    Serial.print("buzzer color: ");
    Serial.print(color);
    Serial.print(" \n");
}