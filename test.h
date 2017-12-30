
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/signal.h>


#define CPU_CLK   14745600

/* normal mode, CPU_CLK/256, interrupt on compareA			*/
#define MY_TIMER_CONTROL_A			TCCR1A
#define MY_TIMER_CONTROL_B			TCCR1B
#define MY_TIMER_INTERRUPT_MASK_REGISTER	TIMSK
#define MY_TIMER_INTERRUPT_MASK_VALUE		_BV(OCIE1A)
#define MY_TIMER_INTERRUPT			SIG_OUTPUT_COMPARE1A
#define MY_TIMER_COUNT_REGISTER			TCNT1
#define MY_TIMER_COMPARE_REGISTER		OCR1A
#define MY_TIMER_CONTROL_A_INIT			0x00
#define MY_TIMER_CONTROL_B_INIT			0x04

#define LAMP_DDR				DDRB
#define LAMP_OPORT				PORTB
#define LAMP_IPORT				PINB
#define LAMP_PIN  				5

