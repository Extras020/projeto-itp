#include <stdio.h>
#include <stdlib.h>

int main()
{
    float n1, n2, n3, nfinal, media;
    scanf("%f %f %f", &n1, &n2, &n3);
    media = (n1+n2+n3)/3.0;
    if(media >= 7.0){
        printf("aprovado\n");
    }
    else if(media < 4.0){
        printf("reprovado\n");
    }
    else if(media >= 4.0 && media < 7.0){
        printf("recuperação\n");
        nfinal = 10 - media;
        printf("nota necessária na prova final: %.2f\n", nfinal);
    }
    return 0;
}
