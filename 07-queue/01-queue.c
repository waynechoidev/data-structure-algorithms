#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
    int *data;
    int front;
    int rear;
    int size;
} Queue;

void init(Queue *queue, int size)
{
    queue->size = size;
    queue->data = (int *)malloc(sizeof(int) * size);
    queue->front = queue->rear = -1;
}

int isEmpty(Queue *queue)
{
    return queue->front == queue->rear;
}

int isFull(Queue *queue)
{
    return queue->rear == queue->size - 1;
}

void push(Queue *queue, int x)
{
    if (isFull(queue))
        printf("The queue is full\n");
    else
        queue->data[++queue->rear] = x;
}

int pop(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("The queue is empty\n");
        return -1;
    }
    else
        return queue->data[++queue->front];
}

int main()
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    init(queue, 5);
    push(queue, 2);
    push(queue, 4);
    push(queue, 6);
    push(queue, 8);
    push(queue, 10);
    push(queue, 12); // full

    printf("pop: %d\n", pop(queue));
    printf("pop: %d\n", pop(queue));
    printf("pop: %d\n", pop(queue));
    printf("pop: %d\n", pop(queue));
    printf("pop: %d\n", pop(queue));
    printf("pop: %d\n", pop(queue)); // empty

    return 0;
}