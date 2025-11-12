#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tipos.h"
#include "remove_nova_linha.h"
#include "insere_emprestados.h"
#include "converte_minusculas.h"

void pega_emprestado(Livro acervo[], Usuario cadastrados[], Emprestimos pegos[]){
    char livro[MAX];
    char cpf[MAX];
    char entrada[MAX];
    int escolha, cont = 0;
    int i, verifica_id, pos_livro, validacao;
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
        if(escolha < 1 || escolha > 2){
            printf("escolha fora do intervalo de 1 a 2, tente novamente!\n");
            continue;
        }
        break;
    }
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
                    verifica_id = atoi(entrada);
                    if(verifica_id < 0 || verifica_id > 1){
                        printf("escolha fora do intervalo de 0 a 1, tente novamente!\n");
                        continue;
                    }
                    break;
                }
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
