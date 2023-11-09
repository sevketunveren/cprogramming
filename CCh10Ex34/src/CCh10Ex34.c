#include <CCh10Ex34.h>
void addNode(NODEPTR *root, DATA nb)
{
    if (*root == NULL)
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
    while (1)
    {
        if (q->front->n->left == NULL)
        {
            q->front->n->left = malloc(sizeof(struct node));
            q->front->n->left->value = nb;
            q->front->n->left->left = NULL;
            q->front->n->left->right = NULL;
            return;
        }
        else
            enqueue(q->front->n->left, q);
        if (q->front->n->right == NULL)
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

void addNodeCmp(NODEPTR *root, DATA nb)
{
    if (*root == NULL)
    {
        (*root) = malloc(sizeof(struct node));
        (*root)->value = nb;
        (*root)->left = NULL;
        (*root)->right = NULL;
        return;
    }
    else if ((*root)->value <= nb)
    {
        addNodeCmp(&((*root)->right), nb);
    }
    else
    {
        addNodeCmp(&((*root)->left), nb);
    }
}

void printBinaryTree(NODEPTR root)
{
    if (root == NULL)
        return;
    else
    {
        printf("%d\t", root->value);
        printBinaryTree(root->left);
        printBinaryTree(root->right);
    }
}

NODEPTR rigthMost(NODEPTR root, NODEPTR *parent)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (root->right != NULL)
    {
        *parent = root;
        rigthMost(root->right, parent);
    }
    else if (root->left != NULL)
    {
        *parent = root;
        rigthMost(root->left, parent);
    }
    else
    {
        return root;
    }
}

void printTree(NODEPTR root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d\n", root->value);
    queue *q;
    initialize(&q);
    enqueue(root, q);
    while (q->front !=NULL)
    {
        if (q->front->n->left != NULL)
        {
            printf("%d\n", q->front->n->left->value);
            enqueue(q->front->n->left, q);
        }
        if (q->front->n->right != NULL)
        {
            printf("%d\n", q->front->n->right->value);
            enqueue(q->front->n->right, q);
        }
        dequeue(q);
    }
}