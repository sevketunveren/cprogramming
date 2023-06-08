#include <stack.h>
#include <string.h>
int main()
{
    stack *ps, *es;
    data d1, d2, d3;
    double f1, f2, f3;
    char *result;
    ps = malloc(sizeof(stack));
    es = malloc(sizeof(stack));
    initialize(ps);
    initialize(es);
    push("+", ps);
    push("*", ps);
    push("3.5", ps);
    push("2.441", ps);
    push("-", ps);
    push("4.45", ps);
    push("13.88145", ps);
    while (ps->cnt > 0)
    {
        d1 = ps->top->d;
        pop(ps);
        if (d1 == "*" || d1 == "+" || d1 == "-")
        {
            d3 = es->top->d;
            pop(es);
            d2 = es->top->d;
            pop(es);
            f2 = strtod(d2, NULL);
            f3 = strtod(d3, NULL);
            if (d1 == "*")
                f1 = f2 * f3;
            else if (d1 == "+")
                f1 = f2 + f3;
            else if (d1 == "-")
                f1 = f2 - f3;
            result = malloc(sizeof(char) * 100);
            sprintf(result, "%f", f1);
            push(result, es);
        }
        else
            push(d1, es);
    }
    printf("result:\t%s\n", es->top->d);
    return 0;
}