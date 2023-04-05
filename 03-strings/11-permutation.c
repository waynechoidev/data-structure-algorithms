#include <stdio.h>

void Perm(char *str, int k)
{
    static int arr[10] = {0};
    static char res[10];

    if (!str[k])
    {
        res[k] = 0;
        printf("%s\n", res);
    }
    else
        for (int i = 0; str[i]; i++)
        {
            if (!arr[i])
            {
                res[k] = str[i];
                arr[i] = 1;
                Perm(str, k + 1);
                arr[i] = 0;
            }
        }
}

int main()
{
    char str[] = "ABC";

    Perm(str, 0);

    return 0;
}