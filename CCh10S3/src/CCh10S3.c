#include <stack.h>

int main()
{
    stack *s;
    s = malloc(sizeof(stack));
    initialize(s);
    push('A', s);
    push('l', s);
    pop(s);
    pop(s);
    pop(s);
    return 0;
}