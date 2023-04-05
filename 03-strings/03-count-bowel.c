#include <stdio.h>

int CountBowel(char *str)
{
    int res = 0;

    for (int i = 0; str[i] != '\0'; i++)
        switch (str[i])
        {
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            res++;
            break;
        }

    return res;
}

int main()
{
    char str[] = "HELLO WORLD";
    printf("%d\n", CountBowel(str));

    return 0;
}