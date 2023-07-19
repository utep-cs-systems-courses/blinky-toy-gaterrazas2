.arch msp430g2553   ; Specify the target architecture as MSP430G2553

.p2align 1,0        ; Align the following code on a 2-byte boundary

.file "toy.c"       ; Specifies the source file name as "toy.c"

.global period      ; Declare the "period" to be accessible from other files
.global rate        ; Declare the "rate"to be accessible from other files

buzzer_advance_frequency:   ; Start of the function "buzzer_advance_frequency"
