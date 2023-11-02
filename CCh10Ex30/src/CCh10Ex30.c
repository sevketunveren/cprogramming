#include <CCh10Ex30.h>
void addNode(NODE* root, DATA nb)
{
    if(*root == NULL)
    {
        (*root) = malloc(sizeof(struct node));
        (*root)->value = nb;
        (*root)->left = NULL;
        (*root)->right = NULL;
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
            q->front->n->left->left = NULL;
            q->front->n->left->right = NULL;
            return;
        }
        else
            enqueue(q->front->n->left, q);
        if(q->front->n->right == NULL)
        {
            q->front->n->right = malloc(sizeof(struct node));
            q->front->n->right->value = nb;
            q->front->n->right->left = NULL;
            q->front->n->right->right = NULL;
            return;
        }
        else
            enqueue(q->front->n->right, q);
        dequeue(q);
    }
    free(q);
}

void addNodeCmp(NODE* root, DATA nb)
{
    if(*root == NULL)
    {
        (*root) = malloc(sizeof(struct node));
        (*root)->value = nb;
        (*root)->left = NULL;
        (*root)->right = NULL;
        return;
    }
    else if((*root)->value <= nb)
    {
        addNodeCmp(&((*root)->right), nb);
    }
    else
    {
        addNodeCmp(&((*root)->left), nb);
    }
}

void printBinaryTree(NODE root)
{
    if(root == NULL)
        return;
    else
    {
        printf("%d\t", root->value);
        printBinaryTree(root->left);
        printBinaryTree(root->right);
    }
}
