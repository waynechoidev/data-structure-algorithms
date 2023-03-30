#include <stdio.h>

int Search(int *arr, int size, int key)
{
    int low = 0, mid, high = size;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (key == arr[mid])
            return mid;
        if (key > arr[mid])
        {
            low = mid + 1;
        }
        if (key < arr[mid])
        {
            high = mid - 1;
        }
    }

    return -1;
}

printf

    int
    RSearch(int *arr, int size, int key, int low, int high)
{
    int mid = (low + high) / 2;

    if (low <= high)
    {
        if (key == arr[mid])
            return mid;
        if (key > arr[mid])
            return RSearch(arr, size, key, mid + 1, high);
        if (key < arr[mid])
            return RSearch(arr, size, key, low, mid - 1);
    }

    return -1;
}

int main()
{
    int arr[10] = {1, 3, 5, 6, 8, 10, 15, 17, 19, 30};
    int arr2[9] = {1, 3, 5, 6, 8, 10, 15, 17, 19};

    printf("%d \n", Search(arr, sizeof arr / sizeof(int), 3));
    printf("%d \n", Search(arr2, sizeof arr / sizeof(int), 8));
    printf("%d \n", Search(arr, sizeof arr / sizeof(int), 4));

    printf("%d \n", RSearch(arr, sizeof arr / sizeof(int), 3, 0, sizeof arr / sizeof(int)));
    printf("%d \n", RSearch(arr2, sizeof arr / sizeof(int), 8, 0, sizeof arr / sizeof(int)));
    printf("%d \n", RSearch(arr, sizeof arr / sizeof(int), 4, 0, sizeof arr / sizeof(int)));

    return 0;
}