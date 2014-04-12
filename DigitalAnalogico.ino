const int ledCount = 5;
int ledPins[] = {3, 4, 5, 6, 7};

void setup() {
  Serial.begin(9600);

  for (int i=0;i<ledCount;i++)
    pinMode(ledPins[i], OUTPUT);
}

void loop() {
  int sensorValue = analogRead(A0);

  Serial.println(sensorValue);

  int ledValue = map(sensorValue, 0, 1023, 0, 5);

  for (int i=0;i<ledCount;i++)
    if (ledValue <= i)
      digitalWrite(ledPins[i], LOW);
    else
      digitalWrite(ledPins[i], HIGH);

  delay(50);
}