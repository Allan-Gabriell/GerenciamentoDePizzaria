#include "../include/pedido.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct queueNode {
    Order data;
    struct queueNode *next;
};

struct queue {
    struct queueNode *front;
    struct queueNode *rear;
};

Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (queue == NULL) {
        fprintf(stderr, "Erro ao alocar memória para a fila\n");
        exit(1);
    }
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

void enqueue(Queue* queue, Order order) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    if (newNode == NULL) {
        fprintf(stderr, "Erro ao alocar memória para o novo nó\n");
        exit(1);
    }
    newNode->data = order;
    newNode->next = NULL;
    
    if (isEmpty(queue)) {
        queue->front = newNode;
    } else {
        queue->rear->next = newNode;
    }
    queue->rear = newNode;
}

Order dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        fprintf(stderr, "Fila vazia, não é possível remover\n");
        exit(1);
    }
    QueueNode* temp = queue->front;
    Order data = temp->data;
    queue->front = queue->front->next;
    free(temp);
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    return data;
}

int isEmpty(Queue* queue) {
    return queue->front == NULL;
}

struct pizzaOrderNode {
    Node *pizzaNode;
    struct pizzaOrderNode *next;
};

struct pizzaOrderList {
    struct pizzaOrderNode *head;
};

PizzaOrderList* createPizzaOrderList() {
    PizzaOrderList *list = (PizzaOrderList*)malloc(sizeof(PizzaOrderList));
    if (list == NULL) {
        fprintf(stderr, "Erro ao alocar memória para a lista de pizzas pedidas\n");
        exit(1);
    }
    list->head = NULL;
    return list;
}

void addToPizzaOrderList(PizzaOrderList *list, Node *pizzaNode) {
    PizzaOrderNode *newNode = (PizzaOrderNode*)malloc(sizeof(PizzaOrderNode));
    if (newNode == NULL) {
        fprintf(stderr, "Erro ao alocar memória para o novo nó da lista de pizzas pedidas\n");
        exit(1);
    }
    newNode->pizzaNode = pizzaNode;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
    } else {
        PizzaOrderNode *current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}


void Enqueue(Queue* queue, Node *pizzaList) {
    Order order;
    char pizzaName[100];

    printf("Digite o nome do cliente: ");
    scanf(" %[^\n]", order.nameClient);

    printf("Escolha a pizza desejada: \n");
    printList(pizzaList);

    printf("Digite o nome da pizza desejada: ");
    scanf(" %[^\n]", pizzaName);

}