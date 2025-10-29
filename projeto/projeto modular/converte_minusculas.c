#include <stdio.h>
#include <string.h>

void converte_minusculas(char string[]){
    int i = 0;
    while(string[i] != '\0'){
        if(string[i] >= 'a' && string[i] <= 'z'){
            string[i] = string[i] - 32;
        }
        i++;
    }
}
