#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado;
    struct no *proxno; 
} no;

typedef struct Lista {
    int qtd;
    no *inicio;
    no *fim;
} lista;

// Agora retorna ponteiro
lista* CriaLista() {
    lista *novalista = malloc(sizeof(lista));
    if (novalista == NULL) {
        printf("Erro ao alocar lista\n");
        exit(1);
    }
    novalista->qtd = 0;
    novalista->inicio = NULL;
    novalista->fim = NULL;
    return novalista;
}

void conferelistavazia(lista *novalista) {
    if (novalista == NULL || novalista->inicio == NULL) {
        printf("LISTA VAZIA\n");
    }
}

void InsereEmLista(lista *novalista, int valor) {
    no *novo = malloc(sizeof(no));
    if (novo == NULL) return;

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

void exibelista(lista *novalista) {
    conferelistavazia(novalista);
    no *proc = novalista->inicio;
    while (proc != NULL) {
        printf("%d\n", proc->dado);
        proc = proc->proxno;
    }
    printf("\n");
}

void proclista(lista *novalista, int n) {
    int c = 0, achou = 0;
    conferelistavazia(novalista);
    no *proc = novalista->inicio;
    while (proc != NULL) {
        if (proc->dado == n) {
            printf("ELEMENTO SE ENCONTRA NA POSICAO %d\n", c);
            achou = 1;
            break;
        }
        proc = proc->proxno;
        c++;
    }
    if (!achou)
        puts("ELEMENTO NAO ENCONTRADO");
}

void removeultimono(lista *novalista) {
    conferelistavazia(novalista);
    no *proc = novalista->inicio;

    if (proc == NULL) return;

    if (proc->proxno == NULL) {
        printf("Removido: %d\n", proc->dado);
        free(proc);
        novalista->inicio = NULL;
        novalista->fim = NULL;
        novalista->qtd = 0;
        return;
    }

    while (proc->proxno->proxno != NULL) {
        proc = proc->proxno;
    }

    printf("Removido: %d\n", proc->proxno->dado);
    free(proc->proxno);
    proc->proxno = NULL;
    novalista->fim = proc;
    novalista->qtd--;
}

int RemoveElemento(lista *novalista, int valor) {
    no *atual = novalista->inicio;
    no *anterior = NULL;

    while (atual != NULL) {
        if (atual->dado == valor) {
            if (novalista->inicio == novalista->fim) {
                novalista->inicio = NULL;
                novalista->fim = NULL;
            } else if (anterior == NULL) {
                novalista->inicio = atual->proxno;
            } else {
                anterior->proxno = atual->proxno;
                if (atual == novalista->fim)
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