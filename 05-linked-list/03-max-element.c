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

int max(Node *p)
{
    int max = p->data;
    p = p->next;

    while (p)
    {
        if (p->data > max)
            max = p->data;
        p = p->next;
    }

    return max;
}

int main()
{
    Node *head;
    int arr[5] = {3, 24, 19, 1, 7};

    createList(&head, arr, 5);
    printf("%d\n", max(head));

    return 0;
}