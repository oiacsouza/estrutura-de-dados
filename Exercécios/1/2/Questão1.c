#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Criação do tipo do elemento da lista
typedef struct No {
    int dado;
    struct No* prox;
} No;

// Criação do tipo da lista
typedef struct {
    No* inicio;
} Lista;

// Função para inicializar a lista
void inicializarLista(Lista* lista) {
    lista->inicio = NULL;
}

// Função para inserir no final da lista
void inserirFinal(Lista* lista, int dado, FILE* saida) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->dado = dado;
    novoNo->prox = NULL;

    // Verifica se a lista está vazia
    if (lista->inicio == NULL) {
        lista->inicio = novoNo;
        
        // Retorna no arquivo de saida
        saida = fopen("arq_de_saida.txt", "w");
        fprintf(saida, "0\n");
        fclose(saida);
    } else {
        No* atual = lista->inicio;
        
        // Verifica se o dado já existe na lista
        while (atual != NULL) {
            if (atual->dado == dado) {
                
                // Se existir, retorna erro no arquivo de saida
                saida = fopen("arq_de_saida.txt", "a");
                fprintf(saida, "E\n");
                fprintf(saida, "0\n");
                fclose(saida);
                free(novoNo); // Libera o nó que seria inserido
                return;
            }
            atual = atual->prox;
        }

        // Insere o novo nó no final da lista
        atual = lista->inicio;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novoNo;
        
        // Retorna no arquivo de saida
        saida = fopen("arq_de_saida.txt", "a");
        fprintf(saida, "0\n");
        fclose(saida);
    }
}

// Função para remover dado da lista
void removerDado(Lista* lista, int dado, FILE* saida) {
    No* atual = lista->inicio;
    No* anterior = NULL;

    // Percorre a lista em busca do dado a ser removido
    while (atual != NULL) {
        if (atual->dado == dado) {
            // Verifica se o nó a ser removido é o primeiro da lista
            if (anterior == NULL) {
                lista->inicio = atual->prox;
            } else {
                anterior->prox = atual->prox;
            }
            free(atual); // Libera o nó da memória
            
            // Retorna no arquivo de saida
            saida = fopen("arq_de_saida.txt", "a");
            fprintf(saida, "0\n");
            fclose(saida);
            return;
        }

        anterior = atual;
        atual = atual->prox;
    }
    
    // Se o dado não existir na lista, retorna erro no arquivo de saida
    saida = fopen("arq_de_saida.txt", "a");
    fprintf(saida, "E\n");
    fprintf(saida, "0\n");
    fclose(saida);
}

// Função para imprimir no arquivo de saida
void imprimirLista(Lista* lista, FILE* saida) {
    No* atual = lista->inicio;
    saida = fopen("arq_de_saida.txt", "a");
    
    while (atual != NULL) {
        fprintf(saida,"%d ", atual->dado);
        atual = atual->prox;
    }
    fprintf(saida,"\n");
    fclose(saida);
}

// Função Main
int main() {
    
    // Cria lista
    Lista lista;
    inicializarLista(&lista);
    
    // Cria variaveis de controle e para os arquivos de entrada e saida
    FILE* arquivo;
    FILE* saida;
    char texto[100];
    char oper;
    int valor;
    
    // Abre o arquivo de entrada e realiza as funções linha por linha
    arquivo = fopen("arq_com_as_operacoes.txt", "r");
    while (fgets(texto, sizeof(texto), arquivo) != 0) {
        oper = texto[0];
        valor = atoi(texto + 1);
        if (oper == '+'){
            inserirFinal(&lista, valor, saida);
        } else if (oper == '-'){
            removerDado(&lista, valor, saida);
        } else if (oper == '='){
            imprimirLista(&lista, saida);
        } else {
            valor = atoi(texto);
            inserirFinal(&lista, valor, saida);
        }
    }
    return 0;
}
