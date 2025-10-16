#include <stdio.h>
#include <stdlib.h>

void define_vetor(int vet[], int x);

int main()
{
    int m, n, a, b, cont = 0;
    printf("informe a quantidade de figurinhas da coleção:\n");
    scanf("%d", &m);
    printf("informe a quantidade de figurinhas que você possui:\n");
    scanf("%d", &n);
    int figurinhas[n];
    printf("informe as figurinhas que você tem:\n");
    define_vetor(figurinhas, n);
    for(b = 1; b <= m; b++){
        cont = 0;
        for(a = 0; a < n; a++){
            if(b == figurinhas[a]){
                cont++;
            }
        }
        if(cont == 0){
            printf("%d ", b);
        }
    }
    return 0;
}
void define_vetor(int vet[], int x){
    int i;
    for(i = 0; i < x; i++){
        scanf("%d", &vet[i]);
    }
}
