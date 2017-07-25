		This is my first uploaded git and thanks to Pawel Kadluczka's TM1638 git.
		
		This .h file is used to let TM1638 work with Arduino.

		The pin of strobe, clock and data is needed to be defined.<br>
>functions:
		`reset();` 
		reset the LED screen.

		`setLed(uint8_t value, uint8_t position);`
		show the number in screen. value is a number from -9999999 to 9999999.

		`readButtons();`
		this function will return the number of the button which is pushed.