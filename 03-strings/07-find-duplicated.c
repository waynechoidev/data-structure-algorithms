#include <stdio.h>

void CheckDuplicated(char *str)
{
    bool hash[26] = {0};

    for (int i = 0; str[i]; i++)
    {
        int code = str[i] - 97;
        if (hash[code])
        {
            printf("It is duplicated\n");
            return;
        }
        else
            hash[code] = 1;
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