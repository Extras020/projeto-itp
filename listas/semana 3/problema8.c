#include <stdio.h>
#include <stdlib.h>

int main()
{
    float l1, l2, l3;
    scanf("%f %f %f", &l1, &l2, &l3);
    if(l1+l2>l3 || l2+l3>l1 || l1+l3>l2){
        printf("forma tri�ngulo!\n");
        if(l1 == l2 && l2 == l3){
            printf("tri�ngulo equil�tero!\n");
        }
        else if(l1 == l2 || l1 == l3 || l2 == l3){
            printf("tri�ngulo is�sceles!\n");
        }
        else if(l1 != l2 && l1 != l3 && l2 != l3){
            printf("tri�ngulo escaleno!\n");
        }
    }
    else{
        printf("n�o forma tri�ngulo!\n");
    }
    return 0;
}
