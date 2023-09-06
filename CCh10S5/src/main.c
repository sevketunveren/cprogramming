#include <CCh10S5.h>

void main()
{
    queue q;
    initialize(&q);
    enqueue("tuna", &q);
    enqueue("sevket", &q);
    enqueue("alp", &q);
    enqueue("isilay", &q);
    enqueue("kalben", &q);
    dequeue(&q);
}