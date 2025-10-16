#include <stdio.h>
#include <stdlib.h>

int main()
{
    float peso, altura, IMC;
    scanf("%f %f", &peso, &altura);
    while(peso <= 0){
        printf("digite um peso válido!!\n");
        scanf("%f", &peso);
    }
    while(altura <= 0){
        printf("digite uma altura válida\n");
        scanf("%f", &altura);
    }
    IMC = peso/(altura*altura);
    printf("IMC = %.2f\n", IMC);
    if(IMC < 18.5){
        printf("Abaixo do peso\n");
    }
    else if(IMC >= 18.5 && IMC <= 24.9){
        printf("peso normal\n");
    }
    else if(IMC >= 25.0 && IMC <= 29.9){
        printf("Sobrepeso\n");
    }
    else if(IMC >= 30.0){
        printf("Obesidade");
    }
    return 0;
}
