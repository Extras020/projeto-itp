#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    float x, y, distancia, x1, y1;
    int pontuacao = 0, i;
    for(i = 1; i <= 10; i++){
        scanf("%f %f", &x, &y);
        distancia = (0 - x)*(0 - x) + (0 - y)*(0 - y);
        distancia = sqrt(distancia);
        if(distancia >= 0 && distancia <= 1) pontuacao += 10;
        else if(distancia > 1 && distancia <= 2) pontuacao += 6;
        else if(distancia > 2 && distancia <= 3) pontuacao += 4;
        if(i > 1){
            distancia = (x1 - x)*(x1 - x)+(y1 - y)*(y1 - y);
            distancia = sqrt(distancia);
            if(distancia >= 0 && distancia <= 1) pontuacao += 5;
            else if(distancia > 1 && distancia <= 2) pontuacao += 3;
            else if(distancia > 2 && distancia <= 3) pontuacao += 2;
        }
        x1 = x;
        y1 = y;
    }
    printf("pontuação total: %d", pontuacao);
    return 0;
}
