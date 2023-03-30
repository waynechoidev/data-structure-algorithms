#include <stdio.h>

void Display(int *arr, int size)
{
    printf("{");

    for (int i = 0; i < size; i++)
    {
        printf("%d", arr[i]);
        if (i < size - 1)
            printf(", ");
    }

    printf("}\n");
}

void ShiftRight(int *arr, int size)
{
    for (int i = size - 1; i > 0; i--)
        arr[i] = arr[i - 1];

    arr[0] = 0;
}

void ShiftLeft(int *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
        arr[i] = arr[i + 1];

    arr[size - 1] = 0;
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};

    Display(arr, 5);
    ShiftRight(arr, 5);
    Display(arr, 5);
    ShiftLeft(arr, 5);
    Display(arr, 5);

    return 0;
}