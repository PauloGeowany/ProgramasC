#include <stdlib.h>
#include <stdio.h>

typedef struct no
{
    int dado;
    struct no *proxno;
}no;

typedef struct Pilha
{
    int qtd;
    no *topo;
}pilha;

pilha* criarpilha(){
    pilha *p = malloc(sizeof(pilha));
    if(!p){
        printf("ERRO AO ALOCAR MEMORIA");
        exit(1);
    }
    p->topo = NULL;
    p->qtd=0;
    return p;
}

void push(pilha *p, int valor){
    no *novo = malloc(sizeof(no));
    if(!novo){
        printf("ERRO AO ALOCAR MEMORIA");
        exit(1);
    }

    novo->dado = valor;
    novo->proxno = p->topo;
    p->topo = novo;
    p->qtd++;
}

int pop(pilha *p){
    if(!p  || p == NULL){
        printf("PILHA VAZIA!");
        exit(1);
    }
    no *remover = p->topo;
    int valor = remover->dado;
    p->topo = remover->proxno;
    free(remover);
    p->qtd--;
    return valor;
}

void exibepilha(pilha *p){
    no *percorre = p->topo;
    if(!p){
        printf("PILHA VAZIA!");
        exit(1);

}
    while(percorre !=NULL){
        printf("%d",percorre->dado);
        percorre = percorre->proxno;
    }
    
}

int main(){
    int n, resto;
    pilha *p = criarpilha();
    printf("Escolha um numero: ");
    scanf("%d",&n);

    while (n>0){
        resto = n % 2;
        push(p, resto);
        n = n/2;
    }
    printf("Forma  binaria: ");
    exibepilha(p);
    
}