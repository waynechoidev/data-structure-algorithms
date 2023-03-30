// Finding Single Missing Element in a Sorted Array
#include <stdio.h>

int Find(int *arr, int length)
{
    for (int i = 0; i < length - 1; i++)
        if (arr[i] + 1 != arr[i + 1])
            return arr[i] + 1;

    return -1;
}

int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 7, 8, 9, 10, 11};
    printf("%d\n", Find(arr, 10));

    return 0;
}