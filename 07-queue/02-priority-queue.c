#include <stdio.h>
#include <stdlib.h>

typedef struct PriorQueue
{
    int *data1;
    int front1;
    int rear1;

    int *data2;
    int front2;
    int rear2;

    int size;
} PriorQueue;

void init(PriorQueue *q, int size)
{
    q->front1 = q->front2 = q->rear1 = q->rear2 = -1;
    q->data1 = (int *)malloc(sizeof(int) * size);
    q->data2 = (int *)malloc(sizeof(int) * size);
    q->size = size;
}

void push(PriorQueue *q, int x, int priority)
{
    if (priority == 1)
    {
        if (q->rear1 == q->size - 1)
            printf("queue with priority 1 is full\n");
        else
            q->data1[++q->rear1] = x;
    }

    if (priority == 2)
    {
        if (q->rear2 == q->size - 1)
            printf("queue with priority 2 is full\n");
        else
            q->data2[++q->rear2] = x;
    }
}

int pop(PriorQueue *q)
{
    if (q->rear1 > q->front1)
    {
        return q->data1[++q->front1];
    }
    else if (q->rear2 > q->front2)
        return q->data2[++q->front2];
    else
    {
        printf("The queue is empty\n");
        return -1;
    }
}

int main()
{
    PriorQueue *q = (PriorQueue *)malloc(sizeof(PriorQueue));
    init(q, 3);
    push(q, 2, 1);
    push(q, 1, 2);
    push(q, 4, 1);
    push(q, 3, 2);
    push(q, 6, 1);
    push(q, 5, 2);
    push(q, 8, 1);
    push(q, 7, 2);

    printf("pop: %d\n", pop(q));
    printf("pop: %d\n", pop(q));
    printf("pop: %d\n", pop(q));
    printf("pop: %d\n", pop(q));
    printf("pop: %d\n", pop(q));
    printf("pop: %d\n", pop(q));
    printf("pop: %d\n", pop(q));

    return 0;
}