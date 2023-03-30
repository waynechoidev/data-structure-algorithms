#include <stdio.h>

int Search(int *arr, int size, int key)
{
    int res = -1;
    for (int i = 0; i < size; i++)
        if (arr[i] == key)
            res = i;
    return res;
}

int main()
{
    int arr[8] = {3, 5, 2, 7, 5, 6, 8, 1};

    printf("%d \n", Search(arr, sizeof arr / sizeof(int), 3));
    printf("%d \n", Search(arr, sizeof arr / sizeof(int), 8));
    printf("%d \n", Search(arr, sizeof arr / sizeof(int), 4));

    return 0;
}