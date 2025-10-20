#include <stdio.h>
#include <string.h>

int main(){
    char campo[20];
    int i, indice, bombas = 0;
    for(i = 0; i < 20; i++){
         printf("%d:", i);
         scanf("%c", &campo[i]);
         getchar();
    }
    scanf("%d", &indice);
    if(campo[indice] == 'x') printf("bum!");
    else{
        if(campo[indice-1] == 'x') bombas++;
        if(campo[indice+1] == 'x') bombas++;
        printf("%d\n", bombas);
    }
    return 0;
}
