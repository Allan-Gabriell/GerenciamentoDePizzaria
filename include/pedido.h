#ifndef PEDIDO_H
#define PEDIDO_H

#include "../src/pizzas.c"


typedef struct order Order;
typedef struct queueNode QueueNode;
typedef struct queue Queue;

Queue* createQueue();
void enqueue(Queue *queue);
Node *orderListPizza(Node * list, Pizza new);
Node* searchPizzaOrderByFlavor(Node* head, char* flavor);
void printQueue(Queue *queue);
void printOrdertxt(Queue *queue);
Queue *loadOrder();
void dequeue(Queue *queue);

#endif //PEDIDO