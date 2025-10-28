#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

typedef struct{
    char nome[MAX];
    char cpf[12];
    int emprestimos;
} Usuario;
typedef struct{
    char nome[MAX];
    char autor[MAX];
    char isbn[14];
    int qnt;
}Livro;
typedef struct{
    char cpf[MAX];
    char isbn[14];
}Emprestimos;

void cadastra_usuario(Usuario cadastrados[]);
void cadastra_livro(Livro acervo[]);
void pega_emprestado(Livro acervo[], Usuario cadastrados[], Emprestimos pegos[]);
void insere_emprestados(Emprestimos pegos[], char livro[], char cpf[], Livro acervo[]);
void devolucao(Livro acervo[], Usuario cadastrados[]);
void remove_nova_linha(char string[]);

int main(){
    int escolha = 0, i, validacao;
    char entrada[100];
    Livro acervo[1000] = {0};
    Usuario cadastrados [1000] = {0};
    Emprestimos pegos[1000] = {0};
    while(1){
        printf("escolha o que deseja:\n");
        printf("1 - cadastra usuario\n");
        printf("2 - cadastra livro\n");
        printf("3 - emprestimo\n");
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
            cadastra_usuario(cadastrados);
        }
        else if(escolha == 2){
            cadastra_livro(acervo);
        }
        else if(escolha == 3){
            pega_emprestado(acervo, cadastrados, pegos);
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
void insere_emprestados(Emprestimos pegos[], char livro[], char cpf[], Livro acervo[]){
    int i, pos;
    for(i = 0; i < 1000; i++){
        if(pegos[i].cpf[0] == '\0'){
            pos = i;
            break;
        }
    }
    for(i = 0; i < 1000; i++){
        if(strcmp(livro, acervo[i].nome) == 0){
            strcpy(pegos[pos].isbn, acervo[i].isbn);
            strcpy(pegos[pos].cpf, cpf);
            return;
        }
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
    int i, pos;
    char isbn[14];
    for(i = 0; i < 1000; i++){
        if(acervo[i].nome[0] == '\0'){
            pos = i;
            break;
        }
    }
    printf("digite o nome do livro:\n");
    fgets(acervo[pos].nome, MAX, stdin);
    remove_nova_linha(acervo[pos].nome);
    printf("digite o nome do autor:\n");
    fgets(acervo[pos].autor, MAX, stdin);
    remove_nova_linha(acervo[pos].autor);
    printf("digite a quantidade:\n");
    scanf("%d", &acervo[pos].qnt);
    getchar();
    printf("digite o ISBN:\n");
    fgets(isbn, 14, stdin);
    remove_nova_linha(isbn);
    for(i = 0; i < 1000; i++){
        if(strcmp(acervo[i].isbn, isbn) == 0){
            printf("livro ja cadastrado.\n");
            acervo[pos].nome[0] = '\0';
            acervo[pos].autor[0] = '\0';
            return;
        }
    }
    strcpy(acervo[pos].isbn, isbn);
}
void pega_emprestado(Livro acervo[], Usuario cadastrados[], Emprestimos pegos[]){
    char livro[MAX];
    char cpf[MAX];
    int escolha, cont = 0;
    int i, verifica_id, pos_livro;
    printf("digite o nome do livro que deseja:\n");
    fgets(livro, MAX, stdin);
    remove_nova_linha(livro);
    for(i = 0; i < 1000; i++){
        if(strcmp(acervo[i].nome, livro) == 0){
            cont++;
            pos_livro = i;
            if(acervo[i].qnt > 0){
                printf("disponível para empréstimo.\n");
                break;
            }
            else{
                printf("indisponível para empréstimo.\n");
                return;
            }
        }
    }
    if(cont == 0) {
        printf("livro não existe no acervo!\n");
        return;
    }
    cont = 0;
    printf("deseja pegar emprestado? (digite 1 para emprestar ou 2 para cancelar!)\n");
    scanf("%d", &escolha);
    getchar();
    if(escolha == 2){
        printf("empréstimo cancelado!\n");
        return;
    }
    else if(escolha == 1){
        printf("informe o cpf do usuário que deseja pegar emprestado:\n");
        fgets(cpf, MAX, stdin);
        remove_nova_linha(cpf);
        for(i = 0; i < 1000; i++){
            if(strcmp(cadastrados[i].cpf, cpf) == 0){
                cont++;
                printf("%s\n", cadastrados[i].nome);
                printf("confirme o usuário!(0 para sim, 1 para não)\n");
                scanf("%d", &verifica_id);
                getchar();
                if(verifica_id == 0){
                    cadastrados[i].emprestimos++;
                    acervo[pos_livro].qnt--;
                    printf("empréstimo realizado!\n");
                    return;
                }
                else if(verifica_id == 1){
                    printf("reveja seus dados\n");
                    return;
                }
            }
        }
        if(cont == 0){
            printf("usuário não encontrado!\n");
            return;
        }
    }
}
