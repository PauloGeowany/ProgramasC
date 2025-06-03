#include <stdio.h>
#include <stdlib.h>


int main() {
int tam, val, proc, ret ;
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
    printf("Informe o valor %d a ser adicionado no vetor: ", i+1);
    scanf("%d",&val);
    vet[i] = val;
}
    for(int i = 0; i < tam; i++){
    printf("%d\n", vet[i]);
}

printf("\n");
printf("Informe o valor a ser procurado: ");
scanf("%d",&proc);

for(int i = 0; i<tam; i++){
    if (vet[i] == proc)
    {
        printf("O valor esta na posicao %d\n", i);
        
    } 
    
}

printf("Insira a posicao do elemento a ser retirado: ");
scanf("%d", &ret);

if (ret >= 0 && ret < tam) {
    // Desloca todos os elementos à direita da posição para a esquerda
    for (int i = ret; i < tam ; i++) {
        vet[i] = vet[i + 1];
    }

    // Reduz o tamanho e realoca memória
    tam--;
    vet = realloc(vet, tam * sizeof(int));

    printf("Elemento removido com sucesso!\n");
} else {
    printf("Posição inválida!\n");
}

    for(int i = 0; i < tam; i++){
    printf("%d\n", vet[i]);

}

}
