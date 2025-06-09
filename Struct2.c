#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct _livro{
   char titulo[100];
   unsigned int num_paginas;
   float preco;
} Livro;

Livro *createlivro(const char *titulo, unsigned int num_paginas, float preco){
   Livro *livro = calloc(1, sizeof(Livro));

   strcpy(livro->titulo, titulo);
   livro->num_paginas = num_paginas;
   livro->preco = preco;

   return livro;
}

void print_livro(const Livro *livro){
   printf("Titulo: %s\n", livro->titulo);
   printf("Numero de paginas: %d\n", livro->num_paginas);
   printf("Preco: R$%.2f\n", livro->preco);
}

int main(){
   setlocale(LC_ALL, "Portuguese_Brazil");
   Livro *livro_harry = createlivro("Harry Potter", 350, 50.0);

   print_livro(livro_harry);
   
}