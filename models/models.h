#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Dish
{
    char name[255];
    int price, qty;
};

struct NodeDish
{
    struct Dish dish;
    NodeDish *prev, *next;
} * headDish, *tailDish, *currDish, *newDish, *delDish;

struct Order
{
    char name[255];
    int quantity, price;
};

struct NodeOrder
{
    struct Order order;
    NodeOrder *prev, *next;
} * newOrder, *currOrder, *delOrder;
struct Customer
{
    char name[255];
};

struct NodeCustomer
{
    struct Customer customer;
    NodeOrder *headOrder, *tailOrder;
    NodeCustomer *prev, *next;
} * headCustomer[26], *tailCustomer[26], *currCustomer, *newCustomer, *delCustomer;

NodeDish *addDish(Dish food);      // create dish
void pushNodeDish(NodeDish *temp); //push node dish
void addDishMenu(NodeDish *c);     // add dish menu
