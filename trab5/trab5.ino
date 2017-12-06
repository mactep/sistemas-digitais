// Define as portas dos segmentos
int unidade = 0;
int dezena = 0;
int catodo_unidade = 9; // portas responsáveis por multiplexar os displays
int catodo_dezena = 10;
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
  pinMode(catodo_unidade, OUTPUT);
  pinMode(catodo_dezena, OUTPUT);
  for (int i = 0; i < 7; i++) {
    pinMode(segmentos[i], OUTPUT); // Define as portas contidas no vetor segmentos como saida
  }
}

void loop() {
  if (unidade == 9) {
    unidade = 0;
    dezena += 1;
  } else if (dezena == 9 && unidade == 9) {
    unidade = 0;
    dezena = 0;
  } else {
    unidade += 1;
  }
  digitalWrite(catodo_unidade, HIGH);
  digitalWrite(catodo_dezena, LOW);
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentos[i], numeros[unidade][i]);
  }
  delay(15);
  digitalWrite(catodo_unidade, LOW);
  digitalWrite(catodo_dezena, HIGH);
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentos[i], numeros[dezena][i]);
  }
  delay(15);
}

