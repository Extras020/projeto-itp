#include <stdio.h>
#include <string.h>
#include "tipos.h"
#include "cadastra_usuario.h"
#include "cadastra_livro.h"
#include "pega_emprestado.h"
#include "devolucao.h"

int main(){
    int escolha;
    Livro acervo[1000] = {0};
    Usuario cadastrados [1000] = {0};
    Emprestimos pegos[1000] = {0};
    while(1){
        printf("Sistema de gerenciamento:\n");
        printf("digite uma das opções(de 1 a 4):\n");
        printf("1 - cadastra usuario\n");
        printf("2 - cadastra livro\n");
        printf("3 - emprestimo\n");
        printf("4 - devolucao\n");
        scanf("%d", &escolha);
        getchar();
        while(escolha < 1 || escolha > 4){
            printf("digite uma opção válida!\n");
            scanf("%d", &escolha);
            getchar();
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
    }
    return 0;
}
