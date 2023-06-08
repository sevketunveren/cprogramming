#include <stack.h>

int main()
{
    stack *s;
    s = malloc(sizeof(stack));
    initialize(s);

    pop(s);
    boolean b = empty(s);
    push('A', s);
    b = empty(s);
    push('l', s);
    pop(s);
    pop(s);

    pop(s);
    return 0;
}