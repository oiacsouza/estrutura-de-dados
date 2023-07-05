#include <stdio.h>
#include <stdlib.h>

// Criação da Estrutura
struct aluno {
    char nome[50];
    int matricula;
    float notas[3];
};

// Função para inserir dados da matricula do aluno
void inserirNomeMatricula(struct aluno *alunos, int *qtdAlunos) {
    if (*qtdAlunos >= 5) {
        printf("Numero maximo de alunos atingido.\n");
        return;
    }
    printf("Digite o nome do aluno: ");
    scanf(" %49[^\n]", alunos[*qtdAlunos].nome);
    printf("Digite a matricula do aluno: ");
    scanf("%d", &alunos[*qtdAlunos].matricula);
    (*qtdAlunos)++;
    printf("Aluno adicionado com sucesso.\n");
}

// Função para inserir as notas do aluno
void inserirNota(struct aluno *alunos, int qtdAlunos) {
    int matricula, i;
    float nota;
    printf("Digite a matricula do aluno: ");
    scanf("%d", &matricula);
    for (i = 0; i < qtdAlunos; i++) {
        if (alunos[i].matricula == matricula) {
            printf("Digite a primeira nota do aluno: ");
            scanf("%f", &alunos[i].notas[0]);
            printf("Digite a segunda nota do aluno: ");
            scanf("%f", &alunos[i].notas[1]);
            printf("Digite a terceira nota do aluno: ");
            scanf("%f", &alunos[i].notas[2]);
            printf("Numero maximo de notas atingido.\n");
            return;
        }
    }
    printf("Aluno nao encontrado.\n");
}

// Função para imprimir alguns dos dados do aluno
void listarNomeMatricula(struct aluno *alunos, int qtdAlunos) {
    int i;
    for (i = 0; i < qtdAlunos; i++) {
        printf("Nome: %s, Matricula: %d\n", alunos[i].nome, alunos[i].matricula);
    }
}

// Função para imprimir a media do aluno
void listarNomeMediaNotas(struct aluno *alunos, int qtdAlunos) {
    int i, j;
    for (i = 0; i < qtdAlunos; i++) {
        float soma = 0;
        for (j = 0; j < 3; j++) {
            soma += alunos[i].notas[j];
        }
        float media = soma / 3;
        printf("Nome: %s, Media das Notas: %.2f\n", alunos[i].nome, media);
    }
}

// Função principal do programa
int main() {
    struct aluno alunos[5];
    int qtdAlunos = 0;
    int opcao;
    //Lista as opções
    do {
        printf("Escolha uma opcao:\n");
        printf("1 - Inserir nome e matricula\n");
        printf("2 - Inserir nota\n");
        printf("3 - Listar todos os nomes e sua respectiva matricula\n");
        printf("4 - Listar todos os nomes e sua respectiva media das notas\n");
        printf("0 - Sair\n");
        scanf("%d", &opcao);
        //Chama as funções
        switch (opcao) {
            case 1:
                inserirNomeMatricula(alunos, &qtdAlunos);
                break;
            case 2:
                inserirNota(alunos, qtdAlunos);
                break;
            case 3:
                listarNomeMatricula(alunos, qtdAlunos);
                break;
            case 4:
                listarNomeMediaNotas(alunos, qtdAlunos);
                break;
            case 0:
                printf("Encerrando...");
                break;
        }
    }while (opcao != 0);
}
