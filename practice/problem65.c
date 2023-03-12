#include "stdio.h"
#include "stdlib.h"

int f = -1;
int r = -1;
int size;
int arr[100];

int isfull()
{
    if (r == size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isempty()
{
    if (f == -1 && r == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(int val)
{
    if (isfull())
    {
        printf("queue overflow\n");
    }
    else
    {
        r++;
        arr[r] = val;
    }
}

int dequeue()
{
    int val = -1;
    if (isempty())
    {
        printf("queue underflow");
    }
    else
    {
        f++;
        val = arr[f];
    }
    return val;
}

void display()
{
    int i;
    for (i = f; i < r; i++)
    {
        printf(" %d ", arr[i+1]);
    }
}

int main()
{
}