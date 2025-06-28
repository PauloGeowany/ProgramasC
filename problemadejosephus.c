#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{
    char participante[50];
    char cpf[10];
    struct no *proxno;
}no;

typedef struct Lista{
    int qtd;
    no *inicio;
    no *final;

}lista

lista* novalista(){
    lista *novalista = malloc(sizeof(Lista));
    if(novalista == NULL){
        printf("ERRO AO ALOCAR MEMORIA");
        exit(1);
    }

    no *cabeça = malloc(sizeof(no));
    if (cabeça == NULL) {
         printf("ERRO AO ALOCAR MEMORIA");
        exit(1);
    }
    
cabeça->proxno = NULL;

    novalista->inicio = cabeça;
    novalista->final = cabeça;
    novalista->qtd = 0;

    return novalista;

}

void inserirnalista(lista *novalista, char nome, char cpf){

    no *novo = malloc(sizeof(no));
    if(novo == NULL){
        printf("ERRO AO ALOCAR MEMORIA");
        exit(1);
    }

    strcpy(novalista->final->participante, nome);
    novalista->final->cpf = cpf;

    novalista->final = novo;
    novalista->final->proxno = novo;
    novo->proxno = novalista->inicio->proxno;
    novalista->qtd++;

}

int main(){
    
}




