#include "../include/pedido.h"

struct order {
    char nameClient[100];
    float price; // Adicionando o campo price para armazenar o preço total do pedido
    int qtdPizzas;
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
    Queue *listOrder = loadOrder();
    Node *listPizzas = loadPizzas();
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
    scanf("%d", &newNode->data.qtdPizzas);

    newNode->data.pizza = NULL;
    newNode->data.price = 0; // Inicializando o preço total como zero
    for (i = 0; i < newNode->data.qtdPizzas; i++)
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

            // Atualiza o preço total do pedido
            newNode->data.price += pizza->pizza.price;
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
    printOrdertxt(queue);
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

void dequeue(Queue *queue) {
    if (queue->front == NULL) {
        printf("Fila vazia, não é possível remover.\n");
        return;
    }

    QueueNode *temp = queue->front;
    queue->front = queue->front->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp);

    printQueue(queue);
    printOrdertxt(queue);

    printf("Primeiro pedido removido com sucesso!\n");
}

Node* searchPizzaOrderByFlavor(Node* head, char* flavor) {
    Node* current = head;
    while (current != NULL) {
        if (strcmp(current->pizza.flavor, flavor) == 0) {
            return current;
        }
        printf("Sabor: %s %s\n", current->pizza.flavor, flavor);
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

void printOrdertxt(Queue *queue){
    FILE *Ordertxt = fopen("pizzaria.txt", "w");
    if(Ordertxt == NULL){
        printf("Erro ao abrir o arquivo! \n");
        return;
    } 

    QueueNode *current = queue->front;
    Node *aux;
    while (current != NULL) {
        fprintf(Ordertxt, "%s\n", current->data.nameClient);
        fprintf(Ordertxt, "%d\n", current->data.qtdPizzas);
        aux = current->data.pizza;
        while (aux != NULL) {
            fprintf(Ordertxt, "%s %s\n", aux->pizza.flavor, aux->pizza.size); // Adiciona um espaço entre o sabor e o tamanho
            aux = aux->next;
        }
        // Escreve o preço total do pedido no arquivo
        fprintf(Ordertxt, "Preço total: %.2f\n", current->data.price);
        current = current->next;
        fprintf(Ordertxt, "\n");
    }
    
    fclose(Ordertxt);
}


Queue *loadOrder(){
    FILE *Ordertxt = fopen("pizzaria.txt", "r");
    if(Ordertxt == NULL){
        printf("Erro ao abrir o arquivo! \n");
        return NULL;
    } 

    Queue *queue = createQueue();
    QueueNode *rear = NULL;

    while (1) {
        QueueNode *newQueueNode = (QueueNode *) malloc(sizeof(QueueNode));
        if (newQueueNode == NULL) {
            printf("Erro ao alocar memória! \n");
            exit(1);
        }

        if (fscanf(Ordertxt, "%s", newQueueNode->data.nameClient) != 1) {
            free(newQueueNode);
            break; // Se falhar a leitura do nome do cliente, sai do loop
        }

        fscanf(Ordertxt, "%d", &newQueueNode->data.qtdPizzas); 
        newQueueNode->data.pizza = NULL;

        for(int i = 0; i < newQueueNode->data.qtdPizzas; i++) {
            Node *newNode = (Node *) malloc(sizeof(Node));
            if (newNode == NULL) {
                printf("Erro ao alocar memória! \n");
                exit(1);
            }

            char flavor[40], size[5];
            fscanf(Ordertxt, "%s %s", flavor, size);
            strcpy(newNode->pizza.flavor, flavor);
            strcpy(newNode->pizza.size, size);

            newNode->next = newQueueNode->data.pizza;
            newQueueNode->data.pizza = newNode;
        }

        // Lê e ignora a linha que contém o preço total do pedido
        char temp[100];
        fscanf(Ordertxt, "%[^\n]", temp);

        newQueueNode->next = NULL;
        if (queue->front == NULL) {
            queue->front = newQueueNode;
        } else {
            rear->next = newQueueNode;
        }
        rear = newQueueNode;
    }

    fclose(Ordertxt);
    return queue;
}
