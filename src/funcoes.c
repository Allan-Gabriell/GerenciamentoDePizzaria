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

int containsOnlyNumbers(int number) {
    while (number != 0) {
        int digit = number % 10;
        if (digit < 0 || digit > 9) {
            return 0; // Não é um dígito válido
        }
        number / 10;
    }
    return 1; // Contém apenas números
}
