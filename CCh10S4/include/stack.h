#pragma pack(1)

#include <stdio.h>
#include <stdlib.h>

typedef char* data;

typedef enum
{
    false,
    true
} boolean;

struct elem
{
    data d;
    struct elem *next;
};

typedef struct elem elem;

struct stack
{
    int cnt;
    elem *top;
};

typedef struct stack stack;

void initialize(stack *stk);
void push(data d, stack *stk);
void pop(stack *stk);
boolean empty(const stack *stk);