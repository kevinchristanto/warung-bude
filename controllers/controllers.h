#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utils.h"
#include "validations.h"

void mainMenu();
void welcome()
{
    system("cls || clear");
    printf("System : %s\n", detectOS());
    printf("%s", printCurrentTime());
    puts("1. Add Dish");
    puts("2. Remove Dish");
    puts("3. Add Customer");
    puts("4. Search Customer");
    puts("5. View Warteg");
    puts("6. Order");
    puts("7. Payment");
    puts("8. Exit");
}

NodeDish *addDish(Dish food)
{
    NodeDish *temp = (NodeDish *)malloc(sizeof(NodeDish));
    strcpy(temp->dish.name, food.name);
    temp->dish.price = food.price;
    temp->dish.qty = food.qty;
    temp->next = temp->prev = NULL;
    return temp;
}

void pushNodeDish(NodeDish *temp)
{

    if (!headDish)
    {
        headDish = tailDish = temp;
    }
    else
    {
        tailDish->next = temp;
        temp->prev = tailDish;
        tailDish = temp;
    }
}

NodeCustomer *addCust(Customer cust)
{
    NodeCustomer *temp = (NodeCustomer *)malloc(sizeof(NodeCustomer));
    strcpy(temp->customer.name, cust.name);
    temp->next = temp->prev = NULL;
    return temp;
}

void pushNodeCust(NodeCustomer *temp)
{
    if (!headCustomer[0])
    {
        headCustomer[0] = tailCustomer[0] = temp;
    }
    else
    {
        tailCustomer[0]->next = temp;
        temp->prev = tailCustomer[0];
        tailCustomer[0] = temp;
    }
}

void addDishMenu(NodeDish *c)
{
    Dish temp;
    do
    {
        printf("Insert the name of the dish [Lowercase letter]: ");
        scanf("%s", temp.name);
        getchar();
    } while (!isValidName(temp.name));

    do
    {
        printf("Insert the price of the dish [1000..50000]: ");
        scanf("%d", &temp.price);
        getchar();
    } while (!isValidPrice(temp.price));

    do
    {
        printf("Insert the quantity of the dish [1..999]: ");
        scanf("%d", &temp.qty);
        getchar();
    } while (!isValidQty(temp.qty));

    pushNodeDish(addDish(temp));
    sleep();
    puts("The dish has been added!");
    puts("Press enter to continue");
    getchar();
    mainMenu();
}

void printMenu(struct NodeDish *temp)
{
    puts("      Bude's Menu ");
    puts("");
    puts("================================================");
    int i = 1;
    printf("%-4s %-8s %-10s %-10s\n", "No.", "Name", "Quantity", "Price");
    if (headDish)
    {
        printf("| %d |", i);
        // center_print(temp->dish.name, 10);
        // center_print("RP", 10);
        // center_print((char *)temp->price, 10);
        puts("the dish has been added!");
        puts("Press enter to continue");
        getchar();
        mainMenu();
    }
    else
    {
        puts("There is no dish in the menu");
        puts("Press enter to continue");
        getchar();
        mainMenu();
    }
}

void removeDishMenu(NodeDish *temp)
{
    NodeDish *baseRoot = NULL;
    printMenu(baseRoot);
    char str[255];
    do
    {
        printf("Insert dish's name to be deleted: ");
        scanf("%s", str);
    } while (!isValidDish(temp, str));
}

void addCustomerMenu(NodeCustomer *c)
{
    Customer temp;
    char str[255];
    do
    {
        printf("Insert customer's name [Without space]: ");
        scanf("%s", str);
    } while (!isValidCust(str));
    pushNodeCust(addCust(temp));
    sleep();
    puts("Customer has been added!");
    getchar();
    mainMenu();
}

void mainMenu() //Prompt print main menu
{
    NodeDish *baseDish = NULL;
    NodeOrder *baseOrder = NULL;
    NodeCustomer *baseCustomer = NULL;
    welcome();
    int input;
    do
    {
        printf(">>");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            addDishMenu(baseDish);
            break;
        case 2:
            //removeDishMenu();
            break;
        case 3:
            addCustomerMenu(baseCustomer);
            break;
        case 4:
            //searchCustomerMenu();
            break;
        case 5:
            //viewWartegMenu();
            break;
        case 6:
            //orderManu();
            break;
        case 7:
            //paymentMenu();
            break;
        case 8:
            //exitMenu();
            break;
        }
    } while (!(input > 1 && input < 9));
}