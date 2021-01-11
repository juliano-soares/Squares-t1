#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
/* 
 * TRABALHO 1 - Squares
 * Nome: Juliano Leonardo Soares
 * Matricula: 201713854
 * Disciplina: Lógica e Algoritmo
 * Professor: Dr. Joaquim Assunção
 */

// Variavel global para a matriz
char matriz[7][7];

// Função para escrever o nome do GAME no menu inicial
void desenhaNomeGame() {
  int valor;
  for(int i = 0; i < 25; i++){
    printf("_");
  }
  printf("\n");
  printf("\n\tSQUARES\n");
  for(int i = 0; i < 25; i++){
    printf("_");
  }
  printf("\n\n");
  printf(" 1 - PLAY\n");
  printf(" 2 - INSTRUCAO\n");
  printf(" 3 - SAIR\n");
  printf("\n");
}

// Função para escrever as instruções no terminal
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

// Função que desenha a matriz durante o game
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

// função para mover as peças pela matriz
void movePeca(char peca) {
  // variaveis para mover a peça no eixoX e eixoY
  // y_atual e x_atual representam a posição atual da peça
  int eixoX, eixoY, y_atual, x_atual;
  printf ("Digite posição da peca:\nEixo X(Vertical):\n");
  scanf("%d", &eixoX); // faz a leitura da posição para mover no eixoX
  printf ("Eixo Y(horizontal):\n");
  scanf("%d", &eixoY); // faz a leitura da posição para mover no eixoY 

  // Verifica se as novas posições estão dentro da matriz
  // caso contrario retorna
  if(eixoY >=7 || eixoY < 0 || eixoX >= 7 || eixoX < 0) {
    printf ("--> O valor dos eixo X ou Y devem ser entre 0 e 6\n");
    return;
  }

  // verifica se na nova posição a ser ocupada esta vazia
  if(matriz[eixoX][eixoY] != '+') {
    printf("\n--> A posição ja esta ocupada!!\n");
    return;
  }

  // pega a posição atual da peça a ser movida 
  // para futuraamente deixar com '+' no lugar
  for (int i = 0; i < 7; i++){
    for(int j = 0; j < 7; j++){
      if(matriz[i][j] == peca){
        y_atual = j;
        x_atual = i;
      }
    }
  }

  // Verifica a movimentação de A
  if(peca == 'A' && 
    ((eixoX == x_atual - 1 && eixoY == y_atual) ||
     (eixoX == x_atual && eixoY == y_atual + 1) || 
     (eixoX == x_atual && eixoY == y_atual - 1))
  ){
    matriz[eixoX][eixoY] = peca;
    matriz[x_atual][y_atual] = '+';
    return;
  }

  // Verifica a movimentação de L
  if(peca == 'L' && 
    ((eixoX == x_atual - 1 && eixoY == y_atual - 1) ||
    (eixoX == x_atual - 1 && eixoY == y_atual + 1) ||
    (eixoX == x_atual + 1 && eixoY == y_atual - 1) ||
    (eixoX == x_atual + 1 && eixoY == y_atual + 1))  
  ){
    matriz[eixoX][eixoY] = peca;
    matriz[x_atual][y_atual] = '+';
    return;
  }
  
  // Verifica a movimentação de M
  if(peca == 'M' && (
    (eixoX == x_atual + 2 && eixoY == y_atual) ||
    (eixoX == x_atual - 2 && eixoY == y_atual) ||
    (eixoX == x_atual && eixoY == y_atual + 2) ||
    (eixoX == x_atual && eixoY == y_atual - 2)
  )){
    matriz[eixoX][eixoY] = peca;
    matriz[x_atual][y_atual] = '+';
    return;
  }

  // Verifica a movimentação de K ou k
  if((peca == 'k'|| peca == 'K') &&
    ((eixoX == x_atual - 3 && eixoY == y_atual - 3) ||
    (eixoX == x_atual - 3 && eixoY == y_atual + 3) ||
    (eixoX == x_atual - 3 && eixoY == y_atual) ||
    (eixoY == y_atual - 3 && eixoX == x_atual) ||
    (eixoY == y_atual + 3 && eixoX == x_atual)) 
  ){
    matriz[eixoX][eixoY] = peca;
    matriz[x_atual][y_atual] = '+';
    return;
  }

  // se não entrou em nenhuma das movimentação o movimento está errado
  printf("\nMovimento errado para '%c'\n\n", peca);
  return;  
}

// função para iniciar as peças nas posições corretas
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

// função que inicia o Game
void iniciaGame() {
  char valor = ' '; // peça a ser movida
  while(true){ // enquanto true o game executa, até que o 0 é digitado e retorna para o menu
    desenhaMatriz(matriz);
    printf ("\nDigite a peça que deseja mover:\n(K, A, L, M, k)\n");
    setbuf(stdin, NULL); // limpar buffer
    scanf("%c", &valor);
    switch(valor)// escolha da peça e movimenta
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
      default:
        printf ("\n--> Valor invalido!\nObs: as letras devem ser maiusculas\nO K tem maiuscula e minuscula e sao pecas diferentes com movimentos iguais.\n");
        break;
    }
  }
}

// função para desenhar o menu
void desenhaMenuGame() {
  int opcao = 0; // opção para escolha no menu
  while(true){
    desenhaNomeGame(); // chama para desenhar o nome do game
    printf ("Digite uma opção: \n");
    scanf("%d", &opcao);
    switch(opcao) // opção para escolha no menu
    {
      case 1 :
        iniciaVariaveis(); // chama para iniciar as variaveis
        iniciaGame(); // inicia o game
        break;
      case 2 :
        mostraInstrucoes(); // chama descreve instruções
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
  desenhaMenuGame(); // chama a função para desenhar o menu
  return 0;
}