#include <stdio.h>

void CheckDuplicated(char *str)
{
    long int mask = 0, x = 0;

    for (int i = 0; str[i]; i++)
    {
        x = 1;
        x = x << str[i] - 97;

        if (x & mask > 0)
        {
            printf("It is duplicated\n");
            return;
        }
        else
            mask = x | mask;
    }

    printf("It is not duplicated\n");
}

int main()
{
    char str[] = "abcdefg";
    char str2[] = "abacde";

    CheckDuplicated(str);
    CheckDuplicated(str2);

    return 0;
}