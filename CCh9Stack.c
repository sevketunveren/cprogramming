#include "CCh9Stack.h"
#include <stdio.h>
void reset(stack *stk) {
    stk->top = EMPTY;
}

void push(char c, stack *stk){
    stk->top++;
    stk->s[stk->top] = c;
}

char pop(stack *stk) {
    return stk->s[stk->top--];
}

char top(const stack *stk) {
    return stk->s[stk->top];
}

boolean empty(const stack *stk) {
    return (boolean)(stk->top == EMPTY);
}

boolean full(const stack *stk) {
        return (boolean)(stk->top == FULL);
}

int main(void) {
    char str[] = "My name is Alp!";
    int i;
    stack s;
    reset(&s);
    printf("In the string: %s\n", str);
    for(i = 0; str[i] != '\0'; ++i)
        if(!full(&s))
            push(str[i], &s);
    while(!empty(&s))
        putchar(pop(&s));
    return 0;
}