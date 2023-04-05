#include <stdio.h>

void Compare(char *str, char *str2)
{
    int i = 0, j = 0;

    while (!!str[i] || !!str2[j])
    {
        if (str[i++] != str2[j++])
        {
            printf("It is different\n");
            return;
        }
    }

    printf("It is same.\n");
}

int main()
{
    char a[] = "hello";
    char b[] = "hello";
    char c[] = "heaab";

    Compare(a, b);
    Compare(a, c);

    return 0;
}