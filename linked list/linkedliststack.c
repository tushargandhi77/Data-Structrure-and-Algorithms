#include "stdio.h"
#include "stdlib.h"

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

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

void push(int val)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));

    if (n == NULL)
    {
        printf("stack overflow\n");
    }
    else
    {
        n->data = val;
        n->next = top;
        top = n;
    }
}

int pop()
{
    struct node *n = top;
    int val = -1;
    if (top == NULL)
    {
        printf("stack underflow\n");
    }
    else
    {
        val = top->data;
        top = top->next;
        free(n);
    }
    return val;
}

void display(struct node *ptr)
{
    printf("\nThe stack:\n");
    while (ptr != NULL)
    {
        printf("\t%d", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    int x, y;
    while (1)
    {
        printf("\nEnter 1 for push\nEnter 2 for pop\nEnter 3 for display\nEnter 4 for exit\n");
        scanf("%d", &x);
        switch (x)
        {
        case 1:
            printf("Enter push element which you want to push:\n");
            scanf("%d", &y);
            push(y);
            break;
        case 2:
            printf("The poped element:%d\n", pop());
            break;
        case 3:
            display(top);
            break;
        case 4:
            exit(0);
            break;

        default:
            printf("Enter valid input\n");
            break;
        }
    }
}