#include <stdio.h>

void Display(int *arr, int length)
{
    printf("{");

    for (int i = 0; i < length; i++)
    {
        printf("%d", arr[i]);
        if (i < length - 1)
            printf(", ");
    }

    printf("}\n");
}

void Insert(int *arr, int length, int x)
{
    for (int i = length; i > 0; i--)
    {
        if (arr[i - 1] > x)
            arr[i] = arr[i - 1];
        else
            arr[i] = x;
    }
}

int main()
{
    int arr[10] = {2, 4, 5, 7, 9};

    Display(arr, 5);
    Insert(arr, 5, 3);
    Display(arr, 6);
}