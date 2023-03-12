#include "stdio.h"
#include "stdlib.h"

struct node
{
    int data;
    struct node *next;
};

struct node *f = NULL;
struct node *r = NULL;

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
    if (f == NULL)
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
    struct node *n = (struct node *)malloc(sizeof(struct node));
    if (isfull())
    {
        printf("Queue overflow\n");
    }
    else
    {
        n->data = val;
        n->next = NULL;
        if (f == NULL)
        {
            f = r = n;
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
    int val = -1;
    if (isempty())
    {
        printf("Queue underflow\n");
    }
    else
    {
        val = f->data;
        f = f->next;
    }
    return val;
}

void display()
{
    struct node *ptr = f;
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
        printf("\nEnter 1 for enqueue\nEnter 2 for dequeue\nEnter 3 for display\nEnter 4 for exit\n");
        scanf("%d", &x);
        switch (x)
        {
        case 1:
            printf("\nEnter the value to be enqueue\n");
            scanf("%d", &d);
            enqueue(d);
            break;
        case 2:
            printf("The dequeue element:%d\n", dequeue());
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