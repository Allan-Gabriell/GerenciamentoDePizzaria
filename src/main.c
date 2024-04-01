#include "../include/pedido.h"
#include "../include/pizzas.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

void menu(Node **head, FILE *pizzas){
    char option[10];
    int num;
    char decision[3];

    do{
        printf("===== Bem vindo ao nosso sistema de pizzaria =====\n");
        printf("Por favor informe um número de acordo com a opção!\n");
        printf("      1. Adicionar pizza\n");
        printf("      2. Remover pizza\n");
        printf("      3. Adicionar pedido\n");
        printf("      4. Remover pedido\n");
        printf("      5. Editar informações de pizza\n");
        printf("      6. Buscar pizza por sabor\n");
        printf("      7. Listar pizzas e quantidades disponíveis\n");
        printf("      8. Sair do sistema\n");
        printf("==================================================\n");
        scanf("%s", option);

        int isNumber = 1;
        for(int i = 0; i < strlen(option); i++){
            if(!isdigit(option[i])){
                isNumber = 0;
                break;
            }
        }

        if(isNumber){
            num = atoi(option);
            switch(num){
                case 1:
                    printf("Deseja adicionar uma nova pizza? (s/n) \n");
                    scanf(" %[^\n]", decision);
                    if(strcmp(decision, "s") == 0 || strcmp(decision, "S") == 0 || strcmp(decision, "sim") == 0 || strcmp(decision, "Sim") == 0 || strcmp(decision, "SIM") == 0){
                        *head = addPizza(*head, pizzas);
                    } else {
                        menu(head, pizzas);
                    }
                break;
                case 2:
                    printf("Deseja remover uma pizza? (s/n) \n");
                    scanf(" %[^\n]", decision);
                    if(strcmp(decision, "s") == 0 || strcmp(decision, "S") == 0 || strcmp(decision, "sim") == 0 || strcmp(decision, "Sim") == 0 || strcmp(decision, "SIM") == 0){
                        *head = removePizza(*head, pizzas);
                    } else {
                        menu(head, pizzas);
                    }
                break;
                case 3:
                break;
                case 4:
                break;
                case 5:
                    printf("Deseja editar uma pizza? (s/n) \n");
                    scanf(" %[^\n]", decision);
                    if(strcmp(decision, "s") == 0 || strcmp(decision, "S") == 0 || strcmp(decision, "sim") == 0 || strcmp(decision, "Sim") == 0 || strcmp(decision, "SIM") == 0){
                        editPizza(*head, pizzas);
                    } else {
                        menu(head, pizzas);
                    }
                break;
                case 6:
                    printf("Deseja buscar pizza por sabor? (s/n) \n");
                    scanf(" %[^\n]", decision);
                    if(strcmp(decision, "s") == 0 || strcmp(decision, "S") == 0 || strcmp(decision, "sim") == 0 || strcmp(decision, "Sim") == 0 || strcmp(decision, "SIM") == 0){
                        searchPizzaByName(*head);
                        printList(*head);
                    } else {
                        menu(head, pizzas);
                    }
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
}

int main(void){
    setlocale(LC_ALL,"portuguese");
    FILE *pizzas = fopen("pizzas.txt", "ar+");
    if(pizzas == NULL){
        printf("Detectamos erro no arquivo de texto! \n");
        exit(1);
    }

    Node *pizzaList = NULL;
    menu(&pizzaList, pizzas);
    printTxt(pizzaList, pizzas);

    fclose(pizzas);
    return 0;
}