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
int line;
int runaway;
int mario;
int hbd;
int fur_elis;
int line;

void update_vynil()
{
	if(cd_state == 1)
  {
    draw_shine1();
  }else if(cd_state == 0)
  {
    draw_shine2();
  }
}

short drawPos[2] = {1,10}, controlPos[2] = {2, 10};
short colVelocity = 1, colLimits[2] = {1, screenWidth/2};

void
draw_ball(int col, int row, unsigned short color)
{
  fillRectangle(col-1, row-1, 3, 3, color);
}

void
screen_update_ball()
{
  for (char axis = 0; axis < 2; axis ++) 
    if (drawPos[axis] != controlPos[axis]) /* position changed? */
      goto redraw;
  return;			/* nothing to do */
 redraw:
  draw_ball(drawPos[0], drawPos[1], COLOR_BLUE); /* erase */
  for (char axis = 0; axis < 2; axis ++) 
    drawPos[axis] = controlPos[axis];
  draw_ball(drawPos[0], drawPos[1], COLOR_WHITE); /* draw */
}

void
update_shape()
{
  screen_update_ball();
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

  while (1) {		
    if (redrawScreen) {
      redrawScreen = 0;
      update_screen(cd_state);
      update_vynil();
      update_shape();
    }
    or_sr(0x10);        
  }  
}

void wdt_c_handler()
{
  static int sec_cout = 0;
  static int cd_time = 0;
  static int runaway_time = 0;
  static int fureli_time = 0;
  static int hbd_time = 0;
  static int mario_time = 0;
  static int line_time = 0;
  sec_cout++;
  
  if(sec_cout >= 250){
    cd_state = 1;
    redrawScreen = 1;
  }
  if(cd_state){
    update_vynil();
  }

//----------------------------------------------------
if (sec_cout >= 25) {		/* 10/sec */
   
    {				/* move ball */
      short oldCol = controlPos[0];
      short newCol = oldCol + colVelocity;
      if (newCol <= colLimits[0] || newCol >= colLimits[1])
	colVelocity = -colVelocity;
      else
	controlPos[0] = newCol;
    }

    {				/* update hourglass */
    redrawScreen = 1;
  }
//----------------------------------------------------

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
