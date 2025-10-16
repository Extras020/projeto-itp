#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int verifica_altura(float a, float b);
int verifica_seguranca(float a, float b);
float calcula_altura(float a, float b);

int main()
{
    float x, y;
    int status_ponto, maior_seguranca;
    scanf("%f %f", &x, &y);
    status_ponto = verifica_altura(x, y);
    if(status_ponto == 1){
        printf("troque de coordenada\n");
    }
    else{
        maior_seguranca = verifica_seguranca(x, y);
        if(maior_seguranca == 0 || maior_seguranca == 1){
            printf("inseguro\n");
        }
        else if(maior_seguranca == 2 || maior_seguranca == 3){
            printf("relativamente seguro\n");
        }
        else if(maior_seguranca == 4){
            printf("seguro\n");
        }
    }
    return 0;
}
float calcula_altura(float a, float b){
    float altura;
    altura = sin(cos(b)+a)+cos(b+sin(a));
    return altura;
}
int verifica_altura(float a, float b){
    int cont = 0;
    float altura;
    altura = calcula_altura(a, b);
    if(altura < 0 || altura > 2) cont++;
    altura = calcula_altura(a+0.2, b+0.2);
    if(altura < 0 || altura > 2) cont++;
    altura = calcula_altura(a-0.2, b-0.2);
    if(altura < 0 || altura > 2) cont++;
    altura = calcula_altura(a+0.2, b-0.2);
    if(altura < 0 || altura > 2) cont++;
    altura = calcula_altura(a-0.2, b+0.2);
    if(altura < 0 || altura > 2) cont++;
    if(cont != 0) return 1;
    else return 0;
}
int verifica_seguranca(float a, float b){
    int cont = 0, status;
    status = verifica_altura(a+2, b);
    if(status == 0) cont++;
    status = verifica_altura(a-2, b);
    if(status == 0) cont++;
    status = verifica_altura(a, b+2);
    if(status == 0) cont++;
    status = verifica_altura(a, b-2);
    if(status == 0) cont++;
    return cont;
}
