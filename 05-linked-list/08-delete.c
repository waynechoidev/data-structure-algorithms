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
    printf("\n");
}

void deleteFromList(Node **head, int index)
{
    if (index < 0)
        return;
    if (index == 0)
    {
        *head = (*head)->next;
        return;
    }

    int count = 1;
    Node *p = (*head);
    while (p->next)
    {
        if (index == count++)
        {
            p->next = p->next->next;
            return;
        }
        p = p->next;
    }
}

int main()
{
    Node *head;
    int arr[5] = {10, 20, 30, 40, 50};
    createList(&head, arr, 5);
    deleteFromList(&head, 0);
    deleteFromList(&head, 10);
    deleteFromList(&head, 3);
    deleteFromList(&head, 3);
    deleteFromList(&head, 4);
    display(head);
}