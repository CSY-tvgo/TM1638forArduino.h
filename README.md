#TM1638forArduino  
==================
This is my `first` uploaded git and thanks to [moozzyk's TM1638 git](https://github.com/moozzyk/TM1638).  
This .h file is used to let `TM1638` work with `Arduino`.  


* The pins of strobe, clock and data are needed to be defined.
>Functions:  
>* `reset();`  
>Reset the LED screen.  
>
>* `setLed(uint8_t value, uint8_t position);`  
>Let the corresponding Led bulb to be lightened.
>value is 0 or 1.  
>position is from 0 to 7.
>
>* `screen(long num,int dotLocation);`  
>Show the number on screen.  
>num is an long integer from -9999999 to 9999999, this number will show on the screen.  
>dotLocation is an integer. If it is from 0 to 7, the corresponding dot will be lightened.
>
>* `readButtons();`  
>this function will return the number of the button which is pushed.  


#EOF