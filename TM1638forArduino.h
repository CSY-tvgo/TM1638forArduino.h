uint8_t digits[] = { 0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f };	//number library

void sendCommand(uint8_t value)
{
	digitalWrite(strobe, LOW);
	shiftOut(data, clock, LSBFIRST, value);
	digitalWrite(strobe, HIGH);
}

void reset()
{
	sendCommand(0x40); // set auto increment mode
	digitalWrite(strobe, LOW);
	shiftOut(data, clock, LSBFIRST, 0xc0);   // set starting address to 0
	for (uint8_t i = 0; i < 16; i++)
	{
		shiftOut(data, clock, LSBFIRST, 0x00);
	}
	digitalWrite(strobe, HIGH);
}

void setLed(uint8_t value, uint8_t position)
{
	pinMode(data, OUTPUT);
	//sendCommand(0x44);
	digitalWrite(strobe, LOW);
	shiftOut(data, clock, LSBFIRST, 0xC1 + (position << 1));
	shiftOut(data, clock, LSBFIRST, value);
	digitalWrite(strobe, HIGH);
}

void screen(long num,int dotLocation)
{
	int position = 1;
	sendCommand(0x40);
	digitalWrite(strobe, LOW);
	shiftOut(data, clock, LSBFIRST, 0xc0);
	if (num < 0)
	{
		shiftOut(data, clock, LSBFIRST, 0x40);
		shiftOut(data, clock, LSBFIRST, 0x00);
	}
	if (num>=0)
	{
		shiftOut(data, clock, LSBFIRST, 0x00);
		shiftOut(data, clock, LSBFIRST, 0x00);
	}
	num=abs(num);
	if (num > 9999999)
	{
		for (position; position < 8; position++)
		{
			shiftOut(data, clock, LSBFIRST, 0x76);
			shiftOut(data, clock, LSBFIRST, 0x00);
		}
	}
	else
	{
		int S[8];
		for (int i = 7; i >= 0; i--)
		{
			S[i] = num % 10;
			num = num / 10;
		}
		for (position; position < 8; position++)
		{
			if(dotLocation==position)
				shiftOut(data, clock, LSBFIRST, digits[S[position]]+0x80);//screen the dot
			else
				shiftOut(data, clock, LSBFIRST, digits[S[position]]);
			shiftOut(data, clock, LSBFIRST, 0x00);
		}
	}
	digitalWrite(strobe, HIGH);
}

uint8_t readButtons(void)
{
	uint8_t buttons = 0;
	int buttonNum = 0;
	digitalWrite(strobe, LOW);
	shiftOut(data, clock, LSBFIRST, 0x42);
	pinMode(data, INPUT);
	for (uint8_t i = 0; i < 4; i++)
	{
		uint8_t v = shiftIn(data, clock, LSBFIRST) << i;
		buttons |= v;
	}
	pinMode(data, OUTPUT);
	digitalWrite(strobe, HIGH);
	switch (buttons)
	{
	case 1:buttonNum = 1; break;
	case 2:buttonNum = 2; break;
	case 4:buttonNum = 3; break;
	case 8:buttonNum = 4; break;
	case 16:buttonNum = 5; break;
	case 32:buttonNum = 6; break;
	case 64:buttonNum = 7; break;
	case 128:buttonNum = 8; break;
	}
	return buttonNum;
}


