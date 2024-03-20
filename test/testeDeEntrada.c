#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char option[10];
    int num;

    do {
        printf("===== Bem vindo ao nosso sistema de pizzaria =====\n");
        printf("Por favor informe um número de acordo com a opção!\n");
        printf("      1. Adicionar pizza\n");
        printf("      2. Remover pizza\n");
        printf("      3. Adicionar pedido\n");
        printf("      4. Editar informações de pizza\n");
        printf("      5. Buscar pizza por sabor\n");
        printf("      7. Listar pizzas e quantidade em disponíveis\n");
        printf("      8. Sair do sistema\n");
        fgets(option, 10, stdin);

        int isNumber = 1; // Inicializado com 1 (verdadeiro) até que seja provado o contrário
        for(int i = 0; i < strlen(option) - 1; i++){
            if(!isdigit(option[i])){ // verifica se o digito é um número
                isNumber = 0; // caso não isNumber vai a 0 para indicar que não é um número 
                break;
            }
        }

        if(isNumber) {
            num = atoi(option); //converte uma string para um inteiro 
            switch(num) {
                case 1:
                break;
                case 2:
                break;
                case 3:
                case 4:
                break;
                case 5:
                break;
                case 6:
                break;
                case 7:
                break;
                case 8:
                break;
                default:
                    printf("A opção informada é inválida. Por favor tente novamente!\n");
            }
        } else {
            printf("A opção informada é inválida. Por favor tente novamente!\n");
        }
    } while(num != 8);

    return 0;
}
