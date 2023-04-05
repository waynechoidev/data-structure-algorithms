#include <stdio.h>

void Reverse(char *str)
{
    int i = 0, j = 0;

    while (!!str[j])
        j++;

    j--;

    while (i < j)
    {
        char temp = str[i];
        str[i++] = str[j];
        str[j--] = temp;
    }
}

int main()
{
    char str[] = "abcdef";

    Reverse(str);

    printf("%s\n", str);
}