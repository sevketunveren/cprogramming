#include <CCh10Ex34.h>
void main()
{
    NODEPTR root = NULL;
    NODEPTR parent;
    NODEPTR rm;
    addNodeCmp(&root, 65);
    addNodeCmp(&root, 56);
    addNodeCmp(&root, 67);
    addNodeCmp(&root, 48);
    addNodeCmp(&root, 59);
    addNodeCmp(&root, 66);
    printBinaryTree(root);
    rm=rigthMost(root, &parent);
    rm->left = root->left;
    rm->right = root->right;
    root = rm;
    parent->left = NULL;
    rm = NULL;
    parent = NULL;
    free(parent);
    free(rm);
    printf("\n");
    printBinaryTree(root);
    printf("\n");
    printf("\n");
    printTree(root);
}