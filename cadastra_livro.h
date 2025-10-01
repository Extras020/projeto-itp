#ifndef cadastra_livro_h
#define cadastra_livro_h

#define MAX 100

typedef struct{
    char nome[MAX];
    char autor[MAX];
    int qnt;
}Livro;

void cadastra_livro(Livro *x, Livro acervo[]);

#endif // cadastra_livro_h
