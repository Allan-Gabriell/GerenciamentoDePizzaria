#ifndef PEDIDO_H
#define PEDIDO_H

#include "../src/pizzas.c"

//Redifinição da struct order para Order
typedef struct order Order;
// Função para fazer o pedido de uma pizza.
void makeOrder();
// Função para encontrar uma pizza em uma lista de pizzas. Recebe um nó para criação de um auxiliar, além de dois caracters especificando
// Sabor e Tamanho.
Node *findPizza(Node *list_Pizza, char *flavor, char *size);
// Função auxiliar para calcular o total do pedido de uma pizza, ele recebe uma lista que adiciona todos os pedidos feitos.
float calOrdertotal(Node *pizzasOrded);
// Função auxiliar para salvar o pedido no arquivo pizzaria.txt.
void saveOrder(Order order, Node *pizzasOrded, float totalOrder);
// Função para remover o primeiro cliente de uma lista de pizzas já salvas em um arquivo.txt
void removeOrder();

#endif //PEDIDO