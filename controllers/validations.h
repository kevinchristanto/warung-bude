#include "../models/models.h"
#include <string.h>
bool isValidName(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (!((str[i] >= 'a' && str[i] <= 'z') || str[i] == ' '))
        {
            return false;
        }
    }
    return true;
}

bool isValidPrice(int price)
{
    if (price < 1000 || price > 500000)
    {
        return false;
    }
    return true;
}

bool isValidQty(int qty)
{
    if (qty < 1 || qty > 999)
    {
        return false;
    }
    return true;
}

bool isValidDish(NodeDish *temp, char *str)
{
    currDish = headDish;
    if (currDish)
    {
        if (strcmp(temp->dish.name, str) != 0)
        {
            return false;
        }
        currDish = currDish->next;
    }
    return true;
}

bool isValidCust(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != ' ' && str[i] < 'a' || str[i] > 'z')
        {
            return false;
        }
    }
    return true;
}

bool isValidDeleteDish(char *name)
{
    if (strcmp(headDish->dish.name, name) == 0)
    {
        if (headDish && headDish == tailDish)
        {
            headDish = tailDish = NULL;
            free(headDish);
        }
        else
        {
            NodeDish *newHead = headDish->next;
            headDish->next = newHead->prev = NULL;
            free(headDish);
            headDish = newHead;
        }
        return true;
    }
    else if (strcmp(tailDish->dish.name, name) == 0)
    {
        if (headDish && headDish == tailDish)
        {
            headDish = tailDish = NULL;
            free(headDish);
        }
        else
        {
            NodeDish *newTail = tailDish->prev;
            tailDish->prev = newTail->next = NULL;
            free(tailDish);
            tailDish = newTail;
        }
        return true;
    }
    else
    {
        currDish = headDish;
        while (currDish)
        {
            if (strcmp(currDish->dish.name, name) == 0)
            {
                currDish->prev->next = currDish->next;
                currDish->next->prev = currDish->prev;
                currDish->prev = currDish->next = NULL;
                free(currDish);
                return true;
            }
            currDish = currDish->next;
        }
    }
    return false;
}

bool isPresent(char *name)
{
    for (int i = 0; i < 26; i++)
    {
        if (headCustomer[i])
        {
            currCustomer = headCustomer[i];
            while (currCustomer)
            {
                if (strcmp(currCustomer->customer.name, name) == 0)
                {
                    return true;
                }
                currCustomer = currCustomer->next;
            }
        }
    }
    return false;
}
