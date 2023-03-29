#include <stdio.h>

int fib(int n)
{
    int arr[n + 1] = {};

    for (int i = 0; i <= n; i++)
    {
        if (i == 0 || i == 1)
        {
            arr[i] = i;
        }
        else
        {
            arr[i] = arr[i - 1] + arr[i - 2];
        }
    }

    return arr[n];
}

int fib2(int n)
{
    if (n <= 1)
        return n;
    return fib(n - 2) + fib(n - 1);
}

int main()
{
    printf("%d\n", fib(7));
    printf("%d\n", fib2(7));
    return 0;
}