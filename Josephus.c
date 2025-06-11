//Aluno: Paulo Geowany Xavier De Brito Dias

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NOME 100

typedef struct Participante {
    char nome[MAX_NOME];
    char cpf[15];
    struct Participante *prox;
} Participante;

Participante *criaParticipante(char *nome, char *cpf) {
    Participante *novo = malloc(sizeof(Participante));
    strcpy(novo->nome, nome);
    strcpy(novo->cpf, cpf);
    novo->prox = NULL;
    return novo;
}

Participante *insere(Participante *fim, Participante *novo) {
    if (!fim) {
        novo->prox = novo;
        return novo;
    }
    novo->prox = fim->prox;
    fim->prox = novo;
    return novo;
}

void mostraParticipantes(Participante *fim) {
    if (!fim) return;
    Participante *atual = fim->prox;
    do {
        printf("- %s\n", atual->nome);
        atual = atual->prox;
    } while (atual != fim->prox);
}

int main() {
    int n, i;
    srand(time(NULL));

    printf("Quantos participantes? ");
    scanf("%d", &n);
    getchar(); 

    Participante *fim = NULL;

    for (i = 0; i < n; i++) {
        char nome[MAX_NOME], cpf[15];
        printf("Nome do participante %d: ", i + 1);
        fgets(nome, sizeof(nome), stdin);
        nome[strcspn(nome, "\n")] = '\0';
        printf("CPF do participante %d: ", i + 1);
        fgets(cpf, sizeof(cpf), stdin);
        cpf[strcspn(cpf, "\n")] = '\0';
        Participante *p = criaParticipante(nome, cpf);
        fim = insere(fim, p);
    }

    Participante *atual = fim->prox;
    while (atual != atual->prox) {
        int m = rand() % n + 1; 
        printf("\nNumero sorteado: %d\n", m);

        Participante *anterior = atual;
        for (i = 1; i < m; i++) {
            anterior = atual;
            atual = atual->prox;
        }

        printf("Eliminado: %s\n", atual->nome);
        anterior->prox = atual->prox;

        if (atual == fim) fim = anterior;

        free(atual);
        atual = anterior->prox;
        n--;

        printf("Participantes restantes:\n");
        mostraParticipantes(fim);
    }

    printf("\nVencedor: %s\nCPF: %s\n", atual->nome, atual->cpf);
    free(atual);

    return 0;
}