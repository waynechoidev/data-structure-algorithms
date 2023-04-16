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
    (*head)->data = arr[0];
    (*head)->next = NULL;
    last = *head;

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
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

void displayR(Node *p)
{
    if (p)
    {
        printf("%d ", p->data);
        displayR(p->next);
    }
}

int main()
{
    Node *head;
    int arr[5] = {1, 2, 3, 4, 5};

    createList(&head, arr, 5);
    display(head);
    displayR(head);
    return 0;
}