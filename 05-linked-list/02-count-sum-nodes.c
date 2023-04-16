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

void count(Node *p)
{
    int i = 0;

    while (p)
    {
        i++;
        p = p->next;
    }

    printf("%d\n", i);
}

void sum(Node *p)
{
    int sum = 0;

    while (p)
    {
        sum += p->data;
        p = p->next;
    }

    printf("%d\n", sum);
}

int main()
{
    Node *head;
    int arr[5] = {1, 2, 3, 4, 5};

    createList(&head, arr, 5);
    count(head);
    sum(head);

    return 0;
}