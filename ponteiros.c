#include <stdio.h>
#include <stdlib.h>

int main() {
int var = 15;
int *ptr = &var;
int *ptr2 = NULL;
float var2 = 15.5;
short var3 = 2;
printf("O conteudo de var eh: %d\n",var);
printf("O endereco de var eh: %p\n", &var);
printf("O endereco de var eh: %p\n", ptr);
printf("Conteudo apontado por ptr: %d\n", *ptr);
printf("Endereco do ponteiro eh: %p\n", &ptr);
printf("tamanho de ptr eh: %ld\n", sizeof(ptr));
printf("Endereco armazenado por ptr2 eh: %d\n", ptr2);
printf("O conteudo de ptr2 eh: %d\n", *ptr2);
printf("tamanho de var eh: %zu\n", sizeof(var3));

}