#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipos.h"
#include "cadastra_usuario.h"
#include "cadastra_livro.h"
#include "pega_emprestado.h"
#include "devolucao.h"
#include "remove_nova_linha.h"

void listagem(Usuario cadastrados[], Livro acervo[], Emprestimos pegos[]);
void busca(Usuario cadastrados[], Livro acervo[], Emprestimos pegos[]);

int main(){
    int escolha = 0, i, validacao;
    char entrada[100];
    Livro acervo[1000] = {0};
    Usuario cadastrados [1000] = {0};
    Emprestimos pegos[1000] = {0};
    while(1){
        printf("Sistema de gerenciamento:\n");
        printf("digite uma das opcoes(de 1 a 5):\n");
        printf("1 - cadastra usuario\n");
        printf("2 - cadastra livro\n");
        printf("3 - emprestimo\n");
        printf("4 - devolucao\n");
        printf("5 - listagem\n");
        while(1){
            fgets(entrada, 100, stdin);
            remove_nova_linha(entrada);
            if(strlen(entrada) == 0){
                printf("nenhuma entrada detectada, tente novamente!\n");
                continue;
            }
            validacao = 1;
            i = 0;
            while(entrada[i] != '\0'){
                if(entrada[i] < '0' || entrada[i] > '9'){
                    validacao = 0;
                    break;
                }
                i++;
            }
            if(validacao == 0){
                printf("entrada invalida, digite apenas numeros!\n");
                continue;
            }
            escolha = atoi(entrada);
            if(escolha < 1 || escolha > 5){
                printf("escolha fora do intervalo de 1 a 5, tente novamente!\n");
                continue;
            }
            break;
        }
        if(escolha == 1){
            cadastra_usuario(cadastrados);
        }
        else if(escolha == 2){
            cadastra_livro(acervo);
        }
        else if(escolha == 3){
            pega_emprestado(acervo, cadastrados, pegos);
        }
        else if(escolha == 4){
            devolucao(acervo, cadastrados);
        }
        else if(escolha == 5){
            listagem(cadastrados, acervo, pegos);
        }
    }
    return 0;
}
void listagem(Usuario cadastrados[], Livro acervo[], Emprestimos pegos[]){
    char entrada[100];
    int i, escolha = 0, validacao;
    printf("digite qual lista voce quer\n");
    printf("1 - Usuarios cadastrados\n");
    printf("2 - Livros do acervo\n");
    printf("3 - Emprestimos realizados\n");
    while(1){
        fgets(entrada, 100, stdin);
        remove_nova_linha(entrada);
        if(strlen(entrada) == 0){
            printf("nenhuma entrada detectada, tente novamente!\n");
            continue;
        }
        validacao = 1;
        i = 0;
        while(entrada[i] != '\0'){
            if(entrada[i] < '0' || entrada[i] > '9'){
                validacao = 0;
                break;
            }
            i++;
        }
        if(validacao == 0){
            printf("entrada invalida, digite apenas numeros!\n");
            continue;
        }
        escolha = atoi(entrada);
        if(escolha < 1 || escolha > 3){
            printf("escolha fora do intervalo de 1 a 3, tente novamente!\n");
            continue;
        }
        break;
    }
    if(escolha == 1){
        for(i = 0; i < 1000; i++){
            if(cadastrados[i].nome[0] == '\0'){
                break;
            }
            else{
               printf("%s\n", cadastrados[i].nome);
            }
        }
    }
    else if(escolha == 2){
        for(i = 0; i < 1000; i++){
            if(acervo[i].nome[0] == '\0'){
                break;
            }
            else{
                printf("%s\n", acervo[i].nome);
            }
        }
    }
    else if(escolha == 3){
        for(i = 0; i < 1000; i++){
            if(pegos[i].isbn[0] == '\0'){
                break;
            }
            else{
                printf("%s - %s\n", pegos[i].isbn, pegos[i].cpf);
            }
        }
    }
}
void busca(Usuario cadastrados[], Livro acervo[], Emprestimos pegos[]){
    //Resolver problema das letras maiusculas e minusculas!!!!!!
    printf("o que deseja buscar?");
    printf("1 - Usuario\n");
    printf("2 - Livro\n");
}
