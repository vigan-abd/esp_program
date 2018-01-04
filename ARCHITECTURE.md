Node 0:
Main prog: 
	Read from N3,
	Write to N3,
	Write to N2,
	Write to N1
Timer 0:
 	Error checking (watchdog)
USART0_RX_vect:
 	Read from PC (Blocking Receive)

Node 1:
Main prog: 
	Set light bulb intensity
	LCD Display
Timer 0:
 	Error checking (watchdog) 
Timer 1:
	Check if all data receive, and copy values
USART0_RX_vect:
 	Read from Node 0 (Async Receive)

Node 2:
Main prog:
	Check if full data received, and copy values
Timer 0:
 	Error checking (watchdog)
Timer 1:
	7Segment Display
USART0_RX_vect:
 	Read from Node 0 (Async Receive)

Node 3:
Main prog:
	Check if full data received, and copy values
	Read sensor values
Timer 0:
 	Error checking (watchdog)
Timer 1:
 	Set fan speed (optionaly)
Timer 2:
	Send temperature value (optionaly)
	Send luminischence value (optionaly)
USART0_RX_vect:
 	Read from Node 0 (Async Receive)

Communication Protocol structure:
[aalllfff][dddddddd][dddddddd]....[dddddddd]