#include "stdio.h"
#include "stdlib.h"

int f = -1;
int r = -1;
int size = 10;
int a[100];

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
    if ((f == -1 && r == -1) || (f == r))
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
        printf("Queue overflow\n");
    }
    else
    {
        r++;
        a[r] = val;
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
        f++;
        val = a[f];
    }
    return val;
}

void display()
{
    printf("\nThe Queue:\n");
    for (int i = f; i < r; i++)
    {
        printf(" %d ", a[i + 1]);
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