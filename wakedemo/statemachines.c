#include <msp430.h>
#include "switches.h"
#include "statemachines.h"
#include "buzzer.h"
#include "led.h"
#include "draw.h"
#include "lcddraw.h"
#include "lcdutils.h"

extern  int cd_state;
extern  int cd_spin;
extern  int line;
extern  int runaway;
extern  int mario;
extern  int hbd;
extern  int fur_elis;
extern int line;

void next_state(int state) {
  leds_off();
  
  switch(state) {
  case 0:
    line =1;
    drawLine(20,40,20,COLOR_BLACK);
    drawString5x7(20,15,"I did that in assembly",WHITE,BLACK);
    __delay_cycles(150000);
    restore_vynil();
    line = 0;
    break;
  case 1:
    runaway = 1;
    runaway_cover();
    draw_Play_Button();
    runawey();
    restore_vynil();
    runaway = 0;
    break;
  case 2:
    mario = 1;
    draw_level();
    draw_Play_Button();
    Mario();
    restore_vynil();
    mario = 0;
    break;
  case 3:
    hbd = 1; 
    draw_Cake();
    draw_Play_Button();
    happy_Bday();
    restore_vynil();
    hbd = 0;
    break;
  case 4:
    fur_elis = 1;
    draw_Piano();
    draw_Play_Button();
    fur_Elise();
    restore_vynil();
    fur_elis = 0; 
    break;
  default:
    green_led_on();
    break;
  }
  // Turn on the green led to indicate it's ready for the next step.
  green_led_on();
}
