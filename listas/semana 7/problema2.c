#include <stdio.h>
#include <string.h>

int main(){
    char palavra[12];
    fgets(palavra, 12, stdin);
    int i;
    for(i = 0; i < 11; i++){
        if(i < 3){
            if(palavra[i] >= 'A' && palavra <= 'Z'){
                continue;
            }
            else{
                printf("invalido!");
                break;
            }
        }
        if(i == 3){
            if(palavra[i] == '-' || palavra[i] >= 0){
                continue;
            }
            else{
                printf("invalido!");
            }
        }
    }
    return 0;
}
