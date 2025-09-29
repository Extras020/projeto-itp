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
void pega_emprestado(Livro *x, Livro *vet[]);

int main(){
    int escolha;
    Livro acervo[1000];
    Usuario cadastrados [1000];
    Usuario usuario;
    Livro livro;
    printf("escolha o que deseja:\n");
    printf("1 - cadastra usuario\n");
    printf("2 - cadastra livro\n");
    printf("3 - emprestimo\n");
    printf("4 - devolucao\n");
    scanf("%d", &escolha);
    getchar();
    if(escolha == 1) cadastra_usuario(&usuario);
    else if(escolha == 2) cadastra_livro(&livro);
    else if(escolha == 3){
        printf("digite o nome do livro que deseja emprestar:\n");
        fgets(livro.nome, MAX, stdin);
        printf("%s\n", livro.nome);
    }
    else if(escolha == 4){
        printf("digite o nome do livro que deseja devolver");
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
void pega_emprestado(Livro *x, Livro *vet[]){
    int i;
    for(i = 0; i < 999; i++){
        if(x->nome == vet[i]->nome){
            vet[i]->qnt--;
        }
    }
}
