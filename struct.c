#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int main(){
    setlocale(LC_ALL, "Portuguese_Brazil");

   typedef struct _pessoa
    {
        char nome[100];
        int idade;
    }Pessoa;

    Pessoa Paulo;
    
    Paulo.idade = 21;
    strcpy(Paulo.nome, "Paulo");

    printf("%s\n", Paulo.nome);
    printf("%d\n", Paulo.idade);

}