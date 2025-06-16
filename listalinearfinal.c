#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int dado;
    struct no *proxno; 
}no;

typedef struct Lista
{
    int qtd;
    no *inicio;
    no *fim;
}lista;

lista CriaLista(){
    lista novalista;
    novalista.qtd = 0;
    novalista.inicio = NULL;
    novalista.fim = NULL;
    return novalista;;
}

void InsereEmLista(lista *novalista, int valor){
    no *novo = malloc(sizeof(no));
    if(novo == NULL){
        return;
    }
novo->dado = valor;

novo->proxno = NULL;
if (novalista->qtd == 0) {
    novalista->inicio = novo;
    novalista->fim = novo;
} else {
    novalista->fim->proxno = novo;
    novalista->fim = novo;
}
novalista->qtd++;
    
}

void exibelista(lista *novalista){
    if(novalista == NULL || novalista->inicio == NULL){
        printf("LISTA VAZIA\n");
        return;
    }
    no *proc = novalista->inicio;
    while (proc != NULL)
    {
        printf("%d\n", proc->dado);
        proc = proc->proxno;
    }
    printf("\n");
}

void proclista(lista *novalista, int n){
    int c = 0;
    if(novalista == NULL || novalista->inicio == NULL){
        printf("LISTA VAZIA\n");
        return;
    }
    no *proc = novalista->inicio;
    while(proc != NULL){
        if(proc->dado == n){
            printf("ELEMENTO ESTÁ NA POSICAO %d", c);
            c++;
            return;
            break;
        }
        //printf("ELEMENTO NAO ENCONTRADO");
    }
}

lista RemoveUltimoNo(lista *novalista){

}

int main(){
    int op = -1;
    int el;
    lista Newlist = CriaLista();

    while (op != 0)
    {
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
    Newlist.qtd = 0;
    Newlist.inicio = NULL;
    Newlist.fim = NULL;
    break;

    case 2:   
        puts("Digite o elemento a ser inserido: ");
        scanf("%d", &el);
        InsereEmLista(&Newlist, el);
        break;
    
    case 3:
        exibelista(&Newlist);
        break;
<<<<<<< HEAD

    case 4:
        puts("Insita o elemento a ser procurado: ");
        scanf("%d", &el);
        proclista(&Newlist, el);
        }

    } 

}
=======
    }
>>>>>>> a877e5d43efb22a2f310038f74ffa401e6127c1a

    
  }

}
