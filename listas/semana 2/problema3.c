#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float cap_inicial, juros, tempo, montante;
    scanf("%f %f %f", &cap_inicial, &juros, &tempo);
    while(cap_inicial <= 0){
        printf("digite capital válido!!\n");
        scanf("%f", &cap_inicial);
    }
    while(juros < 0){
        printf("digite juros válido!!\n");
        scanf("%f", &juros);
    }
    while(tempo <= 0){
        printf("digite tempo válido!!\n");
        scanf("%f", &tempo);
    }
    montante = cap_inicial * pow((1 + juros / 100), tempo);
    printf("Montante: %.2f", montante);
    return 0;
}
