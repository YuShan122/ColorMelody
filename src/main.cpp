#include <Arduino.h>
#include <ColorDetect.h>
#include <Led.h>
#include <Buzzer.h>

/* to-do list */
/* [v] read from photoresistor */
/* [v] output RGB LED */
/* [v] output buzzer */

Color state;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  ColorDetect.setup();
  Led.setup();
  Buzzer.setup();

  state = NO_COLOR;
  Led.shine(BLACK);
  Buzzer.bee(WHITE);

  
  Led.shine(RED);
  Buzzer.bee(RED);
  delay(500);
  Led.shine(GREEN);
  Buzzer.bee(GREEN);
  delay(500);
  Led.shine(BLUE);
  Buzzer.bee(BLUE);
  delay(500);
  Led.shine(BLACK);
  Buzzer.bee(BLACK);
  delay(500);

}

void loop() {
  // put your main code here, to run repeatedly:
  state = ColorDetect.read_color();
  Led.shine(state);
  Buzzer.bee(state);
  delay(1000);
  
}

// put function definitions here:
