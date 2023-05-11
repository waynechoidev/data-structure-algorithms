#include <stdio.h>
#include <stdlib.h>

typedef struct Dequeue
{
    int *data;
    int front;
    int rear;
    int size;
} Dequeue;

void init(Dequeue *q, int size)
{
    q->data = (int *)malloc(sizeof(int) * size);
    q->size = size;
    q->front = q->rear = size / 2;
}

void pushFront(Dequeue *q, int x)
{
    if (q->front == -1)
        printf("dequeue is overflow");
    else
        q->data[--q->front] = x;
}

int popFront(Dequeue *q)
{
    return q->data[q->front++];
}

void pushBack(Dequeue *q, int x)
{
    if (q->rear == q->size - 1)
        printf("dequeue is overflow");
    else
        q->data[++q->rear] = x;
}

int popBack(Dequeue *q)
{
    return q->data[--q->rear];
}

int main()
{
    Dequeue *q = (Dequeue *)malloc(sizeof(Dequeue));
    init(q, 100);

    pushFront(q, 10);
    pushFront(q, 20);
    printf("%d\n", popBack(q));

    pushBack(q, 100);
    printf("%d\n", popFront(q));

    return 0;
}