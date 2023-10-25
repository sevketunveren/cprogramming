#include <CCh10S5.h>

void initialize(queue* q)
{
    allocateELEMENT(&(q->front));
    allocateELEMENT(&(q->rear));
}

void enqueue(NODE d, queue* q)
{
    if(q->front->n.value == NULL)
    {
        q->front->n = d;
        q->rear = q->front;
    }
    else
    q->rear = addElement(d, q->front);
}

void dequeue(queue* q)
{
    delete(&(q->front), q->front);
}