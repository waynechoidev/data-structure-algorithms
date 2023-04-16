#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    Node *next;
} Node;

void insertAtLast(Node **head, Node **tail, int key)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = key;
    newNode->next = NULL;

    if (!*head)
    {
        *head = newNode;
        *tail = newNode;
    }
    else
    {
        (*tail)->next = newNode;
        *tail = newNode;
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

int main()
{
    Node *head = NULL, *tail = NULL;
    insertAtLast(&head, &tail, 10);
    insertAtLast(&head, &tail, 20);
    insertAtLast(&head, &tail, 30);
    insertAtLast(&head, &tail, 40);
    insertAtLast(&head, &tail, 50);
    display(head);

    return 0;
}