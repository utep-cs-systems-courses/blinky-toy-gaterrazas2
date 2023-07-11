#ifndef led_included
#define led_included

#ifdef NEW_MSP_BOARD
# define LED_GREEN BIT0               // P1.0
# define LED_RED BIT6             // P1.6
#else
# define LED_RED BIT0               // P1.0
# define LED_GREEN BIT6             // P1.6
#endif

#define LEDS (BIT0 | BIT6)

#endif // included
