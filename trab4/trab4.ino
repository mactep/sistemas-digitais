// Defini as portas dos segmentos
int a = 2;
int b = 3;
int c = 4;
int d = 5;
int e = 6;
int f = 7;
int g = 8;
int segmentos[7] = {a, b, c, d, e, f, g};
int numeros[10][7] = {
  {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, LOW},
  {LOW, HIGH, HIGH, LOW, LOW, LOW, LOW},
  {HIGH, HIGH, LOW, HIGH, HIGH, LOW, HIGH},
  {HIGH, HIGH, HIGH, HIGH, LOW, LOW, HIGH},
  {LOW, HIGH, HIGH, LOW, LOW, HIGH, HIGH},
  {HIGH, LOW, HIGH, HIGH, LOW, HIGH, HIGH},
  {HIGH, LOW, HIGH, HIGH, HIGH, HIGH, HIGH},
  {HIGH, HIGH, HIGH, LOW, LOW, LOW, LOW},
  {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH},
  {HIGH, HIGH, HIGH, HIGH, LOW, HIGH, HIGH},
  {HIGH, HIGH, HIGH, LOW, HIGH, HIGH, HIGH},
  {LOW, LOW, HIGH, HIGH, HIGH, HIGH, HIGH},
  {HIGH, LOW, LOW, HIGH, HIGH, HIGH, LOW},
  {LOW, HIGH, HIGH, HIGH, HIGH, LOW, HIGH},
  {HIGH, LOW, LOW, HIGH, HIGH, HIGH, HIGH},
  {HIGH, LOW, LOW, LOW, HIGH, HIGH, HIGH},
  {LOW, LOW, LOW, LOW, LOW, LOW, LOW}
};
/*
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
*/

void setup() {
  pinMode(a, OUTPUT); // define as portas como saida
  pinMode(b, OUTPUT); // define as portas como saida
  pinMode(c, OUTPUT); // define as portas como saida
  pinMode(d, OUTPUT); // define as portas como saida
  pinMode(e, OUTPUT); // define as portas como saida
  pinMode(f, OUTPUT); // define as portas como saida
  pinMode(g, OUTPUT); // define as portas como saida
}

void loop() {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 7; j++) {
      segmentos[j] = numeros[i][j];
    }
  delay(100);
  }
}
