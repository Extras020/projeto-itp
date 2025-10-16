#include <stdio.h>
#include <stdlib.h>

int main()
{
    float valor_compra, desconto, percentual_desconto;
    scanf("%f", &valor_compra);
    if(valor_compra <= 100){
        percentual_desconto = 0;
    }
    else if(valor_compra > 100 && valor_compra <= 500){
        percentual_desconto = 10.0/100;
    }
    else if(valor_compra > 500 && valor_compra <= 1000){
        percentual_desconto = 15.0/100;
    }
    else if(valor_compra > 1000){
        percentual_desconto = 20.0/100;
    }
    desconto = valor_compra*percentual_desconto;
    valor_compra = valor_compra - desconto;

    printf("Valor do desconto: %.2f\n", desconto);
    printf("Valor total da compra: %.2f\n", valor_compra);
    printf("Percentual do desconto aplicado: %.1f%% \n", percentual_desconto*100);
    return 0;
}
