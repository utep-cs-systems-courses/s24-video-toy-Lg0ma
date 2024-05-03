#include <msp430.h>
#include <stdio.h>
#include <libTimer.h>
#include "led.h"
#include "switches.h"
#include "buzzer.h"
#include "lcdutils.h"
#include "lcddraw.h"
#include "statemachines.h"
#include "switches.h"
#include "draw.h"

int main(void)
{
  configureClocks();
  switch_init(); // switches
  led_init(); // LED
  buzzer_init(); // Buzzer
  lcd_init();
  enableWDTInterrupts();
  green_led_on();

  or_sr(0x8);                  /**< GIE (enable interrupts) */
  clearScreen(COLOR_BLACK);
  clearScreen(COLOR_WHITE);


  or_sr(0x18); // CPU off, GIE on   
}