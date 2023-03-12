#include "stdio.h"
#include "stdlib.h"

int f = 0;
int r = 0;
int size = 5;
int arr[100];

int isempty()
{
    if (f == r % size)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

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

void enqueue(int val)
{
    if (isfull())
    {
        printf("queue overflow");
    }
    else
    {
        r = r % size + 1;
        arr[r] = val;
    }
}

int dequeue()
{
    int val = -1;
    if (isempty())
    {
        printf("Queue underflow\n");
    }
    else
    {
        f = f % size + 1;
        val = arr[f];
    }
    return val;
}

void display()
{
    int i;
    for (i = f; i < r; i = i % size + 1)
    {
        printf(" %d ", arr[i + 1]);
    }
}

int main()
{
    int x, d;
    while (1)
    {
        printf("\nEnter 1 for push\nEnter 2 for pop\nEnter 3 for display\nEnter 4 for exit\n");
        scanf("%d", &x);
        switch (x)
        {
        case 1:
            printf("\nEnter the value to be push\n");
            scanf("%d", &d);
            enqueue(d);
            break;
        case 2:
            printf("The pop element:%d\n", dequeue());
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        }
    }
}