#include "../include/pedido.h"
#include "../include/pizzas.h"
#include <stdio.h>
#include <stdlib.h>

struct order{
    char client_name[100];    // Identificação
    float qntOrder;           // Total de Pedido
    Pizza *list;              // Lista de Pizzas Pedidas
    struct order *next;
};

struct orderpizza{  
    Order *start;
    Order *end;
};

OrderPizza* create_order(void){
    OrderPizza*queue = (OrderPizza*) malloc (sizeof(OrderPizza));
    queue->start = NULL;
    queue->end = NULL;
    return queue;
}

void new_pizzaorder (OrderPizza *queue, Node *pizzaList){
    Order *neworder = (Order*) malloc (sizeof(Order));
    int pizzaqnt;

    printf("Informe seu nome: ");
    scanf(" %[^\n]", neworder ->client_name );
    printf("Informe a quantidade de pizzas que deseja pedir: ");
    scanf("%d", &pizzaqnt);

    // Imprima a lista de pizzas
    printList(pizzaList);
    
    /*
    neworder->next = NULL;
    if (queue->end!=NULL) {
        queue->end->next = neworder;
    } else {
        queue->start = neworder;;
    }
    queue->end = neworder;
    */
}

int empty_pizzaorder (OrderPizza *queue){
    return (queue->start==NULL);
}
void print_pizzaorder (OrderPizza *queue){
    Order *aux;
    for (aux=queue->start; aux!=NULL; aux=aux->next){
        /*
        imprimir ordem
        */
    }
}