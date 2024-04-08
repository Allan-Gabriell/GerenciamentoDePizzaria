#include "../include/pedido.h"
#include "../include/pizzas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    Pizza pizza;
    struct node *next;
};

struct queueNode{
    Order data;
    struct queueNode *next;
};

struct queue{
    struct queueNode *front;
    struct queueNode *rear;
};

Queue *createQueue(){
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    if (queue == NULL)
    {
        fprintf(stderr, "Erro ao alocar memória para a fila\n");
        exit(1);
    }
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

void enqueue(Queue *queue, Order order){ // Inserir
    QueueNode *newNode = (QueueNode *)malloc(sizeof(QueueNode));
    if (newNode == NULL)
    {
        fprintf(stderr, "Erro ao alocar memória para o novo nó\n");
        exit(1);
    }
    newNode->data = order;
    newNode->next = NULL;

    if (isEmpty(queue))
    {
        queue->front = newNode;
    }
    else
    {
        queue->rear->next = newNode;
    }
    queue->rear = newNode;
}

Order dequeue(Queue *queue){ // Desenfileiramento
    if (isEmpty(queue))
    {
        fprintf(stderr, "Fila vazia, não é possível remover\n");
        exit(1);
    }
    QueueNode *temp = queue->front;
    Order data = temp->data;
    queue->front = queue->front->next;
    free(temp);
    if (queue->front == NULL)
    {
        queue->rear = NULL;
    }
    return data;
}

int isEmpty(Queue *queue){ // Fila vazia
    return queue->front == NULL;
}

struct pizzaOrderNode{ // Nó de Pedidos de PIzza
    Node *pizzaNode;
    struct pizzaOrderNode *next;
};

struct pizzaOrderList{ // Padrozinação para Cabeça (?)
    struct pizzaOrderNode *head;
};

PizzaOrderList *createPizzaOrderList(){ // Lista de Pizzas disponíveis
    PizzaOrderList *list = (PizzaOrderList *)malloc(sizeof(PizzaOrderList));
    if (list == NULL)
    {
        fprintf(stderr, "Erro ao alocar memória para a lista de pizzas pedidas\n");
        exit(1);
    }
    list->head = NULL;
    return list;
}

void addToPizzaOrderList(PizzaOrderList *list, Node *pizzaNode){ // Adição para pedido de pizza
    PizzaOrderNode *newNode = (PizzaOrderNode *)malloc(sizeof(PizzaOrderNode));
    if (newNode == NULL)
    {
        fprintf(stderr, "Erro ao alocar memória para o novo nó da lista de pizzas pedidas\n");
        exit(1);
    }
    newNode->pizzaNode = pizzaNode;
    newNode->next = NULL;

    if (list->head == NULL)
    {
        list->head = newNode;
    }
    else
    {
        PizzaOrderNode *current = list->head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

void Enqueue(Queue *queue, Node *pizzaList){
    Order order;
    char pizzaName[100];
    char pizzaSize[5];
    int qntPizza;

    qntPizza = 0;
    printf("Digite o nome do cliente: ");
    scanf(" %[^\n]", order.nameClient);

    printf("Digite a quantidade de pizzas desejadas: ");
    scanf("%d", &qntPizza);

    if (qntPizza <= 0)
    {
        printf("Quantidade inválida de pizzas, não é possível concluir o pedido.\n");
        return;
    }

    while (qntPizza > 0)
    {
        printf("Pizzas disponíveis: \n");
        printList(pizzaList);

        printf("Digite o nome da pizza desejada: ");
        scanf(" %[^\n]", pizzaName);

        printf("Digite o tamanho da pizza desejada (P, M, G, F): ");
        scanf(" %[^\n]", pizzaSize);

         Node *aux = pizzaList;
         while(aux != NULL){
            if(strcmp(aux->pizza.flavor, pizzaName) == 0 && strcmp(aux->pizza.size, pizzaSize) == 0 && (aux->pizza.qtdInStock>0)){
                if(aux->pizza.qtdInStock > 0) {
                    order.pizza = aux;  // pizza = Nó
                    order.qtdOrder = 1;  
                    enqueue(queue, order);  // Adiciona o pedido na fila
                    aux->pizza.qtdInStock--;  
                    printf("Pedido de %s (%s) adicionado com sucesso!\n", pizzaName, pizzaSize);
                    qntPizza--;  
                    break;
                } else {
                    printf("Desculpe, a pizza %s (%s) não está disponível no momento.\n", pizzaName, pizzaSize);
                    return;
                }
            }
            aux = aux->next;
        }
        if(aux == NULL){
            printf("Pizza %s (%s) não encontrada!\n", pizzaName, pizzaSize);
            return;
        }
    }
}
