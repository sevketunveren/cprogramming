#include <CCh10S5.h>

void initialize(queue** q)
{
    (*q) = malloc(sizeof(queue));
    allocateELEMENT(&((*q)->front));
    allocateELEMENT(&((*q)->rear));
}

void enqueue(NODEPTR d, queue* q)
{
    if(q->front->n == NULL)
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