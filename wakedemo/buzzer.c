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

void playTune(int *notes, int*tempo, int noteAmt)
{
  for

}

void fur_Elise()
{

  int notes[] = {E4, Dsharp4, E4, Dsharp4, E4, B3, D4, C4, A3, Asharp3, B3, D3, E3, Gsharp3, A3};
  int tempo[] = {362, 362, 362, 362, 362, 725, 543, 543, 1087, 1087, 543, 1087, 543, 406, 1087};
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
  int tempo[] = {500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,};

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
  int notes[] = {C4,C4,G4,G4,A4,A4,G4,F4,F4,E4,E4,D4,D4,C4,E4,E4,D4,D4,E4,E4,D4,G4,G4,F4,F4,E4,E4,D4,D4,C4};
  int tempo[] = {400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400};
  for(int i = 0; i < 30; i++)
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
  int note[] = {Fsharp4, E4, Dsharp4, Csharp4, B3, A3, Gsharp3, Fsharp3, E3, Dsharp3, Csharp3, B2, A2, Gsharp2, Fsharp2};
  int tempo[] = {680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680, 680};
  for(int i = 0; i < 32; i++)
  {

    buzzer_set_period(notes[i]);
    __delay_cycles(10000000);
    buzzer_set_period(0);
    __delay_cycles(7000000);

  }
  buzzer_set_period(0);
}