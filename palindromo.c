#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{
    char palavra[50];
    struct no *antno;
    struct no *proxno;
}no;

typedef struct Lista
{
   int qtd;
   no *inicio;
   no *fim; 
}lista;

lista* CriarLista(){
    lista *novalista = malloc(sizeof(lista));
    if (!novalista){
        printf("ERRO AO ALOCAR MEMORIA");
        exit(1);
}
    no *cabeça = malloc(sizeof(no));
    if(!cabeça){
        printf("ERRO AO ALOCAR MEMORIA");
        exit(1);
    }
    cabeça->proxno = NULL;
    cabeça->antno = NULL;
    novalista->inicio = cabeça;
    novalista->fim = cabeça;
    novalista->qtd = 0;

    return novalista;

    }

    void InsereLista(lista *l, char *palavra){
        no *novo = malloc(sizeof(no));
        if(!novo){
           printf("ERRO AO ALOCAR MEMORIA");
           exit(1); 
        }

        strcpy(novo->palavra, palavra);
        novo->antno = l->fim;
        novo->proxno = NULL;

        l->fim->proxno = novo;
        l->fim = novo;
        l->qtd++;
    }

    void ExibeLista(lista *l){
        no *aux = l->inicio->proxno;

        while(aux != NULL){
            printf("%s", aux->palavra);
            aux = aux->proxno;
        }
    }

    void ExibeListaInvertida(lista *l){
        no *aux = l->fim;
        
        while(aux != l->inicio){
            printf("%s", aux->palavra);
            aux = aux->antno;
        }
    }

    void EhPalindromo(lista *l) {
    no *esq = l->inicio->proxno;  // primeiro elemento real (após cabeça)
    no *dir = l->fim;

    while (esq != NULL && dir != NULL && esq != dir && dir->proxno != esq) {
        if (strcmp(esq->palavra, dir->palavra) != 0) {
            printf("Nao eh palindromo");  // não é palíndromo
        }
        esq = esq->proxno;
        dir = dir->antno;
    }

    printf("Eh palindromo");  // é palíndromo
}

        int main(){
    char frase[200];
    printf("Digite a frase: ");
    fgets(frase, sizeof(frase), stdin);
    frase[strcspn(frase, "\n")] = '\0'; // remove o '\n'

    lista *novalista = CriarLista();

    // Quebra a frase em palavras:
    char *token = strtok(frase, " ");
    while (token != NULL) {
        InsereLista(novalista, token);
        token = strtok(NULL, " ");
    }

    printf("\nFrase na ordem normal:\n");
    ExibeLista(novalista);

    printf("\nFrase invertida:\n");
    ExibeListaInvertida(novalista);
    printf("\n");

    EhPalindromo(novalista);

        }