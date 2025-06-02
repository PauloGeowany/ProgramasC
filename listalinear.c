#include <stdio.h>
#include <stdlib.h>


int main() {
int tam, val, proc;
printf("Insira o tamanho do vetor: ");
scanf("%d", &tam);

int *vet = calloc(tam, sizeof(int));

if(vet == NULL){
    printf("ERRO AO ALOCAR MEMORIA\n");
} else {
    printf("MEMORIA ALOCADA COM SUCESSO!\n");
}

vet = realloc(vet, tam*(sizeof(int)));

for(int i = 0; i < tam; i++){
    printf("Informe o valor a ser adicionado no vetor: ");
    scanf("%d",&val);
    vet[i] = val;
}
    for(int i = 0; i < tam; i++){
    printf("%d\n", vet[i]);
}

printf("Informe o valor a ser procurado: ");
scanf("%d",proc);
}


