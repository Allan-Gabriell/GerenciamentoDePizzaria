#include "pedido.c"

void menu()
{
    Node *head = NULL;
    char option[10];
    int num;
    char decision[3];

    Queue *orderPizza = createQueue();

    do
    {
        printf("===== Bem vindo ao nosso sistema de pizzaria =====\n");
        printf("Por favor informe um número de acordo com a opção!\n");
        printf("      1. Adicionar pizza\n");
        printf("      2. Remover pizza\n");
        printf("      3. Adicionar pedido\n");
        printf("      4. Remover pedido\n");
        printf("      5. Editar informações de pizza\n");
        printf("      6. Buscar pizza por sabor\n");
        printf("      7. Listar pizzas e quantidades disponíveis\n");
        printf("      8. Sair do sistema\n");
        printf("==================================================\n");
        scanf("%s", option);

        int isNumber = 1;
        for (int i = 0; i < strlen(option); i++)
        {
            if (!isdigit(option[i]))
            {
                isNumber = 0;
                break;
            }
        }

        if (isNumber)
        {
            num = atoi(option);
            switch (num)
            {
            case 1:
                printf("Deseja adicionar uma nova pizza? (s/n) \n");
                scanf(" %[^\n]", decision);
                if (strcmp(decision, "s") == 0 || strcmp(decision, "S") == 0 || strcmp(decision, "sim") == 0 || strcmp(decision, "Sim") == 0 || strcmp(decision, "SIM") == 0)
                {
                    head = addPizza();
                }
                else
                {
                    menu(head);
                }
                break;
            case 2:
                printf("Deseja remover uma pizza? (s/n) \n");
                scanf(" %[^\n]", decision);
                if (strcmp(decision, "s") == 0 || strcmp(decision, "S") == 0 || strcmp(decision, "sim") == 0 || strcmp(decision, "Sim") == 0 || strcmp(decision, "SIM") == 0)
                {
                    head = removePizza();
                }
                else
                {
                    menu(head);
                }
                break;
            case 3:
                printf("Deseja adicionar um novo pedido? (s/n) \n");
                scanf(" %[^\n]", decision);
                if (strcmp(decision, "s") == 0 || strcmp(decision, "S") == 0 || strcmp(decision, "sim") == 0 || strcmp(decision, "Sim") == 0 || strcmp(decision, "SIM") == 0)
                {
                    enqueue(orderPizza);
                }
                else
                {
                    menu(head);
                }
                break;
            case 4:
                printf("Deseja remover um pedido? (s/n) \n");
                scanf(" %[^\n]", decision);
                if (strcmp(decision, "s") == 0 || strcmp(decision, "S") == 0 || strcmp(decision, "sim") == 0 || strcmp(decision, "Sim") == 0 || strcmp(decision, "SIM") == 0)
                {
                    // dequeueorder(orderPizza);
                }
                else
                {
                    menu(head);
                }
                break;
            case 5:
                printf("Deseja editar uma pizza? (s/n) \n");
                scanf(" %[^\n]", decision);
                if (strcmp(decision, "s") == 0 || strcmp(decision, "S") == 0 || strcmp(decision, "sim") == 0 || strcmp(decision, "Sim") == 0 || strcmp(decision, "SIM") == 0)
                {
                    editPizza();
                }
                else
                {
                    menu(head);
                }
                break;
            case 6:
                printf("Deseja buscar pizza por sabor? (s/n) \n");
                scanf(" %[^\n]", decision);
                if (strcmp(decision, "s") == 0 || strcmp(decision, "S") == 0 || strcmp(decision, "sim") == 0 || strcmp(decision, "Sim") == 0 || strcmp(decision, "SIM") == 0)
                {
                    searchPizzaByName();
                    printList(head);
                }
                else
                {
                    menu(head);
                }
                break;
            case 7:
                printf("Deseja ver pizzas e quantidade em estoque? (s/n) \n");
                scanf(" %[^\n]", decision);
                if (strcmp(decision, "s") == 0 || strcmp(decision, "S") == 0 || strcmp(decision, "sim") == 0 || strcmp(decision, "Sim") == 0 || strcmp(decision, "SIM") == 0)
                {
                    printListPizzas();
                }
                else
                {
                    menu(head);
                }
                break;
            case 8:
                break;
            default:
                printf("A opção informada é inválida. Por favor tente novamente!\n");
            }
        }
        else
        {
            printf("A opção informada é inválida. Por favor tente novamente!\n");
        }

    } while (num != 8);
}

int main(void)
{

    menu();

    return 0;
}