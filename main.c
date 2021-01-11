#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

char matriz[7][7];

void desenhaNomeGame() {
  int valor;
  for(int i = 0; i < 25; i++){
    printf("_");
  }
  printf("\n");
  printf("\n\tSQUARE\n");
  for(int i = 0; i < 25; i++){
    printf("_");
  }
  printf("\n\n");
  printf(" 1 - PLAY\n");
  printf(" 2 - INSTRUCAO\n");
  printf(" 3 - SAIR\n");
  printf("\n");
}

void mostraInstrucoes() {
  printf("\n");
  printf("\t INSTRUCOES \n");
  printf("As seguintes regras devem ser seguidas:\n");
  printf("- O tabuleiro do jogo e 7x7, onde o sinal de '+' representa uma casa vazia.\n");
  printf("- As pecas, representadas pelas respectivas letras, são: 'P', 'A', 'L', 'M', 'K'\n");
  printf("- “K” move até 3 casas para frente, ou diagonais da frente, ou lados.\n");
  printf("- O tabuleiro do jogo é 7x7, onde o sinal de “+” representa uma casa vazia.\n");
  printf("- A primeira linha de cada jogador possui a seguinte configuração: ('K','A','L','+','M','+','k').\n");
  printf("- Nenhuma peca pode ocupar o lugar de outra (aliada ou inimiga).\n");
  printf("- 'A' so move 1 casa para frente e para os lados.\n");
  printf("- 'L' so move 1 casa nas diagonais.\n");
  printf("- 'M' so move ate 2 casas para frente, ou para tras ou para os lados.\n");
  printf("- 'K' move ate 3 casas para frente, ou diagonais da frente, ou lados.\n");
  printf("- DIGITE A LETRO 'O' DURANTE A PARTIDA DO GAME PARA SAIR!!!\n");
  printf("\n");
}

void desenhaMatriz() {
  int i, j;
  printf ("\n");
  printf ("  0123456\n");
  for ( i=0; i<7; i++ ){
    printf ("%d ", i);
    for ( j=0; j<7; j++ )
    {
      printf ("%c", matriz[i][j]);
    }
    printf ("\n");
  }
}

void movePeca(char valor) {
  int eixoX, eixoY, y_atual, x_atual;
  printf ("Digite posição da peca:\nEixo X(Vertical):\n");
  scanf("%d", &eixoX);
  printf ("Eixo Y(horizontal):\n");
  scanf("%d", &eixoY);

  if(eixoY >=7 || eixoY < 0 || eixoX >= 7 || eixoX < 0) {
    printf ("--> O valor dos eixo X ou Y devem ser entre 0 e 6\n");
    return;
  }

  if(matriz[eixoX][eixoY] != '+') {
    printf("A posição ja esta ocupada!!\n");
    return;
  }

  for (int i = 0; i < 7; i++){
    for(int j = 0; j < 7; j++){
      if(matriz[i][j] == valor){
        y_atual = j;
        x_atual = i;
      }
    }
  }

  if(valor == 'A' && 
    ((eixoX == x_atual - 1 && eixoY == y_atual) ||
     (eixoX == x_atual && eixoY == y_atual + 1) || 
     (eixoX == x_atual && eixoY == y_atual - 1))
  ){
    matriz[eixoX][eixoY] = valor;
    matriz[x_atual][y_atual] = '+';
    return;
  }

  if(valor == 'L' && 
    (eixoX == x_atual - 1 && eixoY == y_atual - 1) ||
    (eixoX == x_atual - 1 && eixoY == y_atual + 1) ||
    (eixoX == x_atual + 1 && eixoY == y_atual - 1) ||
    (eixoX == x_atual + 1 && eixoY == y_atual + 1)  
  ){
    matriz[eixoX][eixoY] = valor;
    matriz[x_atual][y_atual] = '+';
    return;
  }
  
  if(valor == 'M' && 
    (eixoX == x_atual && eixoY == y_atual - 2) ||
    (eixoX == x_atual && eixoY == y_atual + 2) ||
    (eixoX == x_atual + 2 && eixoY == y_atual) ||
    (eixoX == x_atual + 2 && eixoY == y_atual)  
  ){
    matriz[eixoX][eixoY] = valor;
    matriz[x_atual][y_atual] = '+';
    return;
  }

  if((valor == 'k'|| valor == 'K') &&
    (eixoX == x_atual - 1 && eixoY == y_atual - 1) ||
    (eixoX == x_atual - 1 && eixoY == y_atual + 1) ||
    (eixoX == x_atual - 3 && eixoY == y_atual) ||
    (eixoY == y_atual - 3 && eixoX == x_atual) ||
    (eixoY == y_atual + 3 && eixoX == x_atual) 
  ){
    matriz[eixoX][eixoY] = valor;
    matriz[x_atual][y_atual] = '+';
    return;
  }

  printf("\nMovimento errado para '%c'\n\n", valor);
  
}

void iniciaVariaveis() {
  int i, j;
  for ( i=0; i<7; i++ ){
    for ( j=0; j<7; j++ ) {
      matriz[ i ][ j ] = '+';
    }
  }
  matriz[0][6] = 'Z';
  matriz[6][0] = 'K';
  matriz[6][1] = 'A';
  matriz[6][2] = 'L';
  matriz[6][4] = 'M';
  matriz[6][6] = 'k';
}

void iniciaGame() {
  char valor;
  while(true){
    desenhaMatriz(matriz);
    printf ("\nDigite a peça que deseja mover:\n(K, A, L, M, k)\n");
    getchar();
    scanf("%c", &valor);
    switch(valor)
    {
      case 'K' :  
        movePeca(valor);
        break;
      case 'A' :
        movePeca(valor);
        break;
      case 'L' :
        movePeca(valor);
        break;
      case 'M' : 
        movePeca(valor);
        break;
      case 'k' :
        movePeca(valor);
        break;
      case '0' : 
        return;
        break;
      default :
        printf ("Valor invalido!\nObs: as letras devem ser maiusculas\no K tem maiuscula e minuscula e sao pecas diferentes com movimentos iguais.\n");
    }
  }
}

void desenhaMenuGame() {
  int valor = 0;
  while(true){
    desenhaNomeGame();
    printf ("Digite uma opção: \n");
    scanf("%d", &valor);
    switch(valor)
    {
      case 1 :
        iniciaVariaveis();
        iniciaGame();
        break;
      case 2 :
        mostraInstrucoes();
        break;
      case 3 :
        return;
        break;
      default :
        printf ("Valor invalido!\n");
    }
  }
}

int main (void) { //Inicia menu inicial do game
  desenhaMenuGame();
  return 0;
}