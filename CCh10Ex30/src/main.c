#include <CCh10Ex30.h>
void main()
{
    NODE root = NULL;
    int r;
    int k;
    srand(time(NULL));   // Initialization, should only be called once.
    r = rand()%50;
    for(int i =0; i<r;++i)
    {
        k = rand()%100;
        if(rand()%2==1)
        {
            k=-k;
        }
        printf("New Element: %d\t", k);
        addNodeCmp(&root,k);
    }
    printf("\n");
    printf("\n");
    printBinaryTree(root);
}