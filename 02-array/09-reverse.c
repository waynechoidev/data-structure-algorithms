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

void Reverse(int *arr, int size)
{
    int low = 0, high = size - 1;

    while (high > low)
    {
        int temp = arr[low];
        arr[low] = arr[high];
        arr[high] = temp;
        high--;
        low++;
    }
}

void RReverse(int *arr, int size, int low, int high)
{
    if (high > low)
    {
        int temp = arr[low];
        arr[low] = arr[high];
        arr[high] = temp;
        RReverse(arr, size, low + 1, high - 1);
    }
}

int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr2[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    Display(arr, 10);
    Display(arr2, 9);

    Reverse(arr, 10);
    RReverse(arr2, 9, 0, 8);

    Display(arr, 10);
    Display(arr2, 9);

    return 0;
}