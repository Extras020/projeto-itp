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
    printf("diferen�a: %d\n", a - b);
    printf("produto: %d\n", a * b);
    printf("divis�o: %f\n", divisao);
    printf("resto da divis�o inteira: %d\n", a % b);
    printf("media: %f\n", media);
    return 0;
}
