#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
    int *data;
    int size;
    int top;
} Stack;

void createStack(Stack *stk, int size)
{
    stk->data = (int *)malloc(size * sizeof(int));
    stk->size = size;
    stk->top = -1;
}

void top(Stack *stk)
{
    if (stk->top < 0)
        printf("The stack is empty\n");
    else
        printf("top: %d\n", stk->data[stk->top]);
}

void push(Stack *stk, int x)
{
    stk->top++;
    stk->data[stk->top] = x;
}

int pop(Stack *stk)
{
    return stk->data[stk->top--];
}

void display(Stack *stk)
{
    printf("-- TOP --\n");

    int p = stk->top;
    while (p >= 0)
        printf("%d\n", stk->data[p--]);

    printf("-- BOTTOM --\n");
}

int main()
{
    Stack stk;
    createStack(&stk, 10);
    top(&stk);

    printf("----------\n");

    push(&stk, 1);
    top(&stk);

    printf("----------\n");

    printf("pop result : %d\n", pop(&stk));
    top(&stk);

    printf("----------\n");

    push(&stk, 1);
    push(&stk, 2);
    push(&stk, 3);
    push(&stk, 4);
    push(&stk, 5);
    display(&stk);
}