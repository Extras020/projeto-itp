#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int a, b, c, delta;
    float x1, x2;
    scanf("%d %d %d", &a, &b, &c);
    while(a == 0){
        printf("a igual a zero n�o forma equa��o do segundo grau, digite novamente!\n");
        scanf("%d", &a);
    }
    delta = (b*b) - (4*a*c);
    if(delta > 0){
        x1 = (-b+sqrt(delta))/(2.0*a);
        x2 = (-b-sqrt(delta))/(2.0*a);
        printf("1� raiz: %.1f\n", x1);
        printf("2� raiz: %.1f\n", x2);
    }
    else if(delta == 0){
        x1 = -b/(2.0*a);
        printf("�nica raiz real: %.1f\n", x1);
    }
    else{
        printf("n�o existe ra�zes reais para esses coeficientes!\n");
    }
    return 0;
}
