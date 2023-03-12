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

void push(int val)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    if (isfull())
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
    struct node *ptr = top;
    int val = -1;
    if (isempty())
    {
        printf("stack underflow\n");
    }
    else
    {
        val = ptr->data;
        top = top->next;
    }
    return val;
}

void display(struct node *ptr)
{
    printf("\nThe stack:\n");
    while (ptr != NULL)
    {
        printf("element:%d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    int y, z;
    while (1)
    {
        printf("\nEnter 1 for enqueue\nEnter 2 for dequeue\nEnter 3 for display\nEnter 4 for exit\n");
        scanf("%d", &y);
        switch (y)
        {
        case 1:
            printf("Enter the enqueue element:");
            scanf("%d", &z);
            push(z);
            break;
        case 2:
            printf("The dequeue element:%d\n", pop());
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