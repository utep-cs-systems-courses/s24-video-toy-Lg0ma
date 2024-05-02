#ifndef led_included
#define led_included

#include <msp430.h>

#define LED_RED BIT0               
#define LED_GREEN BIT6             
#define LEDS (BIT0 | BIT6)

void led_init();
void led_update();
void green_led_on();
void red_led_on();
void leds_off();
void led_flash(int n);

extern unsigned char r_led_on, g_led_on;
extern unsigned char led_changed;

#endif // included