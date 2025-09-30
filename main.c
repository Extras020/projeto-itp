#include <stdio.h>
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

void cadastra_usuario(Usuario *x, Usuario cadastrados[]);
void cadastra_livro(Livro *x, Livro acervo[]);
void pega_emprestado(Livro *x, Livro acervo[]);

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
            cadastra_usuario(&usuario, &cadastrados);
            printf("%s\n", cadastrados[0].nome);
            printf("%s\n", cadastrados[0].cpf);
            printf("%d\n", cadastrados[0].emprestimos);
        }
        else if(escolha == 2){
            cadastra_livro(&livro, &acervo);
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
/*
void cadastra_usuario(Usuario *x, Usuario cadastrados[]){
    int i, pos;
    for(i = 0; i < 1000; i++){
        if(cadastrados[i].nome == '\0'){
            pos = i;
            break;
        }
    }
    printf("digite o nome do usuario:\n");
    fgets(x->nome, MAX, stdin);
    printf("digite o CPF:\n");
    fgets(x->cpf, MAX, stdin);
}
void cadastra_livro(Livro *x, Livro acervo[]){
    int i;
    printf("digite o nome do livro:\n");
    fgets(x->nome, MAX, stdin);
    printf("digite o nome do autor:\n");
    fgets(x->autor, MAX, stdin);
    printf("digite a quantidade:\n");
    scanf("%d", &x->qnt);
    getchar();
}
void pega_emprestado(Livro *x, Livro acervo[]){
    int i;
    for(i = 0; i < 999; i++){
        if(x->nome == acervo[i].nome){
            acervo[i].qnt--;
        }
    }
}
*/
