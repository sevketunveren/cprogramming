#include <CCh10S5.h>

void main()
{
    queue q;
    initialize(&q);
    NODE n1, n2, n3, n4, n5;
    n1.value = "tuna";
    n2.value = "sevket";
    n3.value = "alp";
    n4.value = "isilay";
    n5.value = "kalben";
    enqueue(n1, &q);
    enqueue(n2, &q);
    enqueue(n3, &q);
    enqueue(n4, &q);
    enqueue(n5, &q);
    dequeue(&q);
}