
typedef struct order Order;
typedef struct orderpizza OrderPizza;

OrderPizza* create_order(void);
void new_pizzaorder (OrderPizza *queue);
int empty_pizzaorder (OrderPizza *queue);
void print_pizzaorder (OrderPizza *queue);