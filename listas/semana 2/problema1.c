#include <stdio.h>
#include <stdlib.h>

int main()
{
    float peso, altura, IMC;
    scanf("%f %f", &peso, &altura);
    while(peso <= 0){
        printf("digite um peso v�lido!!\n");
        scanf("%f", &peso);
    }
    while(altura <= 0){
        printf("digite uma altura v�lida\n");
        scanf("%f", &altura);
    }
    IMC = peso/(altura*altura);
    printf("IMC = %.2f", IMC);
    return 0;
}
