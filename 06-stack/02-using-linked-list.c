#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    Node *next;
} Node;

typedef struct Stack
{
    Node *top;
} Stack;

void push(Stack *stk, int x)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = stk->top;
    stk->top = newNode;
}

int pop(Stack *stk)
{
    if (stk->top)
    {
        int res = stk->top->data;
        Node *temp = stk->top;
        stk->top = stk->top->next;
        free(temp);
        printf("pop result: %d\n", res);
        return res;
    }
    else
    {
        printf("stack is empty\n");
        return -1;
    }
}

void top(Stack *stk)
{
    if (stk->top)
    {
        int res = stk->top->data;
        printf("top: %d\n", res);
    }
    else
    {
        printf("stack is empty\n");
    }
}

void display(Stack *stk)
{
    printf("-- TOP --\n");

    Node *p = stk->top;

    while (p)
    {
        printf("%d\n", p->data);
        p = p->next;
    }

    printf("-- BOTTOM --\n");
}

int main()
{
    Stack stk;
    stk.top = NULL;

    top(&stk);

    printf("----------\n");

    push(&stk, 1);
    top(&stk);

    printf("----------\n");

    pop(&stk);
    top(&stk);

    printf("----------\n");

    push(&stk, 1);
    push(&stk, 2);
    push(&stk, 3);
    push(&stk, 4);
    push(&stk, 5);
    display(&stk);
}