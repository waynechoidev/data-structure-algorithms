#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    Node *next;
} Node;

void createCircularList(Node **head, int *arr, int size)
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

    last->next = *head;
}

void display(Node *head)
{
    Node *p = head;
    do
    {
        printf("%d ", p->data);
        p = p->next;
    } while (p != head);

    printf("\n");
}

int main()
{
    Node *head;
    int arr[5] = {1, 2, 3, 4, 5};
    createCircularList(&head, arr, 5);
    display(head);
}