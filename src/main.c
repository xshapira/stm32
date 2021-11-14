#include "stm32f4xx_ll_bus.h"
#include "stm32f4xx_ll_gpio.h"
#include "stm32f4xx_ll_rcc.h"
#include "stm32f4xx_ll_system.h"
#include "stm32f4xx_ll_utils.h"

#define button B1
#define in1 6
#define in2 7

int rotDirection = 0;
int pressed = false;

void setup() {
  pinMode(in1, INPUT);
  pinMode(in2, INPUT);
  pinMode(button, INPUT);
  // Set initial rotation direction
  digitalWrite(in1, LOW);
  digitalWrite(in1, HIGH);
}

//  Read button - Debounce
if (digitalRead(button) == true) {
  pressed = !pressed;
}
while (digitalRead(button) == true)
  ;
delay(20);

// If button is pressed - change rotation direction
if (pressed == true & rotDirection == 0) {
  digitalWrite(in1, HIGH);
  digitalWrite(in1, LOW);
  rotDirection = 1;
  delay(20);
}
