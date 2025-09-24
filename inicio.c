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

void cadastra_usuario(Usuario *x);
void cadastra_livro(Livro *x);

int main(){
    int escolha;
    Livro acervo[1000];
    Usuario cadastrados [1000];
    Usuario usuario;
    Livro livro;
    printf("digite 1 para cadastrar usuario ou 2 para cadastrar livro:\n");
    scanf("%d", &escolha);
    getchar();
    if(escolha == 1){
        cadastra_usuario(&usuario);
    }
    else if(escolha == 2){
        cadastra_livro(&livro);
    }
    return 0;
}
void cadastra_usuario(Usuario *x){
    printf("digite o nome do usuario:\n");
    fgets(x->nome, MAX, stdin);
    printf("digite o CPF:\n");
    fgets(x->cpf, MAX, stdin);
}
void cadastra_livro(Livro *x){
    printf("digite o nome do livro:\n");
    fgets(x->nome, MAX, stdin);
    printf("digite o nome do autor:\n");
    fgets(x->autor, MAX, stdin);
    printf("digite a quantidade:\n");
    scanf("%d", &x->qnt);
    getchar();
}
