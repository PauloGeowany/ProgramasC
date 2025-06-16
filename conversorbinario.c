#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *prox;
} No;

void push(No **topo, int valor) {
    No *novo = (No *)malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = *topo;
    *topo = novo;
}

int pop(No **topo) {
    if (*topo == NULL) {
        printf("Pilha vazia!\n");
        return -1;
    }
    No *temp = *topo;
    int valor = temp->valor;
    *topo = temp->prox;
    free(temp);
    return valor;
}

void converte(int numero) {
    if (numero == 0) {
        printf("0");
        return;
    }

    No *pilha = NULL;
    while (numero > 0) {
        push(&pilha, numero % 2);
        numero /= 2;
    }

    while (pilha != NULL) {
        printf("%d", pop(&pilha));
    }
}

int main() {
    int numero;
    printf("Digite um numero decimal: ");
    scanf("%d", &numero);

    printf("Representacao binaria: ");
    converte(numero);
    printf("\n");

    return 0;
}
