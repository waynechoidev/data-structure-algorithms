#include <stdio.h>

int Sum(int *arr, int size)
{
    int sum = 0;

    for (int i = 0; i < size; i++)
        sum += arr[i];

    return sum;
}

int RSum(int *arr, int size, int n)
{
    if (n >= 0)
        return arr[n] + RSum(arr, size, n - 1);
    else
        return 0;
}

float Avg(int *arr, int size)
{
    int sum = 0;

    for (int i = 0; i < size; i++)
        sum += arr[i];

    return float(sum) / size;
}

float RAvg(int *arr, int size, int n)
{
    if (n >= 0)
        return (float(arr[n]) / size) + RAvg(arr, size, n - 1);
    else
        return 0;
}

int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    printf("sum : %d\n", Sum(arr, 10));
    printf("sum : %d\n", RSum(arr, 10, 9));
    printf("avg : %f\n", Avg(arr, 10));
    printf("avg : %f\n", RAvg(arr, 10, 9));
    return 0;
}