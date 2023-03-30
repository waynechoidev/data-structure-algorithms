// Finding a Pair With Sum k (a + b = k) in a Sorted Array
#include <stdio.h>

void Find(int *arr, int length, int k)
{
    int i = 0, j = length - 1, res = 0;

    while (i < j)
    {
        if (arr[i] + arr[j] == k)
        {
            res++;
            i++;
            j--;
        }
        else if (arr[i] + arr[j] > k)
            j--;
        else
            i++;
    }

    printf("There is %d of sum with K\n", res);
}

int main()
{
    int arr[10] = {1, 3, 4, 5, 6, 8, 9, 10, 12, 14};
    Find(arr, 10, 10);

    return 0;
}