#include "../include/pizzas.h"

struct pizza{
    char flavor[50];
    char description[500];
    float price;
    char size[5];
    int qtdInStock;
};

struct node{
    Pizza pizza;
    struct node *next;
};

Node *addPizza() {
    char decision[3];
    Node *list = loadPizzas();
    printList(list);
    do {
        Pizza newPizza;

        do {
            printf("Informe o sabor da pizza: ");
            scanf(" %[^\n]", newPizza.flavor);
            capitalizeFirstLetter(newPizza.flavor);
                if (!containsOnlyLetters(newPizza.flavor)) {
                    printf("\nSó pode conter letras e espaços! Informe novamente.\n");
                }
        } while (!containsOnlyLetters(newPizza.flavor));

        printf("Informe o valor da pizza: ");
        scanf("%f", &newPizza.price);

        do {
            printf("Informe o tamanho da pizza: (P, M, G, F): ");
            scanf(" %[^\n]", newPizza.size);
            capitalizeFirstLetter(newPizza.size);
                if(!containsOnlyLetters(newPizza.size)){
                    printf("\nSó pode conter letras e espaços! Informe novamente.\n");
                }
        }while(!containsOnlyLetters(newPizza.size));
        
        do{
            printf("Informe uma descrição da pizza: \n");
            scanf(" %[^\n]", newPizza.description);
            capitalizeFirstLetter(newPizza.description);
                if(!containsOnlyLetters(newPizza.description)){
                printf("\nSó pode conter letras e espaços! Informe novamente.\n");
            }
        }while(!containsOnlyLetters(newPizza.description));
        
        printf("Informe a quantidade em estoque: ");
        scanf("%d", &newPizza.qtdInStock);

        Node *newNode = (Node *) malloc(sizeof(Node));
        if(newNode == NULL){
            printf("Erro ao alocar memória\n");
            return list;
            exit(1);
        }
        newNode->pizza = newPizza;
        newNode->next = NULL; // Adicionado para garantir que o próximo nó seja NULL

        // Inserir o novo nó em ordem alfabética
        if(list == NULL || strcmp(newPizza.flavor, list->pizza.flavor) < 0){
            newNode->next = list;
            list = newNode;
        } else {
            Node *current = list;
            while(current->next != NULL && strcmp(newPizza.flavor, current->next->pizza.flavor) > 0){
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }

        printf("Novo sabor adicionado com sucesso!\n");
        printList(list);

        do{
            printf("Deseja adicionar mais uma pizza? (S/N): ");
            scanf(" %[^\n]", decision);
            if(!containsOnlyLetters(decision)){
                printf("\nSó pode conter letras e espaços! Informe novamente.\n");
            }
        }while(!containsOnlyLetters(decision));

    } while(strcmp(decision, "s") == 0 || strcmp(decision, "S") == 0 || strcmp(decision, "Sim") == 0 || strcmp(decision, "sim") == 0 || strcmp(decision, "SIM") == 0);

    fflush(stdout);
    printTxt(list);
    return list;
}

void printList(Node *list) {
    if(list == NULL){
        printf("Lista vazia!\n");
        return;
    }

    printf("\nLista de pizzas:\n");
    Node *aux = list;
    while(aux != NULL){
        printf("Sabor: %s\n", aux->pizza.flavor);
        printf("Valor: %.2f\n", aux->pizza.price);
        printf("Tamanho: %s\n", aux->pizza.size);
        printf("Descrição: %s\n", aux->pizza.description);
        printf("Quantidade em estoque: %d\n", aux->pizza.qtdInStock);
        printf("\n");
        aux = aux->next;
    }
}

void printListPizzas() {
    Node *list = loadPizzas();
    if(list == NULL){
        printf("Lista vazia!\n");
        return;
    } else{
        printf("Lista de pizzas:\n");
        Node *current = list;
        while(current != NULL) {
            printf("Sabor: %s\n", current->pizza.flavor);
            printf("Tamanho: %s\n", current->pizza.size);
            printf("Quantidade disponível: %d\n\n", current->pizza.qtdInStock);
            current = current->next;
        }
    }
}


Node *removePizza() {
    char decision[3];
    Node *list = loadPizzas();
    do {
        char flavor[50];
        char size[50];
        printList(list);
         do{
            printf("Informe o sabor da pizza a ser removida: ");
            scanf(" %[^\n]", flavor);
            if(!containsOnlyLetters(flavor)){
                printf("\nSó pode conter letras e espaços! Informe novamente.\n");
            }
        }while(!containsOnlyLetters(flavor));

        printf("Informe o tamanho da pizza a ser removida (P, M, G, F): ");
        scanf(" %[^\n]", size);
        do{
            printf("Informe o tamanho da pizza a ser removida (P, M, G, F): ");
            scanf(" %[^\n]", size);
            if(!containsOnlyLetters(size)){
                printf("\nSó pode conter letras e espaços! Informe novamente.\n");
            }
        }while(!containsOnlyLetters(size));

        Node *aux = list;
        Node *prev = NULL;
        while(aux != NULL){
            if(strcmp(aux->pizza.flavor, flavor) == 0 && strcmp(aux->pizza.size, size) == 0){
                if(prev == NULL){
                    list = aux->next;
                } else {
                    prev->next = aux->next;
                }
                free(aux);
                printf("Sabor removido com sucesso!\n");
                printList(list);
                break;
            }
            prev = aux;
            aux = aux->next;
        }
        if(aux == NULL){
            printf("Sabor não encontrado!\n");
        }

        do{
            printf("Deseja remover mais uma pizza? (S/N): ");
            scanf(" %[^\n]", decision);
            if(!containsOnlyLetters(decision)){
                printf("\nSó pode conter letras e espaços! Informe novamente.\n");
            }
        }while(!containsOnlyLetters(decision));

    } while(strcmp(decision, "s") == 0 || strcmp(decision, "S") == 0 || strcmp(decision, "sim") == 0 || strcmp(decision, "Sim") == 0 || strcmp(decision, "SIM") == 0);

    printTxt(list);
    return list;
}

void editPizza() {
    Node *list = loadPizzas();
    char decision[3];
    char size[50];
    int newQtdInStock;
    do {
        printList(list);
        char flavor[50];

        do{
            printf("Informe o sabor da pizza a ser editada: ");
            scanf(" %[^\n]", flavor);
            if(!containsOnlyLetters(flavor)){
                printf("\nSó pode conter letras e espaços! Informe novamente.\n");
            }
        }while(!containsOnlyLetters(flavor));
        printf("Informe o tamanho da pizza a ser editada (P, M, G, F): ");
        scanf(" %[^\n]", size);

        Node *aux = list;
        while(aux != NULL){
            if(strcmp(aux->pizza.flavor, flavor) == 0 && strcmp(aux->pizza.size, size) == 0){
                printf("Informe o novo valor: ");
                scanf("%f", &aux->pizza.price);
                
                do{
                    printf("Informe a nova descrição: ");
                    scanf(" %[^\n]", aux->pizza.description);
                    capitalizeFirstLetter(aux->pizza.description);
                    if(!containsOnlyLetters(aux->pizza.description)){
                        printf("\nSó pode conter letras e espaços! Informe novamente.\n");
                    }
                }while(!containsOnlyLetters(aux->pizza.description));

                do{
                    printf("Informe o novo tamanho da pizza (P, M, G, F): ");
                    scanf(" %[^\n]", aux->pizza.size);
                    capitalizeFirstLetter(aux->pizza.size);
                    if(!containsOnlyLetters(aux->pizza.size)){
                        printf("\nSó pode conter letras e espaços! Informe novamente.\n");
                    }
                }while(!containsOnlyLetters(aux->pizza.size));

                printf("Deseja adicionar mais pizzas ao estoque? (s/n) ");
                scanf(" %[^\n]", decision);
                if(strcmp(decision, "s") == 0 || strcmp(decision, "S") == 0 || strcmp(decision, "sim") == 0 || strcmp(decision, "Sim") == 0 || strcmp(decision, "SIM") == 0){
                    printf("Informe a quantidade a ser adicionada: ");
                    scanf("%d", &newQtdInStock);
                    aux->pizza.qtdInStock += newQtdInStock;
                }
                printList(list);
                printf("Sabor editado com sucesso!\n");
                break;
            }
            aux = aux->next;
        }
        if(aux == NULL){
            printf("Sabor não encontrado!\n");
        }

        do{
            printf("Deseja editar mais uma pizza? (S/N): ");
            scanf(" %[^\n]", decision);
            if(!containsOnlyLetters(decision)){
                printf("\nSó pode conter letras e espaços! Informe novamente.\n");
            }
        }while(!containsOnlyLetters(decision));

    } while(strcmp(decision, "s") == 0 || strcmp(decision, "S") == 0 || strcmp(decision, "sim") == 0 || strcmp(decision, "Sim") == 0 || strcmp(decision, "SIM") == 0);

    printTxt(list);
}

void searchPizzaByName() {
    Node *list = loadPizzas();
    char decision[3];
    do {
        char flavor[50];
        char size[50];
        
        do{
            printf("Informe o sabor da pizza a ser buscada: ");
            scanf(" %[^\n]", flavor);
            if(!containsOnlyLetters(flavor)){
                printf("\nSó pode conter letras e espaços! Informe novamente.\n");
            }
        }while(!containsOnlyLetters(flavor));

        
        do{
            printf("Informe o tamanho da pizza a ser buscada (P, M, G, F): ");
            scanf(" %[^\n]", size);
            if(!containsOnlyLetters(size)){
                printf("\nSó pode conter letras e espaços! Informe novamente.\n");
            }
        }while(!containsOnlyLetters(size));

        Node *aux = list;
        int found = 0;
        while (aux != NULL) {
            if (strcmp(aux->pizza.flavor, flavor) == 0 && strcmp(aux->pizza.size, size) == 0) {
                printf("Sabor: %s\n", aux->pizza.flavor);
                printf("Valor: %.2f\n", aux->pizza.price);
                printf("Descrição: %s\n", aux->pizza.description);
                printf("Tamanho: %s\n", aux->pizza.size);
                printf("Quantidade em estoque: %d\n", aux->pizza.qtdInStock);
                found = 1;
                break;
            }
            aux = aux->next;
        }
        if (!found) {
            printf("Sabor não encontrado!\n");
        }

        do{
            printf("Deseja buscar mais uma pizza? (S/N): ");
            scanf(" %[^\n]", decision);
            if(!containsOnlyLetters(decision)){
                printf("\nSó pode conter letras e espaços! Informe novamente.\n");
            }
        }while(!containsOnlyLetters(decision));

    } while (strcmp(decision, "s") == 0 || strcmp(decision, "S") == 0 || strcmp(decision, "sim") == 0 || strcmp(decision, "Sim") == 0 || strcmp(decision, "SIM") == 0);
}

void printTxt(Node *list) {
    FILE *file = fopen("pizzas.txt", "w");
    if(file == NULL){
        printf("Erro ao abrir o arquivo");
        return;
    }

    Node *newList = list;

    if(list == NULL){
        fprintf(file, "\n");
        fclose(file);
        return;
    } else {
        while(newList != NULL){
            fprintf(file, "%s\n", newList->pizza.flavor);
            fprintf(file, "%.2f\n", newList->pizza.price);
            fprintf(file, "%s\n", newList->pizza.description);
            fprintf(file, "%s\n", newList->pizza.size);
            fprintf(file, "%d\n", newList->pizza.qtdInStock);
            newList = newList->next;
        }
        fprintf(file, "Fim arquivo\n");
    }

    fclose(file);
}

Node *loadPizzas() {
    FILE *file = fopen("pizzas.txt", "r");
    if(file == NULL){
        printf("Erro ao abrir o arquivo");
        return NULL;
    }

    Pizza newPizza;
    Node *list = NULL;

    while(fscanf(file, " %[^\n]", newPizza.flavor) != EOF){
        fscanf(file, " %f", &newPizza.price);
        fscanf(file, " %[^\n]", newPizza.description);
        fscanf(file, " %[^\n]", newPizza.size);
        fscanf(file, " %d", &newPizza.qtdInStock);
        printf("Entrou\n");
        

        Node *newNode = (Node *) malloc(sizeof(Node));
        if(newNode == NULL){
            printf("Erro ao alocar memoria");
            return list;
            exit(1);
        }
        newNode->pizza = newPizza;

        // Insere o novo nó na lista mantendo a ordem alfabética
        if(list == NULL || strcmp(newPizza.flavor, list->pizza.flavor) < 0){
            newNode->next = list;
            list = newNode; // Atualiza o ponteiro list para apontar para o primeiro nó da lista
        } else {
            Node *current = list;
            while(current->next != NULL && strcmp(newPizza.flavor, current->next->pizza.flavor) > 0){
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }

         // Mova esta linha para aquiRemover pedido
    }
    

    fclose(file);
    return list;
}

