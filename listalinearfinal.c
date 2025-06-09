#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese_Brazil");

    int op, val, proc, posret;
    int tam = 0;

    int *vet = calloc(tam,sizeof(int));
    while(op != 0){
        puts("-----------------------------");
        puts("SELECIONE A OPERACAO DESEJADA");
        puts("-----------------------------");
        puts("0) Encerrar programa");
        puts("1) Criar uma lista vazia");  
        puts("2) Inserir um n� na lista");
        puts("3) Exibir vetor");
        puts("4) Pesquisar um item na lista");
        puts("5) Remover n� da lista");
        puts("6) Inserir ultimo n� na lista");
        puts("7) Realizar pesquisa bin�ria");
        puts("8) Remover n� ordenadamente da lista");
        puts("9) Remover o n-�simo termo da lista");    

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
            int achado = 0;
            printf("Insira o valor a ser procurado: ");
            scanf("%d", &proc);
            for(int c = 0; c < tam; c++){
                if (vet[c] == proc)
                {
                    printf("O valor est� na posicao %d\n", c);
                    achado = 1;
                }
                
            }    
                if (achado == 0)
                {
                    puts("VALOR NAO ENCONTRADO");
                }
                break;

        case 5:
            printf("Inira a posi��o do elemento a ser retirado: ");
            scanf("%d", &posret);

            if (posret >=0 && posret < tam)  {
               for(int c = posret; c < tam; c++){
                vet[c] = vet[c+1];
            }
            tam--;
            vet = realloc(vet, tam*sizeof(int));

            } else{
                puts("POSI��O INV�LIDA!");
            }
            break;
        }
    }
}
