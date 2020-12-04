#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utils.h"
#include "validations.h"

void mainMenu();
void welcome()
{
    clear_screen();
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

void addDishMenu()
{
    clear_screen();
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

void printMenu()
{
    clear_screen();
    currDish = headDish;
    puts("Bude's Menu ");
    puts("================================================");
    int i = 1;
    printf("%-4s %-8s %-10s %-10s\n", "No.", "Name", "Quantity", "Price");
    while (currDish)
    {
        printf(" %d.  %-10s %03d  Rp%-12d\n", i, currDish->dish.name, currDish->dish.qty, currDish->dish.price);
        currDish = currDish->next;
        i++;
    }
}

void removeDishMenu()
{
    clear_screen();
    char name[255];
    if (!headDish)
    {
        puts("There is no dish in the menu");
        puts("Press enter to continue");
        getchar();
        getchar();
        mainMenu();
    }
    else
    {
        printMenu();
        do
        {
            printf("Insert dish's name to be deleted: ");
            scanf("%s", name);
        } while (!isValidDeleteDish(name));
        puts("The dish has been deleted");
        puts("Press enter to continue");
        getchar();
        getchar();
        mainMenu();
    }
}

NodeCustomer *addCustomer(char *name)
{
    NodeCustomer *temp = (NodeCustomer *)malloc(sizeof(NodeCustomer));
    strcpy(temp->customer.name, name);
    temp->next = temp->prev = NULL;
    return temp;
}

void insertCustomer(struct NodeCustomer *temp, int hash)
{
    if (headCustomer[hash])
    {
        tailCustomer[hash]->next = temp;
        tailCustomer[hash] = temp;
    }
    else
    {
        headCustomer[hash] = tailCustomer[hash] = temp;
    }
}

void addCustomerMenu()
{
    clear_screen();
    char name[255];
    do
    {
        printf("Insert customer's name [Without space]: ");
        getchar();
        scanf("%[^\n]", name);
    } while (!isValidCust(name));
    int hash = DJB2(name);
    insertCustomer(addCustomer(name), hash);
    sleep();
    puts("Customer has been added!");
    puts("Press enter to continue");
    getchar();
    getchar();
    mainMenu();
}

void searchCustomerMenu()
{
    clear_screen();
    char name[255];
    printf("Insert the customer's name to be searched: ");
    scanf("%s", name);
}

void exitMenu()
{
    puts("Please expand your terminal to full screen");
    puts("Press enter to continue");
    FILE *fp = fopen("/Users/kevinchristanto/Desktop/warung-bude/views/splash-screen.txt", "r");
    char str[10000];
    while (!feof(fp))
    {
        fscanf(fp, "%[^\n]%*c", str);
        printf("%s\n", str);
    }
    fclose(fp);
    getchar();
    getchar();
}

void mainMenu() //Prompt print main menu
{
    welcome();
    int input;
    do
    {
        printf(">> ");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            addDishMenu();
            break;
        case 2:
            removeDishMenu();
            break;
        case 3:
            addCustomerMenu();
            break;
        case 4:
            searchCustomerMenu();
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
            exitMenu();
            break;
        }
    } while (!(input > 1 && input < 9));
}