const int ledCount = 5;
int ledPins[] = {2, 3, 4, 5, 6};

int buttonR = 9;
int buttonL = 10;

int ledDelay = 100;

void setup() {
  for (int i=0;i<ledCount;i++)
    pinMode(ledPins[i], OUTPUT);

  pinMode(buttonR, INPUT);
  pinMode(buttonL, INPUT);
}

void loop() {
  for (int count=6;count>1;count--) {
    if (count == 2 && digitalRead(buttonR) == LOW) {
      gameOver();
    }

    digitalWrite(count, HIGH);
    delay(ledDelay);
    digitalWrite(count, LOW);
  }

  for (int count=2;count<7;count++) {
    if (count == 6 && digitalRead(buttonL) == LOW) {
      gameOver();
    }

    digitalWrite(count, HIGH);
    delay(ledDelay);
    digitalWrite(count, LOW);
  }
}

void gameOver() {
  for (int i=0;i<10;i++) {
    for (int count=2;count<7;count++) {
      digitalWrite(count, HIGH);
    }

    delay(ledDelay);

    for (int count=2;count<7;count++) {
      digitalWrite(count, LOW);
    }

    delay(ledDelay);
  }
}
