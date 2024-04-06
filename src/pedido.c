#include "../include/pedido.h"
#include "../include/pizzas.h"
#include <stdio.h>
#include <stdlib.h>

struct order{
    char client_name[100];    // Identificação
    int qntOrder;             // Total de Pedido
    Pizza *list;              // Lista de Pizzas Pedidas
};
// Fila de Pizzas
struct orderpizza{  
    Order orders;
    struct orderpizza *next;
};
//Criar fila vazia
OrderPizza *create_order(){  
    return NULL;
}
// Fila Vazia
int empty_queue(OrderPizza *queue){
    return (queue == NULL);
}
//Adicionar novo pedido
OrderPizza *add_order(OrderPizza *queue, Order neworder){ 
    OrderPizza *new = (OrderPizza *) malloc (sizeof(OrderPizza));
    new->orders = neworder;
    new->next = NULL;
    if (empty_queue(queue)){
        return new;
    }
    OrderPizza *aux = queue;
    while (aux->next != NULL){
        aux = aux->next;
    }
    aux->next = new;
    return queue;
}
//Remover pedido
OrderPizza *remove_order(OrderPizza *queue){ 
    if (empty_queue(queue)){
        printf("Pedidos Vazios.\n");
        return NULL;
    }
    OrderPizza *aux = queue;
    queue = queue->next;
    free(queue);
    return queue;
}
//Imprimir Pedido
void print_order (OrderPizza *queue){ 
    OrderPizza *aux = queue;
    while (aux !=NULL){
        printf("%s");
        aux = aux->next;
    }
}

