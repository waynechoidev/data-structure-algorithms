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

void removeDuplicates(Node *head)
{
    int store[100] = {0};

    Node *p = head;

    store[p->data] = 1;

    while (p->next)
    {
        if (store[p->next->data])
        {
            p->next = p->next->next;
        }
        else
        {
            store[p->next->data] = 1;
            p = p->next;
        }
    }
}

int main()
{
    Node *head;
    int arr[10] = {1, 2, 4, 2, 3, 10, 8, 2, 7, 7};
    createList(&head, arr, 10);

    removeDuplicates(head);

    display(head);

    return 0;
}