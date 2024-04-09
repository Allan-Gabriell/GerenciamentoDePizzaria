#include "../include/sistema.h"

int containsOnlyLetters(char *str){
    for(int index =0; str[index] != '\0'; index++){
        if(!isalpha(str[index]) && str[index] != ' '){
            return 0;
        }
    }
    return 1;
}

void capitalizeFirstLetter(char *str) {
    if(str == NULL) {
        return;
    }

    int len = strlen(str);
    for(int i = 0; i < len; i++) {
        // Capitalize the first character of the string and after each space
        if(i == 0 || str[i-1] == ' ') {
            str[i] = toupper((unsigned char) str[i]);
        }
    }
}
