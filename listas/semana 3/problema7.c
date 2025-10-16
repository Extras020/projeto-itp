#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int a, b, c, delta;
    float x1, x2;
    scanf("%d %d %d", &a, &b, &c);
    while(a == 0){
        printf("a igual a zero não forma equação do segundo grau, digite novamente!\n");
        scanf("%d", &a);
    }
    delta = (b*b) - (4*a*c);
    if(delta > 0){
        x1 = (-b+sqrt(delta))/(2.0*a);
        x2 = (-b-sqrt(delta))/(2.0*a);
        printf("1ª raiz: %.1f\n", x1);
        printf("2ª raiz: %.1f\n", x2);
    }
    else if(delta == 0){
        x1 = -b/(2.0*a);
        printf("única raiz real: %.1f\n", x1);
    }
    else{
        printf("não existe raízes reais para esses coeficientes!\n");
    }
    return 0;
}
