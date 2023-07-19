#include <msp430.h>
#include "libTimer.h"
#include "switches.h"
#include "led.h"
#include "buzzer.h"

static short play_sound;
static char start;

int main(void) {
  start = 0;
  configureClocks();
  buzzer_init();
  switch_init();
  enableWDTInterrupts();
  play_sound = 1;
  or_sr(0x18);
}



// Handle the switch inputs
void __interrupt_vec(PORT2_VECTOR) Port_2() {
  if (P2IFG & S1) {
    led_init();
    P2IFG &= ~S1;
    switch_interrupt_handler();
  }
  else if (P2IFG & S2) {
    led_init();
    P2IFG &= ~S2;
    switch_interrupt_handler();
  }
  else if (P2IFG & S3) {
    led_init();
    P2IFG &= ~S3;
    switch_interrupt_handler();
  }
  else if (P2IFG & S4) {
    led_init();
    P2IFG &= ~S4;
    start = 1;
    play_sound = (2 * 250);
    buzzer_advance_frequency();
  }
}

// Handle the buzzer timer
void __interrupt_vec(WDT_VECTOR) WDT() {
 if (1) {
  if (start && play_sound > -1) {
    if (--play_sound == 0) {
      buzzer_set_period(0);
      start = 0;
    } else if ((play_sound % 50) == 0) {
      buzzer_advance_frequency();
      buzzer_set_period(play_sound);
      P1OUT = LEDS;
      __delay_cycles(10000);
      P1OUT &= ~LED_GREEN;
      __delay_cycles(10000);
      P1OUT &= ~LED_RED;
      __delay_cycles(10000);
    }
  }
 }
}
