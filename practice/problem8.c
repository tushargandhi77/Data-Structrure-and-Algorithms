#include "stdio.h"
#include "stdlib.h"

struct node *f;
struct node *r;

struct node
{
    int data;
    struct node *next;
};

void enqueue(int val)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));

    if (n == NULL)
    {
        printf("queue is full\n");
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
    struct node *n = f;
    if (f == NULL)
    {
        printf("queue is empty\n");
    }
    else
    {
        f = f->next;
        val = f->data;
        free(n);
    }
    return val;
}

void transverse(struct node *ptr)
{
    printf("The element of queue:\n");
    while (ptr != NULL)
    {
        printf("element:%d\n", ptr->data);
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
            printf("Enter the element which you want enqueue:");
            scanf("%d", &y);
            enqueue(y);
            break;
        case 2:
            printf("The dequeue element:%d\n", dequeue());
            break;
        case 3:
            transverse(f);
            break;
        case 4:
            exit(0);
        default:
            printf("invalid input!");
            break;
        }
    }
}