#include <stdio.h>
#include <stdlib.h>

int main()
{
    float l1, l2, l3;
    scanf("%f %f %f", &l1, &l2, &l3);
    if(l1+l2>l3 || l2+l3>l1 || l1+l3>l2){
        printf("forma triângulo!\n");
        if(l1 == l2 && l2 == l3){
            printf("triângulo equilátero!\n");
        }
        else if(l1 == l2 || l1 == l3 || l2 == l3){
            printf("triângulo isósceles!\n");
        }
        else if(l1 != l2 && l1 != l3 && l2 != l3){
            printf("triângulo escaleno!\n");
        }
    }
    else{
        printf("não forma triângulo!\n");
    }
    return 0;
}
