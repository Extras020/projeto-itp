#include <stdio.h>
#include <string.h>
#include "tipos.h"
#include "remove_nova_linha.h"
#include "converte_minusculas.h"

void devolucao(Livro acervo[], Usuario cadastrados[], Emprestimos pegos[]){
    char cpf[MAX];
    char livro[MAX];
    int i, cont = 0, confirma_id, pos_id, pos_livro;
    printf("digite o cpf do usuario:\n");
    fgets(cpf, MAX, stdin);
    remove_nova_linha(cpf);
    for(i = 0; i < 1000; i++){
        if(strcmp(pegos[i].cpf, cpf) == 0){
            cont++;
            printf("confirme o nome(digite 0 para sim ou 1 para n�o).\n");
            printf("%s\n", cadastrados[i].nome);
            scanf("%d", &confirma_id);
            getchar();
            if(confirma_id == 0){
                break;
                for(i = 0; i < 1000; i++){
                    if(strcmp(cadastrados[i].cpf, cpf) == 0){
                        pos_id = i;
                        break;
                    }
                }
            }
            else if(confirma_id == 1){
                printf("verifique seus dados!");
                return;
            }
        }
    }
    if(cont == 0){
        printf("N�o h� nenhum emprestimos realizado para este usuario.\n");
        return;
    }
    cont = 0;
    if(confirma_id == 0){
        printf("digite o nome do livro que deseja devolver.\n");
        fgets(livro, MAX, stdin);
        remove_nova_linha(livro);
        converte_minusculas(livro);
        for(i = 0; i < 1000; i++){
            if(strcmp(acervo[i].nome, livro) == 0){
                pos_livro = i;
                break;
            }
        }
        for(i = 0; i < 1000; i++){
            if(strcmp(pegos[i].nome_livro, livro) == 0){
                cont++;
                printf("devolu��o realizada!\n");
                acervo[pos_livro].qnt++;
                cadastrados[pos_id].emprestimos--;
                pegos[i].nome_livro[0] = '\0';
            }
        }
        if(cont == 0){
            printf("este livro n�o consta como emprestimo desse usuario\n");
            return;
        }
    }
}
