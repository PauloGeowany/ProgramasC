#include <stdio.h>
#include <stdlib.h>

int main(){
    int op, val, proc;
    int tam = 0;
    int achado = 0;

    int *vet = calloc(tam,sizeof(int));
    while(op != 0){
        puts("-----------------------------");
        puts("SELECIONE A OPERACAO DESEJADA");
        puts("-----------------------------");
        puts("0) Encerrar programa");
        puts("1) Criar uma lista vazia");  
        puts("2) Inserir um nó na lista");
        puts("3) Exibir vetor");
        puts("4) Pesquisar um item na lista");
        puts("5) Remover ultimo nó da lista");
        puts("6) Inserir ultimo nó na lista");
        puts("7) Realizar pesquisa binária");
        puts("8) Remover nó ordenadamente da lista");
        puts("9) Remover o n-ésimo termo da lista");    

        printf("OP: ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            free(vet);
            vet = NULL;
            tam = 0;
            break;

        case 2:
            printf("Insira o valor a ser adicionado ao vetor: ");
            scanf("%d", &val);
            tam++;
            vet = realloc(vet, tam * sizeof(int));
            vet[tam-1] = val;
            break;

        case 3:
            puts("VALORES DO VETOR: ");
            for(int c=0; c < tam; c++){
                printf("%d\n", vet[c]);
                
            }
            printf("\n");
            break;

        case 4:
            printf("Insira o valor a ser procurado: ");
            scanf("%d", &proc);
            for(int c = 0; c < tam; c++){
                if (vet[c] == proc)
                {
                    printf("O valor está na posicao %d\n", c);
                    achado = 1;
                }
                if (achado == 0)
                {
                    puts("VALOR NAO ENCONTRADO");
                }
                
                
            }
        
        }
    }
}
