#include <stdio.h>
#include <string.h>
#include "tipos.h"
#include "cadastra_usuario.h"
#include "cadastra_livro.h"
#include "pega_emprestado.h"

void cadastra_usuario(Usuario cadastrados[]);
void cadastra_livro(Livro acervo[]);
void pega_emprestado(Livro acervo[], Usuario cadastrados[], Emprestimos pegos[]);
void insere_emprestados(Emprestimos pegos[], char livro[], char cpf[], Livro acervo[]);
void devolucao(Livro acervo[], Usuario cadastrados[]);
void remove_nova_linha(char string[]);

int main(){
    int escolha;
    Livro acervo[1000] = {0};
    Usuario cadastrados [1000] = {0};
    Emprestimos pegos[1000] = {0};
    while(1){
        printf("escolha o que deseja:\n");
        printf("1 - cadastra usuario\n");
        printf("2 - cadastra livro\n");
        printf("3 - emprestimo\n");
        scanf("%d", &escolha);
        getchar();
        if(escolha == 1){
            cadastra_usuario(cadastrados);
        }
        else if(escolha == 2){
            cadastra_livro(acervo);
        }
        else if(escolha == 3){
            pega_emprestado(acervo, cadastrados, pegos);
        }
    }
    return 0;
}
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
