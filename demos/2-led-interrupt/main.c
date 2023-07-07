//Alternate LEDs from Off, Green, and Red
#include <msp430.h>
#include "libTimer.h"
#include "led.h"

int main(void) {
    P1DIR |= LEDS;
    // Turns off Red LED
    P1OUT &= ~LED_GREEN;
    // Turns on green LED
    P1OUT |= LED_RED;

    configureClocks();		/* setup master oscillator, CPU & peripheral clocks */
    enableWDTInterrupts();	/* enable periodic interrupt */

    or_sr(0x18);		/* CPU off, GIE on */
}


void
__interrupt_vec(WDT_VECTOR) WDT()	/* 250 interrupts/sec */
{
    // static Counter to keep track of interrupt occurrences without losing value
    static unsigned int counter = 0;

      if (counter < 5) {
        // Toggle the red LED state using XOR operator
        P1OUT ^= LED_GREEN;
      }

      counter++;

      if (counter >= 10) {
        // Reset the counter after reaching the desired number of interrupts
        counter = 0;
      }
}

