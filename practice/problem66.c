#include "stdio.h"
#include "stdlib.h"

int top = -1;
int size = 10;
int arr[100];

int isfull()
{
    if (top == size - 1)
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
    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(int val)
{
    if (isfull())
    {
        printf("Stack overflow\n");
    }
    else
    {
        top++;
        arr[top] = val;
    }
}

int pop()
{
    int val = -1;
    if (isempty())
    {
        printf("stack underflow\n");
    }
    else
    {
        val = arr[top];
        top--;
    }
    return val;
}

void display()
{
    int i;
    printf("The stack:\n");
    for (i = 0; i <= top; i++)
    {
        printf(" %d ", arr[i]);
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
            push(d);
            break;
        case 2:
            printf("The pop element:%d\n", pop());
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