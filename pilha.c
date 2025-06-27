#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no
{
    char nome[30];
    float pesoAt;
    float altAt;
    struct no *proxno;
}no;


typedef struct pilha
{
    no *topo;
    int tamanho;
}pilha;

pilha *CriaPilha(){
    pilha *pilha = malloc(sizeof(pilha));
    pilha->topo = NULL;
    pilha->tamanho = 0; 
    return pilha;
}

void push(pilha *p, char *nome, float pesoAt, float altAt){
    no *novo = malloc(sizeof(no));
    if (novo == NULL)
    {
        printf("Problema em alocar mamoria");
        return;
    }
    strcpy(novo->nome, nome);
    novo->pesoAt = pesoAt;
    novo->altAt = altAt;
    novo->proxno = p->topo;
    p->topo = novo;
    p->tamanho++;
    
}

int main(){
    pilha *p = CriaPilha(); 
    push(p, "Paulo", 50.0, 1.76);
    printf("%s", p->topo->nome);
}
