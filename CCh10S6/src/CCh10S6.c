#include <CCh10S6.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int mains()
{
    node *nRoot;
    char input[20];
    nRoot = NULL;
    nRoot = createNode("Root");
    addNode("SubRight1", nRoot);
    addNode("SubLeft1", nRoot);
    return 0;
}

node *createNode(DATA name)
{
    node *newBie = malloc(sizeof(node));
    newBie->d = name;
    newBie->right = NULL;
    newBie->left = NULL;
    return newBie;
}

node* findLastNode(node* tree)
{
    if(tree == NULL)
        return tree;
    findLastNode(tree->right);
    findLastNode(tree->left);
}

void addNode(DATA name, node* tree)
{
    node* found = findLastNode(tree);
    found = createNode(name);
}