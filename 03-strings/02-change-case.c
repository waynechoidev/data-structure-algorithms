#include <stdio.h>

void ToLowerCase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] != 32)
            str[i] += 32;
}

void ReverseCase(char *str)
{
    for (int i = 0; !!str[i]; i++)
        if (str[i] >= 97 && str[i] <= 122)
            str[i] -= 32;
        else if (str[i] >= 65 && str[i] <= 90)
            str[i] += 32;
}

int main()
{
    char str[] = "HELLO WORLD";
    ToLowerCase(str);
    printf("%s\n", str);

    char str2[] = "hELlO wOrLd!";
    ReverseCase(str2);
    printf("%s\n", str2);

    return 0;
}