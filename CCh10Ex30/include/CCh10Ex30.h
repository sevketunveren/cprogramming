#pragma pack(1)
#include <CCh10S5.h>
#include <time.h>
#include <stdlib.h>
#define SIZE 1000
#define MAX 100
void addNode(NODEPTR*, DATA);
void printBinaryTree(NODEPTR);
void addNodeCmp(NODEPTR*, DATA);
NODEPTR rigthMost(NODEPTR, NODEPTR*);