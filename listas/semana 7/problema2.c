#include <stdio.h>
#include <string.h>

int verifica_padrao_brasileiro(char palavra[]);
int verifica_padrao_mercosul(char palavra[]);

int main(){
    char palavra[12];
    fgets(palavra, 12, stdin);
    if(verifica_padrao_brasileiro(palavra) == 0){
        printf("brasileiro\n");
        return 0;
    }
    else if(verifica_padrao_mercosul(palavra) == 0){
        printf("mercosul\n");
        return 0;
    }
    else{
        printf("invalido\n");
        return 0;
    }
}
int verifica_padrao_brasileiro(char palavra[]){
    int i;
    for(i = 0; i < 8; i++){
        if(i < 3){
            if(palavra[i] < 'A' || palavra[i] > 'Z'){
                return 1;
            }
        }
        else if(i == 3){
            if(palavra[i] != '-') return 1;
        }
        else if(i > 3){
            if(palavra[i] < 0){
                return 1;
            }
        }
    }
    return 0;
}
int verifica_padrao_mercosul(char palavra[]){
    int i;
    for(i = 0; i < 7; i++){
        if(i < 3){
            if(palavra[i] < 'A' || palavra[i] > 'Z'){
                return 1;
            }
        }
        else if(i == 3){
            if(palavra[i] < 0){
                return 1;
            }
        }
        else if(i == 4){
            if(palavra[i] < 'A' || palavra[i] > 'Z'){
                return 1;
            }
        }
        else if(i > 4){
            if(palavra[i] < 0){
                return 1;
            }
        }
    }
    return 0;
}
