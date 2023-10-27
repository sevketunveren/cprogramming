#include <CCh10S6.h>
void main()
{
    /*queue q;
    initialize(&q);
    NODE n1, n2, n3, n4, n5;
    n1 = malloc(sizeof(struct node));
    n2 = malloc(sizeof(struct node));
    n3 = malloc(sizeof(struct node));
    n4 = malloc(sizeof(struct node));
    n5 = malloc(sizeof(struct node));
    n1->value = "tuna";
    n2->value = "sevket";
    n3->value = "alp";
    n4->value = "isilay";
    n5->value = "kalben";
    enqueue(n1, &q);
    enqueue(n2, &q);
    enqueue(n3, &q);
    enqueue(n4, &q);
    enqueue(n5, &q);
    dequeue(&q);
    print(q.front);*/
    NODE root = NULL;
    addNode(&root,"root");
    addNode(&root,"LEVEL1-L");
    addNode(&root,"LEVEL1-R");
    addNode(&root,"LEVEL2-LL");
    addNode(&root,"LEVEL2-LR");
    addNode(&root,"LEVEL2-RL");
    addNode(&root,"LEVEL2-RR");
    addNode(&root,"LEVEL3-LLL");
    addNode(&root,"LEVEL3-LLR");
    addNode(&root,"LEVEL3-LRL");
    addNode(&root,"LEVEL3-LRR");
    addNode(&root,"LEVEL3-RLL");
    addNode(&root,"LEVEL3-RLR");
    addNode(&root,"LEVEL3-RRL");
    addNode(&root,"LEVEL3-RRR");
    printBinaryTree(root);
}