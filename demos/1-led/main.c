// Alternate LEDs from Off, Green, and Red
// Include the MSP430 microcontroller header file
#include <msp430.h>
// Include the library for timer functions
#include "libTimer.h"
// Include the library for LED functions
#include "led.h"

int main(void) {
    // Set the direction of Port 1 pins as output for LEDs
    P1DIR |= LEDS;
    // Turn off the red LED by clearing the corresponding bit
    P1OUT &= ~LED_RED;
    // Turn on the  green LED by setting the corresponding bit
    P1OUT |= LED_GREEN;

    or_sr(0x18);         
}
