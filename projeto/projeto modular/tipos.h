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
    char isbn[14];
    int qnt;
}Livro;

typedef struct{
    char isbn[14];
    char cpf[MAX];
}Emprestimos;

#endif // TIPOS_H
