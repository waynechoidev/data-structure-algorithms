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

void insertInSortedList(Node **head, int key)
{
    Node *p = *head;

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = key;

    if (p->data >= key)
    {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    while (p)
    {
        if (p->data <= key && p->next->data >= key)
        {
            newNode->next = p->next;
            p->next = newNode;
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
    insertInSortedList(&head, 5);
    insertInSortedList(&head, 15);
    insertInSortedList(&head, 25);
    display(head);
}