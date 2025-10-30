#ifndef TIPOS_H
#define TIPOS_H

#define MAX 100

typedef struct{
    char nome[MAX];
    char cpf[MAX];
    int emprestimos;
}Usuario;

typedef struct{
    char nome[MAX];
    char autor[MAX];
    char isbn[MAX];
    int qnt;
}Livro;

typedef struct{
    char isbn[MAX];
    char cpf[MAX];
    char nome_usuario[MAX];
    char nome_livro[MAX];
}Emprestimos;

#endif // TIPOS_H
