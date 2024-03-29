enum size{
    P = 1, M, G, F
};

typedef enum size Size;

struct pizza{
    char flavor[50];
    Size size;
    float price;
    int qtdInStock;
};

typedef struct pizza Pizza;
typedef struct node Node;

Node *addPizza(Node *list);