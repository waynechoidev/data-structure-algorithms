#include <stdio.h>

void CheckPalindrome(char *str)
{
    int i = 0, j = 0;
    while (!!str[j])
        j++;
    j--;

    while (i < j)
    {
        if (str[i++] != str[j--])
        {
            printf("It is not palindrome\n");
            return;
        }
    }
    printf("It is palindrome\n");
}

int main()
{
    char a[] = "abcba";
    char b[] = "abccba";
    char c[] = "abcbab";

    CheckPalindrome(a);
    CheckPalindrome(b);
    CheckPalindrome(c);
}