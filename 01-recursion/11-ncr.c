#include <stdio.h>

int ncr(int n, int r)
{
    if (r == 0 || n == r)
        return 1;
    else
        return ncr(n - 1, r - 1) + ncr(n - 1, r);
}
int f(int n)

{

    static int i = 1;

    if (n >= 5)
        return n;

    n = n + i;

    i++;

    return f(n);
}

int main()
{
    printf("%d\n", ncr(4, 2));
    printf("%d\n", f(1));

    return 0;
}