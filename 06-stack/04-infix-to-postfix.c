#include <stdio.h>
#include <stdlib.h>
#define MAX 200

int getPriority(char c)
{
    if (c == '+' || c == '-')
        return 0;
    if (c == '*' || c == '/')
        return 1;
    return -1;
}

void infixToPostfix(char *str)
{
    char stk[MAX] = {0};
    int top = 0;

    for (int i = 0; str[i]; i++)
    {
        char c = str[i];
        if (c >= 'A' && c <= 'Z')
            printf("%c", c);
        else if (c == '(')
            stk[++top] = c;
        else if (c == ')')
        {
            while (stk[top] != '(')
                printf("%c", stk[top--]);
            top--;
        }
        else
        {
            while (top && getPriority(c) <= getPriority(stk[top]))
                printf("%c", stk[top--]);
            stk[++top] = c;
        }
    }

    while (top)
    {
        printf("%c", stk[top--]);
    }
}

int main()
{
    char infix[MAX];
    scanf("%s", infix);

    infixToPostfix(infix);

    return 0;
}