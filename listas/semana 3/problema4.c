#include <stdio.h>
#include <stdlib.h>

int main()
{
    char jogador_um, jogador_dois;
    scanf("%c", &jogador_um);
    scanf(" %c", &jogador_dois);
    while(jogador_um != 'P' && jogador_um != 'A' && jogador_um != 'T'){
        printf("digite uma jogada válida!\n");
        scanf(" %c", &jogador_um);
    }
    while(jogador_dois != 'P' && jogador_dois != 'A' && jogador_dois != 'T'){
        printf("digite uma jogada válida!\n");
        scanf(" %c", &jogador_dois);
    }
    if(jogador_um == jogador_dois){
        printf("empate!\n");
    }
    else if(jogador_um == 'P'){
        if(jogador_dois == 'A'){
            printf("jogador dois venceu!\n");
        }
        else if(jogador_dois == 'T'){
            printf("jogador um venceu!\n");
        }
    }
    else if(jogador_um == 'A'){
        if(jogador_dois == 'P'){
            printf("jogador um venceu!\n");
        }
        else if(jogador_dois == 'T'){
            printf("jogador dois venceu!\n");
        }
    }
    else if(jogador_um == 'T'){
        if(jogador_dois == 'A'){
            printf("jogador um venceu!\n");
        }
        else if(jogador_dois == 'P'){
            printf("jogador dois venceu!\n");
        }
    }
    return 0;
}
