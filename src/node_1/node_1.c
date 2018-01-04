#include "node_1.h"
// NODE 1
// PORTD has access to LED1

// Activate led2 and deactivate led1

void init_port ()
{
    DDRD = 0xFF;
    PORTD = 0xFF;
}

int main(void)
{
	cli();
    init_port();
    PORTD = 0x00;
    while (1)
        ;
	return 0;
}