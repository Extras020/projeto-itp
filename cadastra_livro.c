#include <stdio.h>
#include "cadastra_livro.h"

void cadastra_livro(Livro *x, Livro acervo[]){
    int i;
    printf("digite o nome do livro:\n");
    fgets(x->nome, MAX, stdin);
    printf("digite o nome do autor:\n");
    fgets(x->autor, MAX, stdin);
    printf("digite a quantidade:\n");
    scanf("%d", &x->qnt);
    getchar();
}
