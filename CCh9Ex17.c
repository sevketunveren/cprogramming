#include "CCh9Ex17.h"
void main() {
    food foods[] = {{"Lentil", 100.17, SOUP, 2.45},
                    {"Tomato Soup", 125.12, SOUP, 3.15},
                    {"Chestnut Bisque Soup", 250, SOUP, 6.30 },
                    {"Bread Soup", 400, SOUP, 2.15},
                    {"Carrot Soup", 113.40, SOUP, 2.95},
                    {"Tarhana Soup", 275, SOUP, 4.05},
                    {"Lettuce Soup", 90.35, SOUP, 2.50},
                    {"Fish Soup", 310.80, SOUP, 4.40},
                    {"Banana", 125.16, FRUIT, 0.25},
                    {"Melon", 140, FRUIT, 0.60},
                    {"Orange", 50, FRUIT, 0.15},
                    {"Mandarin", 55, FRUIT, 0.25},
                    {"Strawberry", 90, FRUIT, 0.40},
                    {"Apricot", 140, FRUIT, 0.75},
                    {"Peach", 120, FRUIT, 0.60},
                    {"Kiwi", 50, FRUIT, 0.90},
                    {"Pear", 70, FRUIT, 0.10},
                    {"Apple", 40, FRUIT, 0.05},
                    {"Margaritha Pizza", 250, MAIN, 6.25},
                    {"Meat Pizza", 370, MAIN, 8.10},
                    {"Neapolitan Pizza", 275, MAIN, 7.00},
                    {"Ribeye Steak", 325, MAIN, 10.10},
                    {"Tenderloin Steak", 310, MAIN, 9.45},
                    {"T-Bone Steak", 290, MAIN, 9.50},
                    {"Sirloin Steak", 310, MAIN, 8.75},
                    {"Tomahawk Steak", 325, MAIN, 11.25},
                    {"Chicken Steak", 290, MAIN, 8.10},
                    {"Chicken Wings", 310, MAIN, 8.45},
                    {"Sweet and Sour Chicken", 290, MAIN, 8.90},
                    {"Roast Chicken", 345, MAIN, 9.25},
                    {"Fettuccine Pasta", 500, MAIN, 4.90},
                    {"Fusilli Pasta", 540, MAIN, 5.05},
                    {"Lasagna", 600, MAIN, 6.00},
                    {"Macaroni", 515, MAIN, 4.90},
                    {"Penne Pasta", 525, MAIN, 5.10},
                    {"Ravioli", 570, MAIN, 6.10},
                    {"Spaghetti Pasta", 530, MAIN, 5.75},
                    {"Tagliatelle Pasta", 475, MAIN, 4.90},
                    {"Tortellini", 450, MAIN, 5.35},
                    {"Sea Bream", 325, MAIN, 9.90},
                    {"Tuna Fish", 345, MAIN, 7.90}, 
                    {"Salmon Fish", 490, MAIN, 7.75}, 
                    {"Spinach", 75, VEGETABLE, 1.15}, 
                    {"Carrots", 50, VEGETABLE, 0.90}, 
                    {"Potato", 150, VEGETABLE, 1.45}, 
                    {"Mushrooms", 90, VEGETABLE, 1.30}, 
                    {"Broccoli", 75, VEGETABLE, 1.00}, 
                    {"Garlic", 95, VEGETABLE, 0.95}, 
                    {"Green Peas", 100, VEGETABLE, 1.60}, 
                    {"Onions", 65, VEGETABLE, 0.10}};
    menu myMenu;
    bool menuCreated = FALSE;
    unsigned short attempt = 0;
    srand(time(NULL));
    shuffle(foods);
    menuCreated=createMenu(foods, 750, 12.50, &myMenu);
    while(menuCreated==FALSE && attempt <= 10)
    {
        menuCreated=createMenu(foods, 750, 12.50, &myMenu);
        shuffle(foods);
        attempt++;
    }
    if(!menuCreated)
    {
        printf("Unable to create menu that meets cost and calories.\n");
    }
    else
    {
        for(int i = 0; i<4 && menuCreated==TRUE; ++i)
        {
            printf("%s\t\t\t%lf\t%lf\t%d\n", myMenu.foods[i].name, myMenu.foods[i].calories, myMenu.foods[i].cost, myMenu.foods[i].type);
        }
    }
}