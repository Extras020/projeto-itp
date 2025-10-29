#include <stdio.h>
#include <string.h>
#include "tipos.h"
#include "remove_nova_linha.h"
#include "converte_minusculas.h"

void cadastra_livro(Livro acervo[]){
    int i, pos;
    char isbn[14];
    for(i = 0; i < 1000; i++){
        if(acervo[i].nome[0] == '\0'){
            pos = i;
            break;
        }
    }
    printf("digite o nome do livro:\n");
    fgets(acervo[pos].nome, MAX, stdin);
    remove_nova_linha(acervo[pos].nome);
    converte_minusculas(acervo[pos].nome);
    printf("digite o nome do autor:\n");
    fgets(acervo[pos].autor, MAX, stdin);
    remove_nova_linha(acervo[pos].autor);
    converte_minusculas(acervo[pos].autor);
    printf("digite a quantidade:\n");
    scanf("%d", &acervo[pos].qnt);
    getchar();
    printf("digite o ISBN:\n");
    fgets(isbn, MAX, stdin);
    remove_nova_linha(isbn);
    for(i = 0; i < 1000; i++){
        if(strcmp(acervo[i].isbn, isbn) == 0){
            printf("livro ja cadastrado.\n");
            acervo[pos].nome[0] = '\0';
            acervo[pos].autor[0] = '\0';
            return;
        }
    }
    strcpy(acervo[pos].isbn, isbn);
}
