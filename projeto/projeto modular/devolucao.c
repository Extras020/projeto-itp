#include <stdio.h>
#include <string.h>
#include "tipos.h"
#include "remove_nova_linha.h"

void devolucao(Livro acervo[], Usuario cadastrados[]){
    char cpf[MAX];
    char livro[MAX];
    int i, cont = 0, confirma_id, pos_id;
    printf("digite o cpf do usuario:\n");
    fgets(cpf, MAX, stdin);
    remove_nova_linha(cpf);
    for(i = 0; i < 1000; i++){
        if(strcmp(cadastrados[i].cpf, cpf) == 0){
            cont++;
            pos_id = i;
            printf("confirme o nome(digite 0 para sim ou 1 para não).\n");
            printf("%s\n", cadastrados[i].nome);
            scanf("%d", &confirma_id);
            getchar();
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
                cadastrados[pos_id].emprestimos--;
            }
        }
        if(cont == 0){
            printf("livro não encontrado no acervo!");
            return;
        }
    }
}
