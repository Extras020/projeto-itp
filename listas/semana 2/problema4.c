#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, resto;
    float media, divisao;
    scanf("%d %d", &a, &b);
    divisao = (float)a/b;
    media = (a + b)/2.0;
    printf("soma: %d\n", a + b);
    printf("diferença: %d\n", a - b);
    printf("produto: %d\n", a * b);
    printf("divisão: %f\n", divisao);
    printf("resto da divisão inteira: %d\n", a % b);
    printf("media: %f\n", media);
    return 0;
}
