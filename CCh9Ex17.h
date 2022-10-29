/*Write a program that is able to produce a balanced meal. Start by defining a structure that contains the name of a food, its calories per serving, its food type such as meat or fruit, and its costs. The foods should be stored as an array of structures. The program should construct a meal that comes from four different food types and that meets calorie and cost constraints. The program should be capable of producing a large number of different menus*/
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#define SIZE 50
#define LENGTH 25
#define TRUE 1
#define FALSE 0
typedef unsigned short bool;
typedef enum type
{
    FRUIT,
    MAIN,
    SOUP,
    VEGETABLE
} type;

typedef struct food
{
    char name[LENGTH];
    double calories;
    type type;
    float cost;
} food;

typedef struct menu
{
    food foods[4];
    double totalCost;
    double totalCalories;
} menu;

void swap(food *f1, food *f2)
{
    food temp;
    temp = *f1;
    *f1 = *f2;
    *f2 = temp;
}

void shuffle(food *foods)
{
    int random;
    for (int i = 0; i < SIZE - 1; ++i)
    {
        random = rand() % SIZE;
        swap(foods + i, foods + random);
    }
}

void addFoodToMenu(food f, menu *m, unsigned short* count)
{
    m->totalCalories += f.calories;
    m->totalCost += f.cost;
    m->foods[f.type] = f;
    (*count)++;
}

bool createMenu(food *foods, double maxCalories, double maxCost, menu *menu)
{
    bool isSoupSelected = 0, isFruitSelected = 0, isMainSelected = 0, isVegetableSelected = 0;
    unsigned short count = 0;
    menu->totalCalories = menu->totalCost = 0;
    for (int i = 0; i < SIZE; ++i)
    {
        if (menu->totalCalories + foods[i].calories <= maxCalories &&
            menu->totalCost + foods[i].cost <= maxCost)
        {
            if (foods[i].type == SOUP &&
                isSoupSelected == FALSE)
            {
                isSoupSelected = TRUE;
                addFoodToMenu(foods[i], menu, &count);
            }
            else if (foods[i].type == FRUIT &&
                isFruitSelected == FALSE)
            {
                isFruitSelected = TRUE;
                addFoodToMenu(foods[i], menu, &count);
            }
            else if (foods[i].type == MAIN &&
                isMainSelected == FALSE)
            {
                isMainSelected = TRUE;
                addFoodToMenu(foods[i], menu, &count);
            }
            else if (foods[i].type == VEGETABLE &&
                isVegetableSelected == FALSE)
            {
                isVegetableSelected = TRUE;
                addFoodToMenu(foods[i], menu, &count);
            }
            if (count == 4)
                return TRUE;
        }
    }
    return FALSE;
}