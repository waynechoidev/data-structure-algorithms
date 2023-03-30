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

void Merge(int *arr1, int size1, int *arr2, int size2, int *res)
{
    int i = 0, j = 0, k = 0;
    while (i < size1 && j < size2)
    {
        if (arr1[i] < arr2[j])
            res[k++] = arr1[i++];
        else
            res[k++] = arr2[j++];
    }

    while (i < size1)
        res[k++] = arr1[i++];

    while (j < size2)
        res[k++] = arr2[j++];
}

int main()
{
    int arr[5] = {1, 4, 5, 6, 8};
    int arr2[5] = {2, 3, 5, 10, 12};
    int res[10];

    Merge(arr, 5, arr2, 5, res);

    Display(arr, 5);
    Display(arr2, 5);
    Display(res, 10);
}