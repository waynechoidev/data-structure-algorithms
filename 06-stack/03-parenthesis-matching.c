#include <stdio.h>

int isBalanced(char *str)
{
    int stk[100] = {0};
    int top = 0;

    for (int i = 0; str[i]; i++)
    {
        switch (str[i])
        {
        case '(':
        case '[':
        case '{':
            stk[++top] = str[i];
            break;

        case ')':
            if (stk[top] == '(')
                top--;
            else
                stk[++top] = str[i];
            break;

        case '}':
            if (stk[top] == '{')
                top--;
            else
                stk[++top] = str[i];
            break;

        case ']':
            if (stk[top] == '[')
                top--;
            else
                stk[++top] = str[i];
            break;
        }
    }

    if (top == 0)
        return 1;
    else
        return 0;
}

int main()
{
    char str1[] = "[(a+b)*{(c-d)+(e-f)}]";
    char str2[] = "[(a+b]*{(c-d)+{e-f)}]";

    printf("%d\n", isBalanced(str1));
    printf("%d\n", isBalanced(str2));

    return 0;
}