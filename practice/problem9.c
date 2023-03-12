#include "stdio.h"
#include "stdlib.h"

struct node
{
    int data;
    struct node *next;
};

struct node *f = NULL;
struct node *r = NULL;

void enqueue(int val)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));

    if (n == NULL)
    {
        printf("queue is full\n");
    }
    else
    {
        n->next = NULL;
        n->data = val;
        if (f == NULL)
        {
            r = f = n;
        }
        else
        {
            r->next = n;
            r = n;
        }
    }
}

int dequeue()
{
    struct node *n = f;
    int val = -1;
    if (f == NULL)
    {
        printf("queue is empty\n");
    }
    else
    {
        val = f->data;
        f = f->next;
    }
    return val;
}

void display(struct node *ptr)
{
    printf("The queue:\n");
    while (ptr != NULL)
    {
        printf("Element:%d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    int x, y;
    while (1)
    {
        printf("\nEnter 1 for enqueue\nEnter 2 for dequeue\nEnter 3 for display\nEnter 4 for exit\n");
        scanf("%d", &x);
        switch (x)
        {
        case 1:
            printf("Enter the enqueue element:");
            scanf("%d", &y);
            enqueue(y);
            break;
        case 2:
            printf("The dequeue element:%d\n", dequeue());
            break;
        case 3:
            display(f);
            break;
        case 4:
            exit(0);
            break;

        default:
            printf("enter valid input!");
            break;
        }
    }
}