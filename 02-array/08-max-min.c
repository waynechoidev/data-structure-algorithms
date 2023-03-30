#include <stdio.h>

int Max(int *arr, int size)
{
    int max = arr[0];

    for (int i = 1; i < size; i++)
        if (arr[i] > max)
            max = arr[i];

    return max;
}

int Min(int *arr, int size)
{
    int min = arr[0];

    for (int i = 1; i < size; i++)
        if (arr[i] < min)
            min = arr[i];

    return min;
}

int main()
{
    int arr[10] = {2, 5, 40, 23, 12, 1, 8, 7, 9, 10};

    printf("max: %d\n", Max(arr, 10));
    printf("min: %d\n", Min(arr, 10));

    return 0;
}