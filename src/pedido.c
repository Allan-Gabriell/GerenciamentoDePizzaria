#include "../include/pedido.h"
#include "../include/pizzas.h"
#include <stdio.h>
#include <stdlib.h>

struct order{
    int pizzaId;    // Identificação
    int qntOrder;   // Total de Pedido
    Size size;
    Pizza *list;    // Lista de Pizzas Pedidas
};

struct orderpizza{  // Fila de Pizzas
    Order orders;
    struct orderpizza *next;
};

OrderPizza *create_order(){  //Criar fila vazia
    return NULL;
}
int empty_queue(OrderPizza *queue){ // Fila Vazia
    return (queue == NULL);
}

OrderPizza *addorder(OrderPizza *queue, Order neworder){ //Adicionar nova ordem
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


/*
OrderPizza *created_order(OrderPizza *list){
    Order orders;
    int qtdpizzas;

    printf("Vamos cadastrar um novo pedido! \n");
    printf("Primeiro informe o id do novo pedido: ");
    scanf("%d", &orders.pizzaId);
    getchar();
    printf("Agora informe a quantidade de pizzas que deseja: ");
    scanf("%d", &qtdpizzas);
    getchar();
    for(int i = 0; i < qtdpizzas; i++){
        orders.list = fill_pizza(orders.list);
    }

    OrderPizza *newNode = (OrderPizza*) malloc(sizeof(OrderPizza));
    if(newNode != NULL){
        newNode->orders = orders;
        newNode->next = list;
        list = newNode;
    } else {
        printf("Infelizmente não foi possível adicionar um novo pedido!\n");
    }

    return list;
}

OrderPizza *remove_order(OrderPizza *list){
    OrderPizza *aux = list;
    OrderPizza *aux2 = list;
    int id;

    printf("Informe o id do pedido que deseja remover: ");
    scanf("%d", &id);
    getchar();

    if(list->orders.pizzaId == id){
        list = list->next;
        free(aux);
        printf("Pedido removido com sucesso!\n");
        return list;
    } else {
        while(aux != NULL){
            if(aux->orders.pizzaId == id){
                aux2->next = aux->next;
                free(aux);
                printf("Pedido removido com sucesso!\n");
                return list;
            }
            aux2 = aux;
            aux = aux->next;
        }
        printf("Infelizmente não foi possível remover esse pedido!\n");
        return list;
    }
}
*/