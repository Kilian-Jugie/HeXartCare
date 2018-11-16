#include "hearth.h"

#include "param.h"

int choicemode;

void setup() {
pinMode(2, OUTPUT);
pinMode(3, OUTPUT);
pinMode(4, OUTPUT);
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);
pinMode(7, OUTPUT);
pinMode(8, OUTPUT);
pinMode(9, OUTPUT);
pinMode(10, OUTPUT);
pinMode(11, OUTPUT);
Serial.begin(9600);
 
}

unsigned long timeStart = 0;


void loop() {
	int value = analogRead(A0);
	if (millis() - timeStart > 1000) {
		timeStart = millis();
		Serial.println((value/300)+1);
		switch (choice)
		{
		case 1:
			mod1();
			break;
		case 2:
			mod2();
			break;
		case 3:
			mod3();
			break;
		case 4:
			mod4();
			break;  
		}
	}

    
}

