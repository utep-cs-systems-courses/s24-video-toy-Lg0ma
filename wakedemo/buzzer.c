#include <msp430.h>
#include <libTimer.h>
#include "buzzer.h"
#include "notes.h"
#include "statemachines.h"
#include "led.h"

void buzzer_init()
{
    timerAUpmode();		/* used to drive speaker */
    P2SEL2 &= ~(BIT6 | BIT7);
    P2SEL &= ~BIT7; 
    P2SEL |= BIT6;
    P2DIR = BIT6;		/* enable output to speaker (P2.6) */
}

void buzzer_set_period(short cycles)
{
  CCR0 = cycles; 
  CCR1 = cycles >> 1;	
}

void playTune(int *notes, int*tempo, int noteAmt)
{
  for(int i = 0; i < noteAmt; i++)
  {
    if((i % 2) == 0 ){
      red_led_on();
    }else{
      green_led_on();
    }

    buzzer_set_period(1000000 / notes[i]);
    int dur = tempo[i];
    while(dur--)
    {
    __delay_cycles(10000);

    }
    leds_off();
  }
  buzzer_set_period(bk);
  
}

void fur_Elise()
{

  int notes[] = {E4, Dsharp4, E4, Dsharp4, E4, B3, D4, C4, A3, Asharp3, B3, D3, E3, Gsharp3, A3};
  int tempo[] = {362, 362, 362, 362, 362, 525, 543, 543, 700, 700, 543, 700, 543, 406, 700};

  int noteAmt = sizeof(notes)/sizeof(notes[0]);
  playTune(notes,tempo,noteAmt);
  buzzer_set_period(bk);
}

void happy_Bday()
{

  int notes[] = {G4,G4,A3,G4,C4,B5,bk,G4,G4,A3,G4,D5,C4,bk,G4,G4,G5,E4,C4,B5,A3,bk,F4,F4,E4,C4,D5,C4};
  int tempo[] = {500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,};

  int noteAmt = sizeof(notes)/sizeof(notes[0]);
  playTune(notes,tempo,noteAmt);
  buzzer_set_period(bk);
}

void Mario()
{
  int notes[] = {C4,C4,G4,G4,A4,A4,G4,F4,F4,E4,E4,D4,D4,C4,E4,E4,D4,D4,E4,E4,D4,G4,G4,F4,F4,E4,E4,D4,D4,C4};
  int tempo[] = {400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400};
  
  int noteAmt = sizeof(notes)/sizeof(notes[0]);
  playTune(notes,tempo,noteAmt);
  buzzer_set_period(bk);
}

void runawey()
{
  int notes[] = {E4, E4, E4, E4, G4, E4, D4, D4, D4, D4, B4, D4, C4, C4, C4, C4, E4, D4};
  int tempo[] = {500, 500, 500, 500, 1000, 500, 500, 500, 500, 500, 1000, 500, 500, 500, 500, 500, 1000, 500};

  int noteAmt = sizeof(notes)/sizeof(notes[0]);
  playTune(notes,tempo,noteAmt);
  buzzer_set_period(bk);
}
