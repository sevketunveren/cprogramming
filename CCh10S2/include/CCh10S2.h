#pragma pack(1)
typedef char *DATA;
struct linked_list
{
    DATA d;
    struct linked_list *next;
};
typedef struct linked_list ELEMENT;
typedef ELEMENT *LINK;
void allocateELEMENT(LINK*);
void addElement(DATA, LINK);
unsigned int count(LINK);
LINK find(DATA d, LINK);
void concatenate(LINK, LINK);
void insertElement(LINK, LINK, LINK);
void delete(LINK*, LINK);
void clear(LINK);
void print(LINK);