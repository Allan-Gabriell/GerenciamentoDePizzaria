#include "../include/pedido.h"

struct order {
    char nameClient[100];
    float qtdOrder;
    Node *pizza;
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

void enqueue(Queue *queue){ // Inserir
    Node *listPizzas = loadPizzas();
    int qtdPizzasOrder;
    char flavor[40];
    char tamanho[5];
    Node *pizza;
    int i;
    QueueNode *newNode = (QueueNode *)malloc(sizeof(QueueNode));
    if (newNode == NULL)
    {
        fprintf(stderr, "Erro ao alocar memória para o novo nó\n");
        exit(1);
    }

    printf("Informe o nome do cliente: ");
    scanf(" %[^\n]", newNode->data.nameClient);
    printf("Quantas pizzas deseja pedir: ");
    scanf("%d", &qtdPizzasOrder);

    newNode->data.pizza = NULL;
    for (i = 0; i < qtdPizzasOrder; i++)
    {
        printf("Informe o sabor da pizza %d: ", i + 1);
        scanf(" %[^\n]", flavor);
        printf("Informe o tamanho da pizza %d: ", i + 1);
        scanf(" %[^\n]", tamanho);
        pizza = searchPizzaOrderByFlavor(listPizzas, flavor);
        if (pizza == NULL) {
            printf("Sabor não encontrado.\n");
            return;
        }
        if (pizza->pizza.qtdInStock > 0)
        {
            newNode->data.pizza = orderListPizza(newNode->data.pizza,pizza->pizza);
            pizza->pizza.qtdInStock--;
        }
        
    }
    
    newNode->next = NULL;

    if (queue->front == NULL)
    {
        queue->front = newNode;
    }
    else
    {
        queue->rear->next = newNode;
    }
    queue->rear = newNode;

    printf("Pedido realizado com sucesso!\n");
    printQueue(queue);
}

Node *orderListPizza(Node * list, Pizza new){
    Node *newNodeOrder = (Node *) malloc(sizeof(Node));
    if(newNodeOrder == NULL){
        printf("Não foi possível alocar memória!\n");
        exit(1);
    }
    newNodeOrder->pizza = new;
    newNodeOrder->next = list;
    return newNodeOrder;
}

Node* searchPizzaOrderByFlavor(Node* head, char* flavor) {
    Node* current = head;
    while (current != NULL) {
        if (strcmp(current->pizza.flavor, flavor) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void printQueue(Queue *queue){
    QueueNode *current = queue->front;
    Node *aux;
    while (current != NULL) {
        printf("Cliente: %s\n", current->data.nameClient);
        aux = current->data.pizza;
        while (aux != NULL) {
            printf("Sabor: %s\n", aux->pizza.flavor);
            printf("Tamanho: %s\n", aux->pizza.size);
            aux = aux->next;
        }
        current = current->next;
    }
}
