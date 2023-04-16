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
    last = *head;
    last->data = arr[0];
    last->next = NULL;

    for (int i = 1; i < size; i++)
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = arr[i];
        newNode->next = NULL;
        last->next = newNode;
        last = last->next;
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

void insertAt(Node **head, int index, int key)
{
    if (index < 0)
        printf("%d is wrong index\n", index);

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = key;

    if (!(*head) && index == 0)
    {
        newNode->next = NULL;
        *head = newNode;
    }
    else if (index == 0)
    {
        newNode->next = *head;
        *head = newNode;
    }
    else if (index > 0)
    {
        Node *p = *head;
        int i;
        for (i = 0; i < index - 1 && p->next != NULL; i++)
            p = p->next;

        if (i != index - 1)
        {
            printf("%d is wrong index\n", index);
            return;
        }

        newNode->next = p->next;
        p->next = newNode;
    }
}

int main()
{
    Node *head = NULL;
    // Node *head = (Node *)malloc(sizeof(Node));
    // int arr[5] = {1, 2, 3, 4, 5};
    // createList(&head, arr, 5);
    // display(head);
    insertAt(&head, 0, 10);
    insertAt(&head, 1, 20);
    insertAt(&head, 2, 30);
    insertAt(&head, 3, 40);
    insertAt(&head, 4, 50);
    insertAt(&head, 77, 50);
    insertAt(&head, 0, 100);

    display(head);

    return 0;
}