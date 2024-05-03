#include <msp430.h>
#include "switches.h"
#include "statemachines.h"
#include "buzzer.h"
#include "led.h"
#include "draw.h"
#include "lcddraw.h"
#include "lcdutils.h"

void next_state(int state) {
  leds_off();
  
  switch(state) {
  case 1:
    clearScreen(COLOR_WHITE);
    led_flash(3);
    leds_off();
    fur_Elise();
    leds_off();
    break;
  case 2:
    clearScreen(COLOR_BEIGE);
    led_flash(3);
    leds_off();
    red_led_on();
    happy_Bday();
    leds_off();
    break;
  case 3:
    clearScreen(COLOR_BLUE);
    led_flash(3);
    leds_off();
    red_led_on();
    Mario();
    leds_off();
    break;
  case 4:
    clearScreen(COLOR_RED);
    led_flash(3);
    leds_off();
    red_led_on();
    runaway();
    runaway_cover();
    leds_off();
    break;
  default:
    clearScreen(COLOR_RED);
    green_led_on();
    break;
  }
  // Turn on the green led to indicate it's ready for the next step.
  green_led_on();
}
