#ifndef PIZZAS_H_INCLUDED
#define PIZZAS_H_INCLUDED

#include <stdio.h>
struct pizza{
    char flavor[50];
    char description[500];
    float price;
    char size[5];
    int qtdInStock;
    int qtdInStocktotal;
};

typedef struct pizza Pizza;
typedef struct node Node;

Node *addPizza(Node *list, FILE *file);
void printList(Node *list);
Node *removePizza(Node *list, FILE *file);
void editPizza(Node *list, FILE *file);
void searchPizzaByName(Node *list);
void printTxt(Node *list, FILE *file);

Node *loadPizzas(FILE *file);
void clearFileContents(const char *filename);
void printListPizzas(Node *list);
#endif // PIZZAS_H_INCLUDED