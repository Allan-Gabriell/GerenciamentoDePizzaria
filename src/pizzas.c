#include "../include/pedido.h"
#include "../include/pizzas.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int qtdInStocktotal = 0;

struct node{
    Pizza pizza;
    struct node *next;
};

Node *addPizza(Node *list, FILE *file){
    char decision[3];
    do {
        Pizza newPizza;

        printf("Informe o sabor da pizza: ");
        scanf(" %[^\n]", newPizza.flavor);
        printf("Informe o valor da pizza: ");
        scanf("%f", &newPizza.price);
        printf("Informe uma descrição da pizza: \n");
        scanf(" %[^\n]", newPizza.description);
        printf("Informe a quantidade em estoque: ");
        scanf("%d", &newPizza.qtdInStock);

        Node *newNode = (Node *) malloc(sizeof(Node));
        if(newNode == NULL){
            printf("Erro ao alocar memoria");
            return list;
            exit(1);
        }
        if(newNode != NULL){
            newNode->pizza = newPizza;
            newNode->next = list;
            list = newNode;

            printf("Novo sabor adicionado com sucesso!\n");
        } else {
            printf("Erro ao adicionar novo sabor!\n");
        }

        qtdInStocktotal += newPizza.qtdInStock;

        printf("Deseja adicionar mais sabor? (S/N): ");
        scanf(" %[^\n]", decision);

    }while(strcmp(decision, "s") == 0 || strcmp(decision, "S") == 0 || strcmp(decision, "Sim") == 0 || strcmp(decision, "sim") == 0 || strcmp(decision, "SIM") == 0);

    printTxt(list, file);
    return list;
}

int listNull(Node *list){
    return (list == NULL);
}

void printList(Node *list){
    if(listNull(list)){
        printf("Lista vazia!\n");
        return;
    }

    printf("Lista de pizzas:\n");
    Node *aux = list;
    while(aux != NULL){
        printf("Sabor: %s\n", aux->pizza.flavor);
        printf("Valor: %.2f\n", aux->pizza.price);
        printf("Descrição: %s\n", aux->pizza.description);
        printf("Quantidade em estoque: %d\n", aux->pizza.qtdInStock);
        printf("\n");
        aux = aux->next;
    }
    printf("Quantidade em estoque total: %d\n", qtdInStocktotal);
}

Node *removePizza(Node *list, FILE *file){
    char decision[3];
    do {
        char flavor[50];
        printf("Informe o sabor da pizza a ser removida: ");
        scanf(" %[^\n]", flavor);

        Node *aux = list;
        Node *prev = NULL;
        while(aux != NULL){
            if(strcmp(aux->pizza.flavor, flavor) == 0){
                if(prev == NULL){
                    list = aux->next;
                } else {
                    prev->next = aux->next;
                }
                free(aux);
                printf("Sabor removido com sucesso!\n");
                break;
            }
            prev = aux;
            aux = aux->next;
        }
        if(aux == NULL){
            printf("Sabor não encontrado!\n");
        }

        printf("Deseja remover outro sabor? (s/n) \n");
        scanf(" %[^\n]", decision);
    } while(strcmp(decision, "s") == 0 || strcmp(decision, "S") == 0 || strcmp(decision, "sim") == 0 || strcmp(decision, "Sim") == 0 || strcmp(decision, "SIM") == 0);

    printTxt(list, file);
    return list;
}

void editPizza(Node *list, FILE *file){
    char decision[3];
    int newQtdInStock;
    do {
        char flavor[50];
        printf("Informe o sabor da pizza a ser editada: ");
        scanf(" %[^\n]", flavor);

        Node *aux = list;
        while(aux != NULL){
            if(strcmp(aux->pizza.flavor, flavor) == 0){
                printf("Informe o novo valor: ");
                scanf("%f", &aux->pizza.price);
                printf("Informe a nova descrição: ");
                scanf(" %[^\n]", aux->pizza.description);
                printf("Deseja adicionar mais pizzas ao estoque? ");
                scanf(" %[^\n]", decision);
                if(strcmp(decision, "s") == 0 || strcmp(decision, "S") == 0 || strcmp(decision, "sim") == 0 || strcmp(decision, "Sim") == 0 || strcmp(decision, "SIM") == 0){
                    printf("Informe a quantidade a ser adicionada: ");
                    scanf("%d", &newQtdInStock);
                        aux->pizza.qtdInStock += newQtdInStock;
                        qtdInStocktotal += newQtdInStock;
                }
                printf("Sabor editado com sucesso!\n");
                break;
            }
            aux = aux->next;
        }
        if(aux == NULL){
            printf("Sabor não encontrado!\n");
        }

        printTxt(list, file);

        printf("Deseja editar outro sabor? (s/n) \n");
        scanf(" %[^\n]", decision);
    } while(strcmp(decision, "s") == 0 || strcmp(decision, "S") == 0 || strcmp(decision, "sim") == 0 || strcmp(decision, "Sim") == 0 || strcmp(decision, "SIM") == 0);
}

void searchPizzaByName(Node *list){
    char decision[3];
    do {
        char flavor[50];
        printf("Informe o sabor da pizza a ser buscada: ");
        scanf(" %[^\n]", flavor);

        Node *aux = list;
        while(aux != NULL){
            if(strcmp(aux->pizza.flavor, flavor) == 0){
                printf("Sabor: %s\n", aux->pizza.flavor);
                printf("Valor: %.2f\n", aux->pizza.price);
                printf("Descrição: %s\n", aux->pizza.description);
                printf("Quantidade em estoque: %d\n", aux->pizza.qtdInStock);
                printf("\n");
                break;
            }
            aux = aux->next;
        }
        if(aux == NULL){
            printf("Sabor não encontrado!\n");
        }

        printf("Deseja buscar outra pizza? (s/n) \n");
        scanf(" %[^\n]", decision);
    } while(strcmp(decision, "s") == 0 || strcmp(decision, "S") == 0 || strcmp(decision, "sim") == 0 || strcmp(decision, "Sim") == 0 || strcmp(decision, "SIM") == 0);
}

void printTxt(Node *list, FILE *file){
    Node *newList = list;

    if(list == NULL){
        fprintf(file, "\n");
        return;
    } else {
        fprintf(file, "Lista de pizzas:\n");
        fprintf(file, "Sabor: %s\n", list->pizza.flavor);
        fprintf(file, "Valor: %.2f\n", list->pizza.price);
        fprintf(file, "Descrição: %s\n", list->pizza.description);
        fprintf(file, "Quantidade em estoque: %d\n", list->pizza.qtdInStock);
        fprintf(file, "Estoque total: %d\n", qtdInStocktotal);
    }
    printTxt(newList->next, file);
}