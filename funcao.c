#include <stdio.h>

int soma(int a,int b){
    int soma = a+b;
    return soma;
}

int main(){
    int a,b;
   printf("Insira o numero a: "); 
    scanf("%d", &a);
   printf("Insira o numero b: "); 
    scanf("%d", &b);

    int resultado = soma(a,b);
    printf("A soma entre a e b eh %d\n", resultado);
    puts("FIM");
}