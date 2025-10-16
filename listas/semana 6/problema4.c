#include <stdio.h>
#include <stdlib.h>


int main()
{
    int vet[10];
    int visitadas[10] = {0};
    int i, a, dica, atual;
    for(i = 0; i < 10; i++){
        scanf("%d", &dica);
        vet[i] = dica;
    }
    atual = 0;
    while(visitadas[atual] == 0){
        visitadas[atual] = 1;
        atual = vet[atual];
    }
    printf("%d\n", atual);
    return 0;
}
