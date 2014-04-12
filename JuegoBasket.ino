const int ledCount = 5;
int ledPins[] = {3, 4, 5, 6, 7};

const int photoSensor = 0;

int minLight;
int maxLight;
int currentLightLevel;

int lightLevel;

int score = 0;
int levelActive = 100;

const int buzzerPin = 8;

void setup() {
  for (int i=0;i<ledCount;i++)
    pinMode(ledPins[i], OUTPUT);

  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  lightLevel = getLightLevel();
  int lightLevelActive = 0;

  if (lightLevel < 50) {
    lightLevelActive = lightLevel;
    score++;
    setScore();
    playSound();

    while (lightLevelActive >= getLightLevel()) {
      delay(500);
    }
  }

  if (score == 5) {
    win();
    score = 0;
  }

  delay(500);
}

void setScore() {
  for (int led=0;led<ledCount;led++) {
    if (led < score)
      digitalWrite(ledPins[led], HIGH);
    else
      digitalWrite(ledPins[led], LOW);
  }
}

void playSound() {
  digitalWrite(8, HIGH);
  delay(200);
  digitalWrite(8, LOW);
}

void win() {
  for (int i=0;i<5;i++) {
    for (int led=0;led<ledCount;led++)
      digitalWrite(ledPins[led], HIGH);

    playSound();

    for (int led=0;led<ledCount;led++)
      digitalWrite(ledPins[led], LOW);

    delay(50);
  }
}

int getLightLevel() {
  currentLightLevel = analogRead(photoSensor);

  minLight = min(minLight, currentLightLevel);
  maxLight = max(maxLight, currentLightLevel);

  return map(currentLightLevel, minLight, maxLight, 0, 100);
}
