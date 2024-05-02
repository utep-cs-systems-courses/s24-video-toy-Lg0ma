#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "notes.h"
#include "statemachines.h"


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


void fur_Elise()
{

  int notes[] = {E5,D5,E5,D5,E5,B5,D5,C5,A5,A4,C4,E4,A5,B5,E4,E4,E5,Gsharp5,B5,C5,A4,E5};

  for(int i = 0; i < 22; i++)
  {
    buzzer_set_period(notes[i]);
    __delay_cycles(4500000);
    buzzer_set_period(0);
    __delay_cycles(500000);
  }
  buzzer_set_period(0);
}

void happy_Bday()
{

  int notes[] = {G4,G4,A3,G4,C4,B5,bk,G4,G4,A3,G4,D5,C4,bk,G4,G4,G5,E4,C4,B5,A3,bk,F4,F4,E4,C4,D5,C4};

  for(int i = 0; i < 28; i++)
  {
    buzzer_set_period(notes[i]);
    __delay_cycles(5000000);
    buzzer_set_period(0);
    __delay_cycles(4500000);
  }
  buzzer_set_period(0);
}

void Mario()
{

  int notes[] = {E5,E5,E5,C5,E5,G5,bk,G5,bk,C5,G5,E5,A5,B5,Bb5,A5,G5,E5,G5,A5,F5,G5,E5,C5,D5,B5};

  for(int i = 0; i < 26; i++)
  {
    buzzer_set_period(notes[i]);
    __delay_cycles(2500000);
    buzzer_set_period(0);
    __delay_cycles(2500000);
  }
  buzzer_set_period(0);
}

void runaway()
{
  int notes[] = {E6,E6,E6,E4,E6,E6,E6,D4,E6,E6,E6,C4,A5,A5,A5,G5,E6,E6,E6,E4,E6,E6,E6,D4,E6,E6,E6,C4,A5,A5,A5,G5};

  for(int i = 0; i < 32; i++)
  {

    buzzer_set_period(notes[i]);
    __delay_cycles(10000000);
    buzzer_set_period(0);
    __delay_cycles(7000000);

  }
  buzzer_set_period(0);
}