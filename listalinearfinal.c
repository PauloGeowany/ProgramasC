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
void conferelistavazia(lista *novalista){
    if(novalista == NULL || novalista->inicio == NULL){
        printf("LISTA VAZIA\n");
        return;
    }
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
    conferelistavazia(novalista);
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
    int achou = 0;
    conferelistavazia(novalista);
    no *proc = novalista->inicio;
    while(proc != NULL){
        if(proc->dado == n){
            printf("ELEMENTO SE ENCONTRA NA POSICAO %d\n", c);
            achou = 1;
            break;  
        }else{
            proc = proc->proxno; 
            c++;
            continue;
        }
        
    }
    if (!achou)
    {
        puts("ELEMENTO NAO ENCONTRADO");
    } 
}

void removeultimono(lista *novalista){
    conferelistavazia(novalista);
    no *proc = novalista->inicio;

    //Caso haja um unico no:
    if(proc->proxno == NULL){
    printf("Removido: %d\n", proc->dado);
    free(proc);
    novalista->inicio = NULL;
    novalista->fim = NULL;
    novalista->qtd = 0;
    }
    while (proc->proxno->proxno != NULL)
    {
        proc = proc->proxno;
    }
    printf("Removido: %d\n", proc->proxno->dado);
    free(proc->proxno);          // libera o último nó
    proc->proxno = NULL;         // corta a ligação com o último
    novalista->fim = proc;       // atualiza o ponteiro fim
    novalista->qtd--;
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


    case 4:
        printf("Insita o elemento a ser procurado: ");
        scanf("%d", &el);
        proclista(&Newlist, el);
        break;

    case 5:
        removeultimono(&Newlist);
        break;
        }

    } 

}
