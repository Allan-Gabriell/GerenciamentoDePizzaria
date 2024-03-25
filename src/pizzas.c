#include "../include/pedido.h"
#include "../include/pizzas.h"
#include <stdlib.h>
#include <stdio.h>

enum size{
    P = 1, M, G, F
};

enum flavor{
    CALABRESA = 1,
    QUEIJO,
    CATUPIRY_COM_FRANGO,
    MARGUERITA,
    PORTUGUESA,
    PEPERONE,
    FRUTOS_DO_MAR,
    CHOCOLATE,
    BANANA_COM_CANELA,
    BRIGADEIRO,
    ROMEL_E_JULIETA
};
struct pizza{
    Flavor flavor;
    Size size;
    float price;
    int qntInStock;
};

struct listpizza{
    Pizza pizzas;
    struct listpizza *next;
};


ListPizza *fill_pizza(ListPizza *list){
    Pizza pizza;

    printf("Por favor informe o sabor da pizza: \n");
    printf("1 - Calabresa\n");
    printf("2 - Queijo\n");
    printf("3 - Catupiry com frango\n");
    printf("4 - Marguerita\n");
    printf("5 - Portuguesa\n");
    printf("6 - Peperone\n");
    printf("7 - Frutos do mar\n");

    printf("Opções doces \n");

    printf("8 - Chocolate\n");
    printf("9 - Banana com canela\n");
    printf("10 - Brigadeiro\n");
    printf("11 - Romel e Julieta\n");
    scanf("%d", &pizza.flavor);
    getchar();

    printf("Por favor informe o tamanho da pizza: \n");
    printf("1 - P (pequeno)\n");
    printf("2 - M (médio)\n");
    printf("3 - G (grande)\n");
    printf("4 - F (família)\n");
    scanf("%d", &pizza.size);
    getchar();

    ListPizza * newNode = (ListPizza *) malloc(sizeof(ListPizza));
    if(newNode == NULL){
        printf("Não foi possível alocar memória! \n");
        exit(1);
    }

    if(newNode != NULL){
        newNode->pizzas = pizza;
        newNode->next = list;
        list = newNode;
    } else {
        printf("Infelizmente não foi possível adicionar uma nova pizza! \n");
    }

    return list;
}