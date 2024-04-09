#include "../include/funcoes.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int containsOnlyLetters(char *str){
    for(int index =0; str[index] != '\0'; index++){
        if(!isalpha(str[index]) && str[index] != ' '){
            return 0;
        }
    }
    return 1;
}
