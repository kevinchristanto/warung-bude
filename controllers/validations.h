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
        if (str[i] == ' ')
        {
            return false;
        }
    }
    return true;
}