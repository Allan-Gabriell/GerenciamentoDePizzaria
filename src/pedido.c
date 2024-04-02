#include "../include/pedido.h"
#include "../include/pizzas.h"
#include <stdio.h>
#include <stdlib.h>
/*
struct order{
    char name[100]; // Nome do Cliente - Identificação
    int qntOrder;   // Total de Pedido
    Pizza *list;    // Lista de Pizzas Pedidas
};

struct pizzaorder{  // Fila de Pizzas
    Order orders;
    struct pizzaorder *next;
};

PizzaOrder *create_order(){  //Criar fila vazia
    return NULL;
}
int empty_queue(PizzaOrder *queue){ // Fila Vazia
    return (queue == NULL);
}

PizzaOrder *addorder(PizzaOrder *queue, Order neworder){ //Adicionar nova ordem
    PizzaOrder *new = (PizzaOrder *) malloc (sizeof(PizzaOrder));
    new->orders = neworder;
    new->next = NULL;
    if (empty_queue(queue)){
        return new;
    }
    PizzaOrder *aux = queue;
    while (aux->next != NULL){
        aux = aux->next;
    }
    aux->next = new;
    return queue;
}

PizzaOrder *removeorder(PizzaOrder *queue){
    if (empty_queue(queue)){
        printf("Pedidos Vazios.\n");
        return NULL;
    }
    PizzaOrder *aux = queue;
    queue = queue->next;
    free(queue);
    return queue;
}

void print_order (PizzaOrder *queue){
    PizzaOrder *aux = queue;
    while (aux !=NULL){
        printf("%s");
        aux = aux->next;
    }
}

*/