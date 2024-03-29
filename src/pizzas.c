#include "../include/pedido.h"
#include "../include/pizzas.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct node{
    Pizza pizza;
    struct node *next;
};

Node *addPizza(Node *list){
    char decision[3];
    do {
        Pizza newPizza;

        printf("Informe o sabor da pizza: ");
        scanf(" %[^\n]", newPizza.flavor);

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

        printf("Deseja adicionar mais sabor? (S/N): ");
        scanf(" %[^\n]", decision);

    }while(strcmp(decision, "s") == 0 || strcmp(decision, "S") == 0 || strcmp(decision, "Sim") == 0 || strcmp(decision, "sim") == 0 || strcmp(decision, "SIM") == 0);

    return list;
}
