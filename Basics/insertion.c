#include "stdio.h"
void input(int *, int);
void display(int *, int);
void insert(int *, int, int, int);
int main()
{
    int arr[100], pos, n, key;
    printf("Enter the size of array:");
    scanf("%d", &n);
    input(arr, n);
    printf("Enter the position where you want to insert:");
    scanf("%d", &pos);
    display(arr, n);
    printf("Enter the value which you want to insert:");
    scanf("%d", &key);
    if (pos > n)
    {
        printf("\ninsertion not possibe:\n");
    }
    else
    {
        printf("\nThe array  after insertion:\n");
        insert(arr, n, pos, key);
        display(arr, n + 1);
    }
    return 0;
}
void input(int *arr, int n)
{
    int i;
    printf("Enter the element of array:");
    for (i = 0; i < n; i++)
    {
        scanf("%d", (arr + i));
    }
}
void display(int *arr, int n)
{
    int i;
    printf("\nThe array is :\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", *(arr + i));
    }
}
void insert(int *arr, int n, int pos, int key)
{
    int i;

    for (i = n - 1; i > pos - 1; i--)
    {
        *(arr + i + 1) = *(arr + i);
    }
    *(arr + pos - 1) = key;
}