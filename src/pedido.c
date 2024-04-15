#include "../include/pedido.h"

 struct order {
    char client[100];
    struct node *pizzasOrded; 
    float order_total;
};

void makeOrder() {
    Node *pizzasAvailable = loadPizzas();

    if (pizzasAvailable == NULL) {
        printf("Não há pizzas disponíveis no momento.\n");
        return;
    }

    Order newOrder;
    printf("Informe o nome do cliente: ");
    scanf("%s", newOrder.client);

    printf("Pizzas disponíveis:\n");
    printListPizzas();

    char flavor_Pizza[50];
    char size_Pizza[5];
    int qnt;
    char continue_Order;
    Node *pizzasOrded= NULL;

    do {
        printf("Informe o sabor da pizza desejada: ");
        scanf("%s", flavor_Pizza);

        printf("Informe o tamanho da pizza (P, M, G, F): ");
        scanf("%s", size_Pizza);

        printf("Informe a quantidade desejada: ");
        scanf("%d", &qnt);

        Node *pizza = findPizza(pizzasAvailable, flavor_Pizza, size_Pizza);
        if (pizza != NULL && pizza->pizza.qtdInStock >= qnt) {
            Node *newPizzaOrded = (Node *)malloc(sizeof(Node));
            newPizzaOrded ->pizza = pizza->pizza;
            newPizzaOrded ->pizza.qtdInStock = qnt;
            newPizzaOrded ->next = NULL;

            if (pizzasOrded == NULL) {
                pizzasOrded = newPizzaOrded ;
            } else {
                Node *temp = pizzasOrded;
                while (temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = newPizzaOrded ;
            }

            pizza->pizza.qtdInStock -= qnt;
        } else {
            printf("Pizza não disponível ou quantidade insuficiente.\n");
        }

        printf("Deseja adicionar mais pizzas ao pedido? (S/N): ");
        scanf(" %c", &continue_Order);
    } while (continue_Order == 'S' || continue_Order == 's');

    float totalOrder = calOrdertotal(pizzasOrded);

    saveOrder(newOrder, pizzasOrded, totalOrder);

    printTxt(pizzasAvailable);

    free(pizzasOrded);
}
Node *findPizza(Node *list_Pizza, char *flavor, char *size) {
    Node *aux = list_Pizza;
    while (aux != NULL) {
        if (strcmp(aux->pizza.flavor, flavor) == 0 && strcmp(aux->pizza.size, size) == 0) {
            return aux;
        }
        aux = aux->next;
    }
    return NULL; 
}

float calOrdertotal(Node *pizzasOrded) {
    float total = 0;
    Node *aux = pizzasOrded;
    while (aux != NULL) {
        total += aux->pizza.price * aux->pizza.qtdInStock;
        aux = aux->next;
    }
    return total;
}

void saveOrder(Order order, Node *pizzasOrded, float totalOrder) {
    FILE *file = fopen("pizzaria.txt", "a");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo pizzaria.txt.\n");
        return;
    }

    fprintf(file, "Cliente: %s\n", order.client);
    fprintf(file, "Pizzas pedidas:\n");
    Node *aux = pizzasOrded;
    while (aux != NULL) {
        fprintf(file, " - Sabor: %s, Tamanho: %s, Quantidade: %d, Preço(Unidade): %.2f\n", aux->pizza.flavor, aux->pizza.size, aux->pizza.qtdInStock, aux->pizza.price);
        aux = aux->next;
    }
    fprintf(file, "Total do pedido: R$ %.2f\n", totalOrder);
    fprintf(file, "----------------------------------\n");

    fclose(file);
}

void removeOrder() {
    FILE *fileInput = fopen("pizzaria.txt", "r");
    FILE *fileAux = fopen("temp.txt", "w");

    if (fileInput == NULL || fileAux  == NULL) {
        printf("Erro ao abrir os arquivos.\n");
        return;
    }

    char line[1000];
    int numOrderReaded;
    int firstOrder = 1; 

    while (fgets(line, sizeof(line), fileInput)) {
        if (sscanf(line, "Pedido #%d", &numOrderReaded) == 1 && firstOrder) {
            firstOrder = 0;
            while (fgets(line, sizeof(line), fileInput) && strcmp(line, "----------------------------------\n") != 0);
        } else {
            fputs(line, fileAux);
        }
    }

    fclose(fileInput);
    fclose(fileAux);

    remove("pizzaria.txt");
    rename("temp.txt", "pizzaria.txt");

    printf("Primeiro pedido removido com sucesso.\n");
}

