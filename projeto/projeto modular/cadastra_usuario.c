#include <stdio.h>
#include <string.h>
#include "remove_nova_linha.h"
#include "tipos.h"
#include "converte_minusculas.h"

void cadastra_usuario(Usuario cadastrados[]){
    char cpf[MAX];
    int i, pos;
    for(i = 0; i < 1000; i++){
        if(cadastrados[i].nome[0] == '\0'){
            pos = i;
            break;
        }
    }
    printf("digite o CPF:\n");
    fgets(cpf, MAX, stdin);
    remove_nova_linha(cpf);
    for(i = 0; i < 1000; i++){
        if(strcmp(cpf, cadastrados[i].cpf) == 0){
            printf("CPF já cadastrado.\n");
            return;
        }
    }
    strcpy(cadastrados[pos].cpf, cpf);
    printf("digite o nome do usuário:\n");
    fgets(cadastrados[pos].nome, MAX, stdin);
    remove_nova_linha(cadastrados[pos].nome);
    converte_minusculas(cadastrados[pos].nome);
}
