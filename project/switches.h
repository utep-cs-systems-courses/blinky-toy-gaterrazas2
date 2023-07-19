#ifndef SWITCHES_H
#define SWITCHES_H

#define S1 BIT0
#define S2 BIT1
#define S3 BIT2
#define S4 BIT3
#define P2_SWITCHES (S1 | S2 | S3 | S4)

void switch_init();
void switch_interrupt_handler();

#endif /* SWITCHES_H */
