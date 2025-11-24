#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipos.h"
#include "remove_nova_linha.h"
#include "converte_minusculas.h"

void busca(Emprestimos pegos[], Livro acervo[], Usuario cadastrados[]){
    char entrada[100];
    char busca[100];
    int i, a, escolha, validacao = 0, cont = 0;
    printf("Qual busca você procura?\n");
    printf("1 - Usuário\n");
    printf("2 - Livro\n");
    printf("3 - Empréstimos\n");
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
            printf("entrada inválida, digite apenas numeros!\n");
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
        printf("digite o nome ou cpf procurado:\n");
        fgets(busca, 100, stdin);
        remove_nova_linha(busca);
        converte_minusculas(busca);
        for(i = 0; i < 1000; i++){
            if(strcmp(cadastrados[i].nome, busca) == 0 || strcmp(cadastrados[i].cpf, busca) == 0){
                cont = 1;
                printf("Nome - %s\n", cadastrados[i].nome);
                printf("CPF - %s\n", cadastrados[i].cpf);
                printf("Empréstimos - %d\n", cadastrados[i].emprestimos);
            }
        }
        if(cont == 0){
            printf("Nenhum usuario encontrado\n");
            return;
        }
    }
    else if(escolha == 2){
        printf("digite o nome do livro ou o autor que procura:\n");
        fgets(busca, 100, stdin);
        remove_nova_linha(busca);
        converte_minusculas(busca);
        for(i = 0; i < 1000; i++){
            if(strcmp(acervo[i].nome, busca) == 0 || strcmp(acervo[i].autor, busca) == 0){
                cont = 1;
                printf("Nome - %s\n", acervo[i].nome);
                printf("Autor - %s\n", acervo[i].autor);
                printf("Id - %s\n", acervo[i].isbn);
                printf("Quantidade disponivel - %d\n", acervo[i].qnt);
            }
        }
        if(cont == 0){
            printf("Nenhum livro encontrado\n");
            return;
        }
    }
    else if(escolha == 3){
        printf("digite o nome ou o cpf do usuario que procura:\n");
        fgets(busca, 100, stdin);
        remove_nova_linha(busca);
        converte_minusculas(busca);
        for(i = 0; i < 1000; i++){
            if(strcmp(pegos[i].cpf, busca) == 0 || strcmp(pegos[i].nome_usuario, busca) == 0){
                cont = 1;
                printf("Nome do usuário - %s\n", pegos[i].nome_usuario);
                printf("CPF do usuário - %s\n", pegos[i].cpf);
                printf("Empréstimos realizados:\n");
                for(a = 0; a < 1000; a++){
                    if(strcmp(pegos[a].nome_usuario, busca) == 0 || strcmp(pegos[a].cpf, busca) == 0){
                        printf("%s - %s\n", pegos[a].nome_livro, pegos[a].isbn);
                    }
                }
                break;
            }
        }
        if(cont == 0){
            printf("Nenhum empréstimo encontrado para esse usuário\n");
            return;
        }
    }
}
