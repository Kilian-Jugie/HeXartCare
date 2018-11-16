
void setup() {
  Serial.begin(9600);
}

void loop() {
  int in = analogRead(A0);
  Serial.println(in);
}
