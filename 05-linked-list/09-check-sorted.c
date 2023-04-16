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
        last = last->next;
    }
}

void checkSorted(Node *head)
{
    Node *p = head;
    int res = p->data;
    p = p->next;

    while (p)
    {
        if (p->data <= res)
        {
            printf("It is not sorted\n");
            return;
        }
        res = p->data;
        p = p->next;
    }
    printf("It is sorted\n");
}

int main()
{
    Node *head;
    int arr[5] = {1, 2, 3, 4, 5};
    createList(&head, arr, 5);
    checkSorted(head);

    Node *head2;
    int arr2[5] = {1, 2, 4, 4, 5};
    createList(&head2, arr2, 5);
    checkSorted(head2);

    return 0;
}