#include <stdio.h>
#include <string.h>

void remove_nova_linha(char string[]){
    int i = 0;
    while(string[i] != '\0'){
        if(string[i] == '\n'){
            string[i] = '\0';
            return;
        }
        i++;
    }
}
