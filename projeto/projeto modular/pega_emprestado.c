#include <stdio.h>
#include <string.h>
#include "tipos.h"
#include "remove_nova_linha.h"
#include "insere_emprestados.h"
#include "converte_minusculas.h"

void pega_emprestado(Livro acervo[], Usuario cadastrados[], Emprestimos pegos[]){
    char livro[MAX];
    char cpf[MAX];
    int escolha, cont = 0;
    int i, verifica_id, pos_livro;
    printf("digite o nome do livro que deseja:\n");
    fgets(livro, MAX, stdin);
    remove_nova_linha(livro);
    converte_minusculas(livro);
    for(i = 0; i < 1000; i++){
        if(strcmp(acervo[i].nome, livro) == 0){
            cont++;
            pos_livro = i;
            if(acervo[i].qnt > 0){
                printf("disponível para empréstimo.\n");
                break;
            }
            else{
                printf("indisponível para empréstimo.\n");
                return;
            }
        }
    }
    if(cont == 0) {
        printf("livro não existe no acervo!\n");
        return;
    }
    cont = 0;
    printf("deseja pegar emprestado? (digite 1 para emprestar ou 2 para cancelar!)\n");
    scanf("%d", &escolha);
    getchar();
    if(escolha == 2){
        printf("empréstimo cancelado!\n");
        return;
    }
    else if(escolha == 1){
        printf("informe o cpf do usuário que deseja pegar emprestado:\n");
        fgets(cpf, MAX, stdin);
        remove_nova_linha(cpf);
        for(i = 0; i < 1000; i++){
            if(strcmp(cadastrados[i].cpf, cpf) == 0){
                cont++;
                printf("%s\n", cadastrados[i].nome);
                printf("confirme o usuário!(0 para sim, 1 para não)\n");
                scanf("%d", &verifica_id);
                getchar();
                if(verifica_id == 0){
                    cadastrados[i].emprestimos++;
                    acervo[pos_livro].qnt--;
                    insere_emprestados(pegos, livro, cpf, acervo, cadastrados[i].nome);
                    printf("empréstimo realizado!\n");
                    return;
                }
                else if(verifica_id == 1){
                    printf("reveja seus dados\n");
                    return;
                }
            }
        }
        if(cont == 0){
            printf("usuário não encontrado!\n");
            return;
        }
    }
}
