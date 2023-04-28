// Merge two sorted list
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

// Node *mergeList(Node *list1, Node *list2)
// {
//     Node **res = (Node **)malloc(sizeof(Node *));
//     *res = (Node *)malloc(sizeof(Node));
//     Node *last = *res;

//     while (list1 && list2)
//     {
//         Node *newNode = (Node *)malloc(sizeof(Node));

//         if (list1->data > list2->data)
//         {
//             newNode->data = list2->data;
//             list2 = list2->next;
//         }
//         else
//         {
//             newNode->data = list1->data;
//             list1 = list1->next;
//         }

//         last->next = newNode;
//         last = newNode;
//     }

//     while (list1)
//     {
//         Node *newNode = (Node *)malloc(sizeof(Node));
//         newNode->data = list1->data;
//         list1 = list1->next;
//         last->next = newNode;
//         last = newNode;
//     }

//     while (list2)
//     {
//         Node *newNode = (Node *)malloc(sizeof(Node));
//         newNode->data = list2->data;
//         list2 = list2->next;
//         last->next = newNode;
//         last = newNode;
//     }

//     return *res;
// }

Node *mergeList(Node *list1, Node *list2)
{
    Node res;
    Node *last = &res;

    while (list1 && list2)
    {
        if (list1->data > list2->data)
        {
            last->next = list2;
            list2 = list2->next;
        }
        else
        {
            last->next = list1;
            list1 = list1->next;
        }
        last = last->next;
    }

    last->next = (list1) ? list1 : list2;

    return res.next;
}

int main()
{
    Node *head;
    int arr[5] = {1, 5, 7, 9, 11};
    createList(&head, arr, 5);

    Node *head2;
    int arr2[7] = {2, 3, 6, 8, 9, 14, 15};
    createList(&head2, arr2, 7);

    Node *res = mergeList(head, head2);
    display(res);

    return 0;
}