#include <stdio.h>
#include <stdlib.h>

void define_vetor(int vet[], int x);

int main()
{
    int n, a, cont = 0;
    printf("informe a quantidade de questões:\n");
    scanf("%d", &n);
    int gabarito[n], respostas[n];
    printf("informe o gabarito:\n");
    define_vetor(gabarito, n);
    printf("informe as respostas:\n");
    define_vetor(respostas, n);
    for(a = 0; a < n; a++){
        if(gabarito[a] == respostas[a]) cont++;
    }
    printf("%d acerto(s)\n", cont);
    return 0;
}
void define_vetor(int vet[], int x){
    int i;
    for(i = 0; i < x; i++){
        scanf("%d", &vet[i]);
        while(vet[i] < 1 || vet[i] > 5){
            printf("respostas entre 1 e 5, digite uma resposta válida!\n");
            scanf("%d", &vet[i]);
        }
    }
}
