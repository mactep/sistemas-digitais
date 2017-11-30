int led1 = 3;
int led2 = 7;
int led3 = 13;
int button1 = 8;
int button2 = 10;
int ledarray[] = {led1, led2, led3};

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
}

void loop() {
  if (digitalRead(button1) == LOW) {
    int order[3] = {0, 1 ,2};
    blinka(ledarray, order);
  }
  if (digitalRead(button2) == LOW) {
    int order[3] = {1, 0 ,2};
    blinka(ledarray, order);
  }
}

void blinka(int vet[], int ord[]) {
  for (int i = 0; i < 3; i++) {
    digitalWrite(vet[ord[i]], HIGH);
    delay(1000);
    digitalWrite(vet[ord[i]], LOW);
    delay(1000);
  }
}
