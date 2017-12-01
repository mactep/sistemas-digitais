// Define as portas dos segmentos
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
  for (int i = 0; i < 7; i++) {
    pinMode(segmentos[i], OUTPUT); // Define as portas contidas no vetor segmentos como saida
  }
}

void loop() {
  // Loop que percorre as linhas da matriz (representa os dígitos e sua sequência de segmentos)
  for (int i = 0; i < 10; i++) {
    // Loop que percorre as colunas da matriz, associando os dados níveis (1 ou 0) às portas contidas no vetor segmentos
    for (int j = 0; j < 7; j++) {
      // O funcinamento é o seguinte:
      // i é o contador para as linhas da matriz.
      // j é o contador para colunas.
      // O loop mais externo vai percorrer os dígitos do vetor números.
      // O loop interno vai ser responsável por associar os níveis contidos em um dado vetor de um dígito às portas
      // representadas no vetor segmentos, ou seja, a mesma "posição" j dos vetores será acionada por vez.
      // O digitalWrite é pradrão, joga um nível em uma porta, sendo o nível e a porta definidos no funcionamento anterior.
      digitalWrite(segmentos[j], numeros[i][j]);
    }
  delay(1000);
  }
}
