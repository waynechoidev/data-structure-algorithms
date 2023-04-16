#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    Node *next;
} Node;

void createList(Node **head, int *arr, int size)
{
    Node *last;
    *head = (Node *)malloc(sizeof(Node));
    last = *head;
    last->data = arr[0];
    last->next = NULL;

    for (int i = 1; i < size; i++)
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = arr[i];
        newNode->next = NULL;
        last->next = newNode;
        last = newNode;
    }
}

void display(Node *p)
{
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

Node *search(Node *p, int x)
{
    while (p)
    {
        if (p->data == x)
            return p;
        p = p->next;
    }
    return NULL;
}

int main()
{
    Node *head;
    int arr[5] = {10, 5, 2, 4, 19};
    createList(&head, arr, 5);
    // display(head);
    Node *result = search(head, 19);
    // Node *result = search(head, 20);
    if (result)
        printf("%d\n", result->data);
    else
        printf("cannot find\n");
    return 0;
}