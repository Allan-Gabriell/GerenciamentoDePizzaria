enum size{
    P = 1, M, G, F
};

typedef enum size Size;

struct pizza{
    char flavor[50];
    char description[500];
    Size size;
    float price;
    int qtdInStock;
};

typedef struct pizza Pizza;
typedef struct node Node;

Node *addPizza(Node *list);
int listNull(Node *list);
void printList(Node *list);
Node *removePizza(Node *list);
void editPizza(Node *list);