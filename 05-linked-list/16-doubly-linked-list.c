#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    Node *prev;
    Node *next;
} Node;

void createList(Node **head, Node **tail, int *arr, int size)
{
    *head = (Node *)malloc(sizeof(Node));
    Node *last = *head;
    last->data = arr[0];
    last->prev = NULL;
    last->next = NULL;

    for (int i = 1; i < size; i++)
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = arr[i];
        newNode->prev = last;
        newNode->next = NULL;

        last->next = newNode;
        last = newNode;
    }

    *tail = last;
}

void displayFwd(Node *head)
{
    Node *p = head;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void displayBwd(Node *tail)
{
    Node *p = tail;
    while (p)
    {
        printf("%d ", p->data);
        p = p->prev;
    }
    printf("\n");
}

void reverse(Node **head, Node **tail)
{
    Node *p = *head;
    Node *temp;
    while (p)
    {
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;

        p = p->prev;
    }

    temp = *head;
    *head = *tail;
    *tail = temp;
}

int main()
{
    Node *head;
    Node *tail;
    int arr[7] = {1, 2, 3, 4, 5, 6, 7};

    createList(&head, &tail, arr, 7);
    reverse(&head, &tail);

    displayFwd(head);
    // displayBwd(tail);

    return 0;
}