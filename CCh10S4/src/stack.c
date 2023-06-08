#include <stack.h>

void initialize(stack *stk)
{
    stk->cnt = 0;
    stk->top = NULL;
}

void push(data d, stack *stk)
{
    elem *newElem;
    newElem = malloc(sizeof(elem));
    newElem->d = d;
    newElem->next = stk->top;
    stk->top = newElem;
    stk->cnt++;
}

void pop(stack *stk)
{
    if (stk->top != NULL)
    {
        elem *temp = (stk->top);
        stk->top = stk->top->next;
        stk->cnt--;
        free(temp);
    }
}

boolean empty(const stack *stk)
{
    return stk->top==NULL;
}