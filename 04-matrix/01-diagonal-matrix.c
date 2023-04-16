#include <stdio.h>

struct Diagonal
{
    int A[10];
    int n;
};

void Display(struct Diagonal *m)
{
    for (int i = 0; i < m->n; i++)
    {
        for (int j = 0; j < m->n; j++)
        {
            if (i == j)
                printf("%d ", m->A[i]);
            else
                printf("%d ", 0);
        }
        printf("\n");
    }
}

void Set(struct Diagonal *m, int i, int j, int x)
{
    if (i == j)
        m->A[i - 1] = x;
}

void Get(struct Diagonal *m, int i, int j)
{
    if (i == j)
        printf("%d\n", m->A[i - 1]);
    else
        printf("0\n");
}

int main()
{
    struct Diagonal m;
    m.n = 4;
    Set(&m, 1, 1, 2);
    Set(&m, 2, 2, 3);
    Set(&m, 3, 3, 4);
    Set(&m, 4, 4, 5);

    Get(&m, 1, 1);
    Get(&m, 1, 2);
    Display(&m);

    return 0;
}