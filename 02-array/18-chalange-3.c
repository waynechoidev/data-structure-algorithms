// Finding Duplicate Elements in an Unsorted Array
#include <stdio.h>

void Find(int *arr, int length)
{
    bool hash[20] = {false};

    for (int i = 0; i < length; i++)
    {
        if (hash[arr[i]])
            printf("Element %d is duplicated.\n", arr[i]);
        else
            hash[arr[i]] = true;
    }
}

int main()
{
    int arr[10] = {8, 3, 6, 4, 6, 5, 6, 8, 2, 7};
    Find(arr, 10);

    return 0;
}