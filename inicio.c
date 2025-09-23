#include <stdio.h>
#define MAX 100

typedef struct{
    char nome[MAX];
    char CPF[12];
    int emprestimos;
} Usuario;
typedef struct{
    char nome[MAX];
    char autor[MAX];
    int qnt;
}Livro;

void cadastra_usuario(Usuario x);
void cadastra_livro(Livro x);
void pegar_emprestado();
void devolver();

int main(){
    int escolha;
    Usuario usuario;
    Livro livro;
    printf("digite 1 para cadastrar usuario ou 2 para cadastrar livro:\n");
    scanf("%d", &escolha);
    if(escolha == 1){
        cadastrar_usuario(usuario);
        printf("")
    }
    else if(escolha == 2) cadastra_livro(livro);
    return 0;
}
void cadastra_usuario(Usuario x){
    int i;
    printf("digite o nome do usuario:\n");
    //comando para definir o nome
    printf("digite o CPF:\n");
    //comando para definir o CPF
}
void cadastra_livro(Livro x){
    int i;
    printf("digite o nome do livro:\n");
    //comando para definir o nome do livro
    printf("digite o nome do autor:\n");
    //comando para definir o nome do autor;
    printf("digite a quantidade de exemplares:\n", &)
}
