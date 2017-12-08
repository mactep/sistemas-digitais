// Define as portas dos segmentos
int unidade = 0; // valores que representam o numero mostrado no display das unidades
int dezena = 0; // valores que representam o numero mostrado no display das dezenas
int catodo_unidade = 9; // portas responsáveis por multiplexar os displays
int catodo_dezena = 10; // portas responsáveis por multiplexar os displays
int a = 2;
int b = 3;
int c = 4;
int d = 5;
int e = 6;
int f = 7;
int g = 8;
int segmentos[7] = {a, b, c, d, e, f, g}; // Vetor contendo as portas referentes aos 7 segmentos
int numeros[10][7] = {
  { 1,1,1,1,1,1,0 },  // = Digito 0
  { 0,1,1,0,0,0,0 },  // = Digito 1
  { 1,1,0,1,1,0,1 },  // = Digito 2
  { 1,1,1,1,0,0,1 },  // = Digito 3
  { 0,1,1,0,0,1,1 },  // = Digito 4
  { 1,0,1,1,0,1,1 },  // = Digito 5
  { 1,0,1,1,1,1,1 },  // = Digito 6
  { 1,1,1,0,0,0,0 },  // = Digito 7
  { 1,1,1,1,1,1,1 },  // = Digito 8
  { 1,1,1,0,0,1,1 },  // = Digito 9
};

void setup() {
  // Define as portas contidas no vetor segmentos como saida
  pinMode(catodo_unidade, OUTPUT);
  pinMode(catodo_dezena, OUTPUT);
  for (int i = 0; i < 7; i++) {
    pinMode(segmentos[i], OUTPUT);
  }
}

void loop() {
  if (dezena == 9 && unidade == 9) { // checa se o contador atingiu 99, voltando a 0
    unidade = 0;
    dezena = 0;
  } else if (unidade == 9) { // checa se o contador atingiu 9 nas unidades, adicionando 1 a dezena
    unidade = 0;
    dezena += 1;
  } else { // incrementa o numero em 1
    unidade += 1;
  }
  for (int j = 0; j < 10; j++) { // faz o ciclo 10 vezes para dar tempo de ver (displays piscam rapido)
    digitalWrite(catodo_unidade, LOW); // habilita o display das unidades
    digitalWrite(catodo_dezena, HIGH); // desabilita o das dezenas
    for (int i = 0; i < 7; i++) {
      // configura os niveis nos segmentos do display das unidades para mostrar o numero armazenado na variavel unidade
      digitalWrite(segmentos[i], numeros[unidade][i]);
    }
    delay(10); // para por 10 segundos
    // faz o mesmo que o de cima, só que agora para as dezenas
    digitalWrite(catodo_unidade, HIGH);
    digitalWrite(catodo_dezena, LOW);
    for (int i = 0; i < 7; i++) {
      digitalWrite(segmentos[i], numeros[dezena][i]);
    }
    delay(10);
  }
}

