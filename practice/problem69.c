#include "stdio.h"
#include "stdlib.h"

struct node
{
    int data;
    struct node *next;
};

struct node *top;

int isfull()
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    if (n == NULL)
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
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(int data)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    if (isfull())
    {
        printf("Stack overflow");
    }
    else
    {
        n->data = data;
        n->next = NULL;
        if (top == NULL)
        {
            top = n;
        }
        else
        {
            n->next = top;
            top = n;
        }
    }
}

int pop()
{
    int val = -1;
    if (isempty())
    {
        printf("Stack underflow");
    }
    else
    {
        val = top->data;
        top = top->next;
    }
    return val;
}

void display()
{
    struct node *ptr = top;
    while (ptr != NULL)
    {
        printf(" %d ", ptr->data);
        ptr = ptr->next;
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