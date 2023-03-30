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

void UnionSorted(int *arr, int size, int *arr2, int size2, int *res)
{
    int i = 0, j = 0, k = 0;
    while (i < size && j < size)
    {
        if (arr[i] < arr2[j])
            res[k++] = arr[i++];
        else if (arr[i] > arr2[j])
            res[k++] = arr2[j++];
        else
        {
            res[k++] = arr[i++];
            j++;
        }
    }
    while (i < size)
        res[k++] = arr[i++];

    while (j < size)
        res[k++] = arr2[j++];
}

void UnionONSqrt(int *arr, int size, int *arr2, int size2, int *res)
{
    for (int i = 0; i < size; i++)
        res[i] = arr[i];

    for (int j = 0, k = size; j < size2; j++)
    {
        bool isColapse = false;

        for (int l = 0; l < size; l++)
            if (arr2[j] == arr[l])
                isColapse = true;

        if (!isColapse)
            res[k++] = arr2[j];
    }
}

void UnionON(int *arr, int size, int *arr2, int size2, int *res)
{
    bool anchor[100] = {0};

    for (int i = 0; i < size; i++)
    {
        res[i] = arr[i];
        anchor[arr[i]] = true;
    }

    for (int j = 0, k = size; j < size2; j++)
        if (!anchor[arr2[j]])
            res[k++] = arr2[j];
}

int main()
{
    int arr[5] = {1, 4, 5, 6, 8};
    int arr2[5] = {2, 3, 5, 10, 12};

    int res[10] = {0};
    UnionSorted(arr, 5, arr2, 5, res);
    Display(res, 10);

    int arr3[5] = {1, 6, 8, 7, 2};
    int arr4[5] = {2, 8, 3, 5, 12};

    int res2[10] = {0};
    UnionONSqrt(arr3, 5, arr4, 5, res2);
    Display(res2, 10);

    int res3[10] = {0};
    UnionON(arr3, 5, arr4, 5, res3);
    Display(res3, 10);

    return 0;
}