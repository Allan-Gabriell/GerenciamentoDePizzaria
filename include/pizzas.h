#include <stdio.h>

typedef enum size Size;

struct pizza{
    char flavor[50];
    char description[500];
    float price;
    int qtdInStock;
    int qtdInStocktotal;
};

typedef struct pizza Pizza;
typedef struct node Node;

Node *addPizza(Node *list, FILE *file);
int listNull(Node *list);
void printList(Node *list);
Node *removePizza(Node *list, FILE *file);
void editPizza(Node *list, FILE *file);
void searchPizzaByName(Node *list);
void printTxt(Node *list, FILE *file);

Node *loadPizzas(FILE *file);