unsigned long timeStart = 0;

void setup() {
	Serial.begin(9600);
}

void loop() {
	int value = analogRead(A0);
	if (millis() - timeStart > 1000) {
		timeStart = millis();
		Serial.println((value/300)+1);
	}
}
