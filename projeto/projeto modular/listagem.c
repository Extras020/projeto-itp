#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tipos.h"
#include "remove_nova_linha.h"

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
                printf("%s - %s\n", pegos[i].nome_livro, pegos[i].nome_usuario);
            }
        }
    }
}
