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

extern  int redrawScreen;
int redrawScreen = 1;
int cd_state;
int cd_spin;
int runaway;
int mario;
int hbd;
int fur_elis;
int line;
int on_main;


short drawPos[2] = {40,20}, controlPos[2] = {41 , 20};
short colVelocity = 1, colLimits[2] = {40, screenWidth/2};

void
draw_bar(int col, int row, unsigned short color)
{
  fillRectangle(col-1, row-1, 12, 6, color);
}

void
screen_update_bar()
{
  for (char axis = 0; axis < 2; axis ++) 
    if (drawPos[axis] != controlPos[axis]) 
      goto redraw;
  return;			
 redraw:
  draw_bar(drawPos[0], drawPos[1], COLOR_BLUE); 
  for (char axis = 0; axis < 2; axis ++) 
    drawPos[axis] = controlPos[axis];
  draw_bar(drawPos[0], drawPos[1], COLOR_GREEN); 
}

void wdt_c_handler()
{
  static int sec_cout = 0;
  static int runaway_time = 0;
  static int fureli_time = 0;
  static int hbd_time = 0;
  static int mario_time = 0;
  static int line_time = 0;
  sec_cout++;
  
    if (sec_cout >= 25) {		/* 10/sec */			/* move ball */
      short oldCol = controlPos[0];
      short newCol = oldCol + colVelocity;
      if (newCol <= colLimits[0] || newCol >= colLimits[1])
	      colVelocity = -colVelocity;
      else
	      controlPos[0] = newCol;
      sec_cout = 0;
    redrawScreen = 1;
    }


  if(runaway){
    if(runaway_time >= 3000){
      runaway = 0;
    }
  }
  if(mario){
    if(mario_time >= 3000){
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
  if(line){
    if(line_time >= 2000){
      line = 0;
    }
  }
}

update_shape()
{
  screen_update_bar();
}

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
  on_main = 1;          

  while (1) {		
    if (redrawScreen) {
      redrawScreen = 0;
      update_screen(cd_state);
      if(on_main == 1){
        update_shape();
      }
      update_vynil();
    }
    or_sr(0x10);        
  }  
}