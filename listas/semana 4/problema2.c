#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float ax, ay, comprimento, bx, by;
    int n, i, verifica = 0;
    scanf("%f %f %f %d", &ax, &ay, &comprimento, &n);
    for(i = 0; i < n; i++){
        scanf("%f %f", &bx, &by);
        if(sqrt((bx-ax)*(bx-ax)+(by-ay)*(by-ay)) <= comprimento){
            ax = 2*bx-ax;
        }
        else{
            printf("N\n");
            return 0;
        }
    }
    printf("S\n");
    return 0;
}
