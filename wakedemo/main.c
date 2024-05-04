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

extern u_char redrawScreen;
u_char redrawScreen = 1;
u_char cd_state;
u_char cd_spin;
u_char line;
u_char runaway;
u_char mario;
u_char hbd;
u_char fur_elis;

void main(void) 
{
  configureClocks();
  lcd_init();
  switch_init();
  led_init();
  buzzer_init();
  enableWDTInterrupts();   

  led_flash(2);
  or_sr(0x8);     
  restore_vynil();
  cd_state =1;
  cd_spin = 1;             

  while (1) {		
    if (redrawScreen) {
      redrawScreen = 0;
      update_screen(cd_state);
    }
    or_sr(0x10);        
  }  
}

void wdt_c_handler()
{
  static int cd_time = 0;
  static int runaway_time = 0;
  static int fureli_time = 0;
  static int hbd_time = 0;
  static int mario_time = 0;
  
  if(cd_spin){
    if(cd_time++ >= 1000) {
      cd_time = 0;
      cd_state = 0;
      redrawScreen = 1;
    }
  }
  else{
    if(cd_time++ >= 2000) {
      cd_time = 0;
      cd_spin = 1;
      redrawScreen = 1;
    }
  }
  if(runaway){
    if(runaway_time >= 2000){
      runaway = 0;
    }
  }
  if(mario){
    if(mario_time >= 2000){
      mario = 0;
    }
  }
  if(hbd){
    if(hbd_time >= 2000){
      hbd = 0;
    }
  }
  if(fur_elis){
    if(fureli_time >= 2000){
      fur_elis = 0;
    }
  }
  // if(mc){
  //   if(mc_time >= 2000){
  //     mc = 0;
  //     clearMain();
  //   }
  // }
}
