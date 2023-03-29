#include <stdio.h>

void fun1(int n)
{
    if (n > 0)
    {
        printf("%d ", n);
        fun1(n - 1);
    }
}

void fun2(int n)
{
    if (n > 0)
    {
        fun2(n - 1);
        printf("%d ", n);
    }
}

int fun3(int n)
{
    if (n > 0)
    {
        return fun3(n - 1) + n;
    }
    return 0;
}

int main()
{
    int x = 3;
    printf("fun1\n");
    fun1(x);
    printf("\n");
    // 3 2 1

    printf("fun2\n");
    fun2(x);
    printf("\n");
    // 1 2 3

    printf("fun3\n");
    printf("%d\n", fun3(x));
    // 6

    return 0;
}