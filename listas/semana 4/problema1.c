#include <stdio.h>
#include <stdlib.h>

int main()
{
    float comprimento, largura, comp_bolso;
    int cont = 0;
    scanf("%f %f %f", &comprimento, &largura, &comp_bolso);
    while(comprimento > comp_bolso || largura > comp_bolso){
        if(comprimento >= largura && comprimento > comp_bolso){
            comprimento = comprimento / 2.0;
            cont++;
        }
        else{
            largura = largura / 2.0;
            cont++;
        }
    }
    printf("Será necessário dobrar a folha: %d vezes", cont);
    return 0;
}
