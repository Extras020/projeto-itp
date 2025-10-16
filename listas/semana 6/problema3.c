#include <stdio.h>
#include <stdlib.h>


int main()
{
    int n, i, maior, conta_comprimento = 0, marca_maior;
    scanf("%d", &n);
    int vet[n];
    for(i = 0; i < n; i++){
        scanf("%d", &vet[i]);
    }
    maior = vet[0];
    i = 0;
    while(marca_maior != 2){
        if(vet[i] >= maior){
            if(vet[i] != maior){
                conta_comprimento = 0;
                marca_maior = 1;
            }
            else{
                marca_maior++;
            }
            maior = vet[i];
        }
        else{
            conta_comprimento++;
        }
        i++;
    }
    printf("%d\n", conta_comprimento);
    return 0;
}
