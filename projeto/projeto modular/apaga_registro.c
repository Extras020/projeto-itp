#include <stdio.h>
#include <stdlib.h>

void apaga_registro(char string[]){
    int i = 0;
    while(string[i] != '\0'){
        string[i] = '\0';
        i++;
    }
}
