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

    Node *first = head;
    Node *last = first->next;

    while (first && last)
    {
        if (first->data == last->data)
        {
            first->next = last->next;
            free(last);
            last = first->next;
        }
        else
        {
            first = first->next;
            last = last->next;
        }
    }
}

int main()
{
    Node *head;
    int arr[10] = {1, 2, 2, 3, 3, 3, 4, 5, 5, 6};
    createList(&head, arr, 10);

    removeDuplicates(head);

    display(head);

    return 0;
}