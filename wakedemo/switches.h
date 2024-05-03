#ifndef switches_included
#define switches_included

#define SW0 BIT3 //button0 connected to P1.3 Bit3
#define SW1 BIT0 //button1 connected to P2.0 Bit0
#define SW2 BIT1 //button2 connected to P2.1 Bit1
#define SW3 BIT2 //button3 connected to P2.2 Bit2
#define SW4 BIT3 //button4 connected to P2.3 Bit3

#define SWITCHES (SW1 | SW2 | SW3 | SW4)//defines switches to the bits we need


void switch_init();
void switch_interrupt_handler();
char switch_update_interrupt_sense();
extern char switch_state_down;


#endif
