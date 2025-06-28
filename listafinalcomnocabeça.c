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

lista* CriaLista() {
    lista *novalista = malloc(sizeof(lista));
    if (novalista == NULL) {
        printf("Erro ao alocar lista\n");
        exit(1);
    }

    no *cabeca = malloc(sizeof(no));
    if (cabeca == NULL) {
        printf("Erro ao alocar nó cabeça\n");
        exit(1);
    }

    cabeca->proxno = NULL;

    novalista->inicio = cabeca;
    novalista->fim = cabeca;
    novalista->qtd = 0;

    return novalista;
}

void InsereEmLista(lista *novalista, int valor) {
    no *novo = malloc(sizeof(no));
    if (novo == NULL) return;

    novo->dado = valor;
    novo->proxno = NULL;

    novalista->fim->proxno = novo;
    novalista->fim = novo;
    novalista->qtd++;
}

void exibelista(lista *novalista) {
    if (novalista->inicio->proxno == NULL) {
        printf("LISTA VAZIA\n");
        return;
    }

    no *proc = novalista->inicio->proxno;
    while (proc != NULL) {
        printf("%d\n", proc->dado);
        proc = proc->proxno;
    }
    printf("\n");
}

void removeultimono(lista *novalista) {
    if (novalista->inicio->proxno == NULL) {
        printf("LISTA VAZIA\n");
        return;
    }

    no *atual = novalista->inicio;
    while (atual->proxno->proxno != NULL) {
        atual = atual->proxno;
    }

    printf("Removido: %d\n", atual->proxno->dado);
    free(atual->proxno);
    atual->proxno = NULL;
    novalista->fim = atual;
    novalista->qtd--;
}

void proclista(lista *novalista, int n) {
    int pos = 0;
    no *proc = novalista->inicio->proxno;

    if (proc == NULL) {
        printf("LISTA VAZIA\n");
        return;
    }

    while (proc != NULL) {
        if (proc->dado == n) {
            printf("ELEMENTO SE ENCONTRA NA POSICAO %d\n", pos);
            return;
        }
        proc = proc->proxno;
        pos++;
    }

    printf("ELEMENTO NAO ENCONTRADO\n");
}

int RemoveElemento(lista *novalista, int valor) {
    no *anterior = novalista->inicio;
    no *atual = anterior->proxno;

    while (atual != NULL) {
        if (atual->dado == valor) {
            anterior->proxno = atual->proxno;
            if (novalista->fim == atual) {
                novalista->fim = anterior;
            }
            free(atual);
            novalista->qtd--;
            return 1;
        }
        anterior = atual;
        atual = atual->proxno;
    }
    return 0;
}

int main() {
    int op = -1, el;
    lista *Newlist = CriaLista();  // ponteiro agora

    while (op != 0) {
        puts("-----------------------------");
        puts("SELECIONE A OPERACAO DESEJADA");
        puts("-----------------------------");
        puts("0) Encerrar programa");
        puts("1) Criar uma lista vazia");  
        puts("2) Inserir um nó na lista");
        puts("3) Exibir vetor");
        puts("4) Pesquisar um item na lista");
        puts("5) Remover ultimo nó da lista");
        puts("6) Remover um elemento específico");

        printf("OP: ");
        scanf("%d", &op);

        switch (op) {
        case 1:
            free(Newlist);
            Newlist = CriaLista();
            break;

        case 2:
            printf("Digite o elemento a ser inserido: ");
            scanf("%d", &el);
            InsereEmLista(Newlist, el);
            break;

        case 3:
            exibelista(Newlist);
            break;

        case 4:
            printf("Insira o elemento a ser procurado: ");
            scanf("%d", &el);
            proclista(Newlist, el);
            break;

        case 5:
            removeultimono(Newlist);
            break;

        case 6:
            printf("Insira o elemento a ser removido: ");
            scanf("%d", &el);
            RemoveElemento(Newlist, el);
            break;
        }
    }

    // Libera todos os nós ao final
    no *atual = Newlist->inicio;
    while (atual != NULL) {
        no *prox = atual->proxno;
        free(atual);
        atual = prox;
    }
    free(Newlist);

    return 0;
}