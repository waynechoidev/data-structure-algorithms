#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    Node *next;
} Node;

void createList(Node **head, int *arr, int size)
{
    *head = (Node *)malloc(sizeof(Node));
    Node *last = *head;
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

void reverseElement(Node *head)
{
    Node *p = head;
    int store[100] = {0};
    int i = 0;
    while (p)
    {
        store[i++] = p->data;
        p = p->next;
    }

    p = head;

    while (p)
    {
        p->data = store[--i];
        p = p->next;
    }
}

void reverseLinks(Node **head)
{
    Node *first = *head;
    Node *last = (*head)->next;
    first->next = NULL;

    while (first && last)
    {
        Node *temp = last->next;
        last->next = first;
        first = last;
        last = temp;
    }

    *head = first;
}

int main()
{
    Node *head;
    int arr[5] = {1, 2, 3, 4, 5};
    createList(&head, arr, 5);

    reverseElement(head);
    display(head);

    reverseLinks(&head);
    display(head);
}