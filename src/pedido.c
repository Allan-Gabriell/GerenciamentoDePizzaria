#include "include/pedido.h"
#include "include/pizzas.h"
#include <stdio.h>
#include <stdlib.h>

struct order{
    int pizzaId;
    Pizza *orderPizza;
    int qntOrder;
};
