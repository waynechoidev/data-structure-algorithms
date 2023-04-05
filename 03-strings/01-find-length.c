#include <stdio.h>

int FindLength(char *str)
{
    int i;
    for (i = 0; str[i] != '\0'; i++)
    {
    }

    return i;
}

int main()
{
    char str[] = "Hello World";

    printf("%d\n", FindLength(str));
}