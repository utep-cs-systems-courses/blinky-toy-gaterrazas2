#ifndef LED_H
#define LED_H

#define LED_RED BIT6
#define LED_GREEN BIT0
#define LEDS (BIT0 | BIT6)

void led_init();

#endif /* LED_H */
