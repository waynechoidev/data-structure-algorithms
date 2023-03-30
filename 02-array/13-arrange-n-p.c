#include <stdio.h>

void Display(int *arr, int length)
{
    printf("{");

    for (int i = 0; i < length; i++)
    {
        printf("%d", arr[i]);
        if (i < length - 1)
            printf(", ");
    }

    printf("}\n");
}

void Arrange(int *arr, int length)
{
    int i = 0, j = length - 1;

    while (i < j)
    {
        if (arr[i] >= 0 && arr[j] < 0)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        if (arr[i] < 0)
            i++;
        if (arr[j] >= 0)
            j--;
    }
}

int main()
{
    int arr[10] = {1, 4, -2, -5, 3, -9, 20, -11, -12, -13};

    Display(arr, 10);
    Arrange(arr, 10);
    Display(arr, 10);

    return 0;
}