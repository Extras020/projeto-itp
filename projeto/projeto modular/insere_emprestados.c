#include <stdio.h>
#include <string.h>
#include "tipos.h"

void insere_emprestados(Emprestimos pegos[], char livro[], char cpf[], Livro acervo[]){
    int i, pos;
    for(i = 0; i < 1000; i++){
        if(pegos[i].cpf[0] == '\0'){
            pos = i;
            break;
        }
    }
    for(i = 0; i < 1000; i++){
        if(strcmp(livro, acervo[i].nome) == 0){
            strcpy(pegos[pos].isbn, acervo[i].isbn);
            strcpy(pegos[pos].cpf, cpf);
            return;
        }
    }
}
