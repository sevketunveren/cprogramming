#pragma pack(1)
typedef int DATA;
struct node
{
    DATA value;
    struct node* left;
    struct node* right;
};
typedef struct node* NODE;
struct linked_list
{
    NODE n;
    struct linked_list *next;
};
typedef struct linked_list ELEMENT;
typedef ELEMENT *LINK;
void allocateELEMENT(LINK*);
LINK addElement(NODE, LINK);
unsigned int count(LINK);
LINK find(NODE d, LINK);
void concatenate(LINK, LINK);
void insertElement(LINK, LINK, LINK);
void delete(LINK*, LINK);
void clear(LINK);
void print(LINK);