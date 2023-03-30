#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[100];
    int size;
    int length;
};

void Display(struct Array arr)
{
    printf("{");

    for (int i = 0; i < arr.length; i++)
    {
        printf("%d", arr.A[i]);
        if (i < arr.length - 1)
            printf(", ");
    }

    printf("}\n");
}

void Append(struct Array *arr, int x)
{
    if (arr->length < arr->size)
        arr->A[arr->length++] = x;
}

void Insert(struct Array *arr, int index, int x)
{
    if (index >= 0 && index <= arr->length && arr->length < arr->size)
    {
        for (int i = arr->length; i > index; i--)
            arr->A[i] = arr->A[i - 1];
        arr->A[index] = x;
        arr->length++;
    }
}

void Delete(struct Array *arr, int index)
{
    if (index >= 0 && index < arr->length)
    {
        for (int i = index; i < arr->length - 1; i++)
            arr->A[i] = arr->A[i + 1];
        arr->length--;
    }
}

void Pop(struct Array *arr)
{
    if (arr->length > 0)
        arr->length--;
}

int main()
{
    struct Array arr = {{1, 2, 3, 4, 5}, 10, 5};
    printf("Initialize array : ");
    Display(arr);

    printf("Append : ");
    Append(&arr, 6);
    Display(arr);

    Insert(&arr, 1, 10);
    printf("Insert : ");
    Display(arr);

    Delete(&arr, 2);
    printf("Delete : ");
    Display(arr);

    Pop(&arr);
    printf("Pop : ");
    Display(arr);

    return 0;
}