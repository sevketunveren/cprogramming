#include <CCh10S6.h>
void addNode(NODE* root, DATA nb)
{
    if(*root == NULL)
    {
        (*root) = malloc(sizeof(struct node));
        (*root)->value = nb;
        return;
    }
    queue *q;
    initialize(&q);
    enqueue((*root), q);
    while(1)
    {
        if(q->front->n->left == NULL)
        {
            q->front->n->left = malloc(sizeof(struct node));
            q->front->n->left->value = nb;
            return;
        }
        else
            enqueue(q->front->n->left, q);
        if(q->front->n->right == NULL)
        {
            q->front->n->right = malloc(sizeof(struct node));
            q->front->n->right->value = nb;
            return;
        }
        else
            enqueue(q->front->n->right, q);
        dequeue(q);
    }
    free(q);
}


void printBinaryTree(NODE root)
{
    if(root == NULL)
        return;
    else
    {
        printf("%s\t", root->value);
        printBinaryTree(root->left);
        printBinaryTree(root->right);
    }
}
