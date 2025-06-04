#include <stdio.h>
#include <stdlib.h>

int main() {
int var = 15;
int *ptr = &var;
float var2 = 15.5;
printf("O conteudo de var eh: %d\n",var);
printf("O endereco de var eh: %p\n", &var);
printf("Conteudo apontado por ptr: %d\n", *ptr);
printf("Endereco do ponteiro eh: %p\n", &ptr);
printf("tamanho de ptr eh: %zu\n", sizeof(ptr));
}