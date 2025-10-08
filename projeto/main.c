#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct{
    char nome[MAX];
    char cpf[12];
    int emprestimos;
} Usuario;
typedef struct{
    char nome[MAX];
    char autor[MAX];
    char isbn[3];
    int qnt;
}Livro;

void cadastra_usuario(Usuario cadastrados[]);
void cadastra_livro(Livro acervo[]);
void pega_emprestado(Livro acervo[]);
void remove_nova_linha(char string[]);

int main(){
    int escolha;
    Livro acervo[1000] = {0};
    Usuario cadastrados [1000] = {0};
    Usuario usuario;
    Livro livro;
    while(1){
        printf("escolha o que deseja:\n");
        printf("1 - cadastra usuario\n");
        printf("2 - cadastra livro\n");
        printf("3 - emprestimo\n");
        printf("4 - devolucao\n");
        scanf("%d", &escolha);
        getchar();
        if(escolha == 1){
            cadastra_usuario(&cadastrados);
        }
        else if(escolha == 2){
            cadastra_livro(&acervo);
        }
        else if(escolha == 3){
            pega_emprestado(&acervo);
        }
        else if(escolha == 4){
            printf("digite o nome do livro que deseja devolver");
        }
    }
    return 0;
}
void remove_nova_linha(char string[]){
    int i = 0;
    while(string[i] != '\0'){
        if(string[i] == '\n'){
            string[i] = '\0';
            return;
        }
        i++;
    }
}
void cadastra_usuario(Usuario cadastrados[]){
    char cpf[MAX];
    int i, pos;
    for(i = 0; i < 1000; i++){
        if(cadastrados[i].nome[0] == '\0'){
            pos = i;
            break;
        }
    }
    printf("digite o nome do usuario:\n");
    fgets(cadastrados[pos].nome, MAX, stdin);
    remove_nova_linha(cadastrados[pos].nome);
    printf("digite o CPF:\n");
    fgets(cpf, 12, stdin);
    remove_nova_linha(cpf);
    for(i = 0; i < 1000; i++){
        if(strcmp(cpf, cadastrados[i].cpf) == 0){
            printf("CPF ja cadastrado.\n");
            cadastrados[pos].nome[0] = '\0';
            return;
        }
    }
    strcpy(cadastrados[pos].cpf, cpf);
}
void cadastra_livro(Livro acervo[]){
    //PRECISA VERIFICAR SE O LIVRO JA EXISTE NO ACERVO
    int i, pos;
    char nome[MAX];
    char isbn[14];
    for(i = 0; i < 1000; i++){
        if(acervo[i].nome[0] == '\0'){
            pos = i;
            break;
        }
    }
    printf("digite o ISBN:\n");
    fgets(isbn, 14, stdin);
    remove_nova_linha(isbn);
    for(i = 0; i < 1000; i++){
        if(strcmp(acervo[i].isbn, isbn) == 0){
            printf("livro ja cadastrado.\n");
            acervo[pos].nome[0] = '\0';
            return;
        }
    }
    strcpy(acervo[pos].isbn, isbn);
    printf("digite o nome do livro:\n");
    fgets(acervo[pos].nome, MAX, stdin);
    remove_nova_linha(acervo[pos].nome);
    printf("digite o nome do autor:\n");
    fgets(acervo[pos].autor, MAX, stdin);
    remove_nova_linha(acervo[pos].autor);
    printf("digite a quantidade:\n");
    scanf("%d", &acervo[pos].qnt);
    getchar();
}
void pega_emprestado(Livro acervo[]){
    char livro[MAX];
    int escolha, cont = 0;
    int i;
    printf("digite o nome do livro que deseja:\n");
    fgets(livro, MAX, stdin);
    for(i = 0; i < 1000; i++){
        if(strcmp(acervo[i].nome, livro) == 0){
            cont++;
            if(acervo[i].qnt > 0){
                printf("disponível para empréstimo.\n");
                printf("digite 1 para emprestimo ou 2 para cancelar!\n");
                scanf("%d", &escolha);
                if(escolha == 1){
                    acervo[i].qnt--;
                    printf("emprestimo realizado!\n");
                }
                else if(escolha == 2){
                    return;
                }
            }
        }
    }
    if(cont == 0){
        printf("livro indisponível.\n");
    }
    return;
}
