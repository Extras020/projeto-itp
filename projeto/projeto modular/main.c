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
void devolucao(Livro acervo[], Usuario cadastrados[]){
    char cpf[MAX];
    char livro[MAX];
    int i, cont = 0, confirma_id;
    fgets(cpf, MAX, stdin);
    remove_nova_linha(cpf);
    for(i = 0; i < 1000; i++){
        if(strcmp(cadastrados[i].cpf, cpf) == 0){
            cont++;
            printf("confirme o nome(digite 0 para sim ou 1 para não).\n");
            printf("%s\n", cadastrados[i].nome);
            scanf("%d", &confirma_id);
            if(confirma_id == 0){
                break;
            }
            else if(confirma_id == 1){
                printf("verifique seus dados!");
                return;
            }
        }
    }
    if(cont == 0){
        printf("usuario não encontrado.\n");
        return;
    }
    cont = 0;
    if(confirma_id == 0){
        printf("digite o nome do livro que deseja devolver.\n");
        fgets(livro, MAX, stdin);
        remove_nova_linha(livro);
        for(i = 0; i < 1000; i++){
            if(strcmp(acervo[i].nome, livro) == 0){
                cont++;
                printf("devolução realizada!\n");
                acervo[i].qnt++;
                cadastrados[i].emprestimos--;
            }
        }
        if(cont == 0){
            printf("livro não encontrado no acervo!");
            return;
        }
    }
}
