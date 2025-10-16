#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, i, somatorioa = 0, somatoriob = 0;
    scanf("%d %d", &a, &b);
    for(i = 1; i < a; i++){
        if(a%i == 0){
            somatorioa += i;
        }
    }
    for(i = 1; i < b; i++){
        if(b%i == 0){
            somatoriob += i;
        }
    }
    if(b - somatorioa <= 2 && b - somatorioa >= -2 && a - somatoriob <= 2 && a - somatoriob >= -2){
        printf("S\n");
    }
    else{
        printf("N\n");
    }
    return 0;
}
