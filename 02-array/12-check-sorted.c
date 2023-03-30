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

bool Check(int *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
        if (arr[i] > arr[i + 1])
            return false;

    return true;
}

int main()
{
    int arr[5] = {1, 3, 5, 7, 9};
    int arr2[5] = {1, 4, 2, 5, 3};

    printf("%d\n", Check(arr, 5));
    printf("%d\n", Check(arr2, 5));
    return 0;
}