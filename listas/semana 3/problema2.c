#include <stdio.h>
#include <stdlib.h>

int main()
{
    float conta = 0, consumo;
    char tipo;
    scanf("%f", &consumo);
    scanf(" %c", &tipo);
    while(consumo < 0){
        printf("informe um consumo válido!!\n");
        scanf("%f", &consumo);
    }
    while(tipo != 'R' && tipo != 'C' && tipo != 'I'){
        printf("informe um tipo válido!!\n");
        scanf(" %c", &tipo);
    }
    if(tipo == 'R'){
        conta = 15.0 + consumo*0.60;
    }
    else if(tipo == 'C'){
        conta = 15.0 + consumo*0.48;
    }
    else if(tipo == 'I'){
        conta = 15.0 + consumo*1.29;
    }
    printf("conta: %.2f\n", conta);
    return 0;
}
