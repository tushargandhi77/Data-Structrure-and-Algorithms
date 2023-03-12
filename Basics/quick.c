#include "stdio.h"
#include "stdlib.h"

void input(int *arr, int n)
{
    printf("\nEnter the array element:\n");
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
}

void display(int *arr, int n)
{
    printf("\nThe array:\n");
    int i;
    for (i = 0; i < n; i++)
    {
        printf(" %d ", arr[i]);
    }
    printf("\n");
}

int partition(int *arr, int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    int temp;
    do
    {
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    } while (i < j);

    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    return j;
}

void quicksort(int *arr, int low, int high)
{
    int partidata;

    if (low < high)
    {
        partidata = partition(arr, low, high);
        quicksort(arr, low, partidata - 1);
        quicksort(arr, partidata + 1, high);
    }
}

int main()
{
    int arr[100], n, key;
    printf("Enter the size of array:");
    scanf("%d", &n);
    input(arr, n);
    display(arr, n);
    quicksort(arr, 0, n - 1);
    display(arr, n);
}