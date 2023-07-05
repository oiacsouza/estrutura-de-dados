#include <stdio.h>
#include <stdlib.h>
 
// Criação da Estrutura
struct jogador {
  char nome[50];
  int jogo;
  int assistencia;
  int gols;
};

// Criando o TAD
typedef struct jogador Jogador;

// Declarando função para inserir dados do Jogador
void inserir (Jogador *j);
// Declarando função para imprimir dados do Jogador
void imprimir (Jogador *j);
// Declarando função para identificar a qualidade do Jogador
void ehBom (Jogador *j);
// Declarando função para imprimir a média de gol/jogo do Jogador
float mediaGols (Jogador *j);
// Declarando função para imprimir a média de assistencia/jogo do Jogador
float mediaAssistencia (Jogador *j);

// Função para inserir dados do Jogador
void inserir (Jogador *j){
  printf("Digite o nome do jogador: ");
  scanf("%s", j->nome);
  printf("Digite a quantidade de jogos: ");
  scanf("%d", &j->jogo);
  printf("Digite a quantidade de gols: ");
  scanf("%d", &j->gols);
  printf("Digite a quantidade de assistencia: ");
  scanf("%d", &j->assistencia);
}
// Função para imprimir dados do Jogador
void imprimir (Jogador *j){
  printf("Nome do jogador: %s \n", j->nome);
  printf("Jogos: %d \n", j->jogo);
  printf("Gols: %d \n", j->gols);
  printf("Assistência: %d \n", j->assistencia);
}
// Função para identificar a qualidade do Jogador
void ehBom (Jogador *j){
  if(mediaGols(j) >= 1 && mediaAssistencia(j) >= 2)
    printf("O jogador eh bom");
  else
    printf("O jogador não eh bom");
}
// Função para imprimir a média de gol/jogo do Jogador
float mediaGols (Jogador *j){
  float media = j->gols/j->jogo;
  return media;
}
// Função para imprimir a média de assistencia/jogo do Jogador
float mediaAssistencia (Jogador *j){
  float media = j->assistencia/j->jogo;
  return media;
}

int main (void) {
    Jogador *j;
    j = malloc(sizeof(Jogador));
    printf("------ Painel de Jogador ------\n");
    inserir(j);
    imprimir(j);
    ehBom(j);
}
