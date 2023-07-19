#include <msp430.h>
#include "switches.h"
#include "led.h"

char switch_state_down;

void switch_init() {
  P2REN |= P2_SWITCHES;
  P2OUT |= P2_SWITCHES;
  P2DIR &= ~P2_SWITCHES;
  P2IE = P2_SWITCHES;
  P2IES |= P2_SWITCHES; // Set interrupt on high-to-low transition
  P2IFG &= ~P2_SWITCHES; // Clear interrupt flags for switches
}

// Handle switches 1-3
void switch_interrupt_handler() {
  // P2IN tells you which switches are up (not being pressed)
  switch_state_down = ~P2IN;
  
  if (switch_state_down & S1) {
    P1OUT |= LED_GREEN; // Turn on the green LED when S1 is pressed
    P1OUT &= ~LED_RED;  // Turn off the red LED when S1 is pressed
  } else if (switch_state_down & S2) {
    P1OUT |= LED_RED;   // Turn on the red LED when S2 is pressed
    P1OUT &= ~LED_GREEN; // Turn off the green LED when S2 is pressed
  } else if (switch_state_down & S3) {
      P1OUT |= LEDS; // Turn on both LEDs when S3 is pressed

  }
}
