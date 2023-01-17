#pragma pack(1)

#include <stdio.h>
#include <stdlib.h>

#define EMPTY 0
#define FULL 10000

typedef char data;
typedef enum
{
    false,
    true
} boolean;

struct elem {
    data d;
    struct elem *next;
};

typedef struct elem elem;

struct stack {
    int cnt;
    elem *top;
};

typedef struct stack stack;

void initialize(stack *stk);