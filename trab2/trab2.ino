int led1 = 11; // define a porta do led
int led2 = 12; // define a porta do led
int led3 = 13; // define a porta do led
int botao1 = 2; // define a porta do botao
int botao2 = 3; // define a porta do botao
int ledarray[3] = {led1, led2, led3}; // define vetor com leds
int ordem1[3] = {0, 1, 2}; // define ordem de acendimento
int ordem2[3] = {2, 1, 0}; // define ordem de acendimento
int estado = 1; // variavel pra indicar a ordem que deve ser usada

void setup() {
  pinMode(led1, OUTPUT); // define as portas como entrada/saida
  pinMode(led2, OUTPUT); // define as portas como entrada/saida
  pinMode(led3, OUTPUT); // define as portas como entrada/saida
  pinMode(botao1, INPUT); // define as portas como entrada/saida;
  pinMode(botao2, INPUT); // define as portas como entrada/saida;
}

void loop() {
  if (estado == 1) { // checa o estado
    for (int i = 0; i < 3; i++) { // loop pra percorrer o vertor ordem
      if (digitalRead(botao1) == LOW) { // checa o botao
        estado = 2;
      }
      else if (digitalRead(botao2) == LOW) { // checa o outro
        estado = 1;
      }
      digitalWrite(ledarray[ordem1[i]], HIGH); // pisca
      delay(300);
      digitalWrite(ledarray[ordem1[i]], LOW);
    }
  }
  if (estado == 2) { // mesma coisa que o de cima, mudando apenas a ordem
    for (int i = 0; i < 3; i++) {
      if (digitalRead(botao1) == LOW) {
        estado = 2;
      }
      else if (digitalRead(botao2) == LOW) {
        estado = 1;
      }
      digitalWrite(ledarray[ordem2[i]], HIGH);
      delay(300);
      digitalWrite(ledarray[ordem2[i]], LOW);
    }
  }
}
