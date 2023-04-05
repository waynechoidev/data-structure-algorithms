#include <stdio.h>

void CheckAnagram(char *str, char *str2)
{
    int hash[26] = {0};

    int i, j;

    for (i = 0; str[i]; i++)
        hash[str[i] - 97] += 1;

    for (j = 0; str2[j]; j++)
    {
        int code = str2[j] - 97;
        hash[code] -= 1;
        if (hash[code] < 0)
        {
            printf("It is not anagram\n");
            return;
        }
    }

    if (i == j)
        printf("It is anagram\n");
    else
        printf("It is not anagram\n");
}

int main()
{
    char str[] = "decimal";
    char str2[] = "medical";

    CheckAnagram(str, str2);

    return 0;
}