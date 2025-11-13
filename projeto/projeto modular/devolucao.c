#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tipos.h"
#include "remove_nova_linha.h"
#include "converte_minusculas.h"
#include "apaga_registro.h"

void devolucao(Livro acervo[], Usuario cadastrados[], Emprestimos pegos[]){
    char cpf[MAX];
    char livro[MAX];
    char entrada[MAX];
    int i, cont = 0, confirma_id, pos_id, pos_livro, validacao;
    int l, u, v, p;
    Emprestimos AUX;
    printf("digite o cpf do usuario:\n");
    fgets(cpf, MAX, stdin);
    remove_nova_linha(cpf);
    for(i = 0; i < 1000; i++){
        if(strcmp(pegos[i].cpf, cpf) == 0){
            cont++;
            printf("confirme o nome(digite 0 para sim ou 1 para não).\n");
            printf("%s\n", cadastrados[i].nome);
            while(1){
                fgets(entrada, 100, stdin);
                remove_nova_linha(entrada);
                if(strlen(entrada) == 0){
                    printf("nenhuma entrada detectada, tente novamente!\n");
                    continue;
                }
                validacao = 1;
                v = 0;
                while(entrada[v] != '\0'){
                    if(entrada[v] < '0' || entrada[v] > '9'){
                        validacao = 0;
                        break;
                    }
                    v++;
                }
                if(validacao == 0){
                    printf("entrada invalida, digite apenas numeros!\n");
                    continue;
                }
                confirma_id = atoi(entrada);
                if(confirma_id < 0 || confirma_id > 1){
                    printf("escolha fora do intervalo de 0 a 1, tente novamente!\n");
                    continue;
                }
                break;
            }
            if(confirma_id == 0){
                for(p = 0; p < 1000; p++){
                    if(strcmp(cadastrados[p].cpf, cpf) == 0){
                        pos_id = p;
                        break;
                    }
                }
                break;
            }
            else if(confirma_id == 1){
                printf("verifique seus dados!");
                return;
            }
        }
    }
    if(cont == 0){
        printf("Não há nenhum emprestimos realizado para este usuario.\n");
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
            if(strcmp(pegos[i].nome_livro, livro) == 0 && strcmp(pegos[i].cpf, cpf) == 0){
                cont++;
                printf("devolução realizada!\n");
                acervo[pos_livro].qnt++;
                cadastrados[pos_id].emprestimos--;
                apaga_registro(pegos[i].cpf);
                apaga_registro(pegos[i].isbn);
                apaga_registro(pegos[i].nome_livro);
                apaga_registro(pegos[i].nome_usuario);
                // reordena vetor para separar posições vazias de posições não-vazias
                for(l = 0; l < 1000; l++){
                    if(pegos[l].cpf[0] == '\0'){
                        for(u = l + 1; u < 1000; u++){
                            if(pegos[u].cpf[0] != '\0' && pegos[u+1].cpf[0] == '\0'){
                                AUX = pegos[u];
                                break;
                            }
                        }
                        pegos[u] = pegos[l];
                        pegos[l] = AUX;
                        break;
                    }
                }
            }
        }
        if(cont == 0){
            printf("este livro não consta como emprestimo desse usuario\n");
            return;
        }
    }
}
