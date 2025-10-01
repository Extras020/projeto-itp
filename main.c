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
    int qnt;
}Livro;

void cadastra_usuario(Usuario cadastrados[]);
void cadastra_livro(Livro acervo[]);
void pega_emprestado(Livro acervo[]);

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
            printf("%s\n", cadastrados[0].nome);
            printf("%s\n", cadastrados[0].cpf);
            printf("%d\n", cadastrados[0].emprestimos);
        }
        else if(escolha == 2){
            cadastra_livro(&acervo);
            printf("%s\n", acervo[0].nome);
            printf("%s\n", acervo[0].autor);
            printf("%d\n", acervo[0].qnt);
        }
        else if(escolha == 3){
            printf("digite o nome do livro que deseja emprestar:\n");
            fgets(livro.nome, MAX, stdin);
            printf("%s\n", livro.nome);
        }
        else if(escolha == 4){
            printf("digite o nome do livro que deseja devolver");
        }
    }
    return 0;
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
    printf("digite o CPF:\n");
    fgets(cpf, 12, stdin);
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
    for(i = 0; i < 1000; i++){
        if(acervo[i].nome[0] == '\0'){
            pos = i;
            break;
        }
    }
    printf("digite o nome do livro:\n");
    fgets(nome, MAX, stdin);
    printf("digite o nome do autor:\n");
    fgets(acervo[pos].autor, MAX, stdin);
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
        if(strcmp(livro, acervo[i].nome) == 0){
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
