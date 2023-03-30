// Finding Max and Min in a Single Scan
#include <stdio.h>

void Find(int *arr, int length, int k)
{
    int min = arr[0], max = arr[0];

    for (int i = 0; i < length; i++)
    {
        if (arr[i] < min)
            min = arr[i];

        if (arr[i] > max)
            max = arr[i];
    }

    printf("Min is %d.\n", min);
    printf("Max is %d.\n", max);
}

int main()
{
    int arr[10] = {5, 8, 3, 9, 6, 2, 10, 7, -1, 4};
    Find(arr, 10, 10);

    return 0;
}