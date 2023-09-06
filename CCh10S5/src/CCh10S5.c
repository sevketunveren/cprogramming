#include <CCh10S5.h>

void initialize(queue* q)
{
    allocateELEMENT(&(q->front));
    allocateELEMENT(&(q->rear));
}

void enqueue(DATA d, queue* q)
{
    if(q->front->d == NULL)
    {
        q->front->d = d;
        q->rear = q->front;
    }
    else
    q->rear = addElement(d, q->front);
}

void dequeue(queue* q)
{
    delete(&(q->front), q->front);
}