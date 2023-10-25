#pragma pack(1)
typedef const char* DATA;
struct node
{
    DATA d;
    struct node *right;
    struct node *left;
};
typedef struct node node;

node* createNode(DATA);
node* findLastNode(node*);
void addNode(DATA, node*);
