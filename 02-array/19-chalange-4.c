// Finding a Pair With Sum k (a + b = k)
#include <stdio.h>

void Find(int *arr, int length, int k)
{
    bool hash[20] = {false};
    int res = 0;

    for (int i = 0; i < length; i++)
    {
        if (arr[i] < k && hash[k - arr[i]])
        {
            res++;
        }
        hash[arr[i]] = true;
    }

    printf("There is %d of sum with K\n", res);
}

int main()
{
    int arr[10] = {6, 3, 8, 10, 16, 7, 5, 2, 9, 14};
    Find(arr, 10, 10);

    return 0;
}