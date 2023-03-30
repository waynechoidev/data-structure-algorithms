#include <stdio.h>

int Get(int *arr, int size, int index)
{
    if (index >= 0 && index < size)
        return arr[index];
    else
        return -1;
}

void Set(int *arr, int size, int index, int x)
{
    if (index >= 0 && index < size)
        arr[index] = x;
}

int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    printf("Get 7 : %d\n", Get(arr, 10, 7));
    Set(arr, 10, 7, 100);
    printf("Get 7 : %d\n", Get(arr, 10, 7));

    return 0;
}