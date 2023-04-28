#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    Node *next;
} Node;

void createList(Node **head, int *arr, int size, bool isLoop)
{
    *head = (Node *)malloc(sizeof(Node));
    Node *last = *head;
    last->data = arr[0];
    last->next = NULL;

    Node *temp = *head;

    for (int i = 1; i < size; i++)
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = arr[i];
        newNode->next = NULL;

        last->next = newNode;
        last = newNode;
    }

    // make it loop
    if (isLoop)
        last->next = temp;
}

void display(Node *p)
{
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void checkLoop(Node *head)
{
    Node *p;
    Node *q;

    do
    {
        p = p->next;
        q = q->next;
        q = q ? q->next : q;
    } while (p && q && p != q);

    if (p == q)
        printf("it is loop");
    else
        printf("it is not loop");
}

int main()
{
    Node *head;
    int arr[5] = {1, 2, 3, 4, 5};
    // createList(&head, arr, 5, true);
    createList(&head, arr, 5, false);

    checkLoop(head);
    // display(head);

    return 0;
}