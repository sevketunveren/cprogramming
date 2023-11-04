 #include <CCh10S2.h>
 #include <stdio.h>
 #include <stdlib.h>
 struct queue
 {
    LINK front;
    LINK rear;
 };
 typedef struct queue queue;
 void initialize(queue**);
 void enqueue(NODEPTR n, queue*);
 void dequeue(queue*);