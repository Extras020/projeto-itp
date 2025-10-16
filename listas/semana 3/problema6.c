#include <stdio.h>
#include <stdlib.h>

int main()
{
    char febre = 'N', dor_de_cabeca = 'N', dor_no_corpo = 'N', tosse = 'N';
    scanf("%c", &febre);
    scanf(" %c", &dor_de_cabeca);
    scanf(" %c", &dor_no_corpo);
    scanf(" &c", &tosse);
    while(febre != 'S' && febre != 'N'){
        printf("digite uma resposta válida para febre!\n");
        scanf(" %c", &febre);
    }
    while(dor_de_cabeca != 'S' && dor_de_cabeca != 'N'){
        printf("digite uma resposta válida para dor de cabeça!\n");
        scanf(" %c", &dor_de_cabeca);
    }
    while(dor_no_corpo != 'S' && dor_no_corpo != 'N'){
        printf("digite uma resposta válida para dor no corpo!\n");
        scanf(" %c", &dor_no_corpo);
    }
    while(tosse != 'S' && tosse != 'N'){
        printf("digite uma resposta válida para tosse!\n");
        scanf(" %c", &tosse);
    }
    if(febre == 'S' && dor_de_cabeca == 'S' && dor_no_corpo == 'S'){
        printf("Possível gripe!\n");
    }
    else if(tosse == 'S' && febre == 'S'){
        printf("Possível resfriado!\n");
    }
    else if(dor_de_cabeca == 'S'){
        printf("possível enxaqueca!\n");
    }
    else if(febre == 'S'){
        printf("Consulte um médico!\n");
    }
    else if(febre == 'N' && dor_de_cabeca == 'N' && dor_no_corpo == 'N' && tosse == 'N'){
        printf("Você parece estar bem!\n");
    }
    else{
        printf("consulte um médico para avaliação!\n");
    }
    return 0;
}
