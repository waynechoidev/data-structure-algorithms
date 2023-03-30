// Finding Multiple Missing Element in a Sorted Array
#include <stdio.h>

void Find(int *arr, int length)
{
    printf("Missing elements are");

    for (int i = 0; i < length - 1; i++)
        if (arr[i] + 1 != arr[i + 1])
            printf(" %d", arr[i] + 1);

    printf("\n");
}

int main()
{
    int arr[10] = {1, 2, 4, 5, 7, 8, 9, 11, 12, 13};
    Find(arr, 10);

    return 0;
}