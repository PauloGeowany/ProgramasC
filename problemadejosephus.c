#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{
    char participante[50];
    int cpf;
    struct no *proxno;
}no;

typedef struct Lista{
    int qtd;
    no *inicio;
    no *final;

}lista;

lista* criarlista(){
    lista *novalista = malloc(sizeof(lista));
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

void inserirnalista(lista *novalista, char *nome, int cpf){

    no *novo = malloc(sizeof(no));
    if(novo == NULL){
        printf("ERRO AO ALOCAR MEMORIA");
        exit(1);
    }
    strcpy(novo->participante, nome);
    novo->cpf = cpf;

    novo->proxno = novalista->inicio->proxno;
    novalista->final->proxno = novo;
    novalista->final = novo;
    novalista->qtd++;
}


    int sortearnumero(int min, int max){
        if (min > max) {
        int temp = min;
        min = max;
        max = temp;
    }
    return min + rand() % (max - min + 1);

}

int main(){
    int n, cpf;
    char nome[50];
    printf("Digite o numero de participantes: ");
    scanf("%d", &n);

    lista *Newlist =  criarlista();

    for(int c=0; c<n; c++){
        printf("Digite o nome do participante %d: ", c+1);
        scanf("%s", nome);
        printf("Digite o CPF do participante: ");
        scanf("%d", &cpf);
        inserirnalista(Newlist, nome, cpf);
    }

}
 
    







