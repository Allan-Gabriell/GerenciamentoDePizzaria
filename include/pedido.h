#include "../include/pizzas.h"
struct order {
    char nameClient[100];
    float qtdOrder;
    Node *pizza;
};
typedef struct pizzaOrderNode PizzaOrderNode;
typedef struct pizzaOrderList PizzaOrderList;
typedef struct order Order;
typedef struct queueNode QueueNode;
typedef struct queue Queue;

Queue* createQueue();
void enqueue(Queue* queue, Order order);
Order dequeue(Queue* queue);
int isEmpty(Queue* queue);
void Enqueue(Queue* queue, Node *pizzaList);
Order dequeueorder(Queue *queue);
