#include "stdio.h"
#include "stdlib.h"

struct cqueue
{
    int f;
    int r;
    int size;
    int *arr;
};

int isEmpty(struct cqueue *ptr)
{
    if (ptr->r == ptr->f)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct cqueue *ptr)
{
    if ((ptr->r + 1) % ptr->size == ptr->f)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(struct cqueue *ptr, int val)
{
    if (isFull(ptr))
    {
        printf("queue overflow\n");
    }
    else
    {
        ptr->r = (ptr->r + 1) % ptr->size;
        ptr->arr[ptr->r] = val;
    }
}

int dequeue(struct cqueue *ptr)
{
    int val = -1;
    if (isEmpty(ptr))
    {
        printf("queue underflow\n");
    }
    else
    {
        ptr->f = (ptr->f + 1) % ptr->size;
        val = ptr->arr[ptr->f];
    }
    return val;
}

void display(struct cqueue *ptr)
{
    printf("The queue:");
    for (int i = ptr->f; i != ptr->r; i = ((i + 1) % ptr->size))
    {
        printf("\t%d", ptr->arr[i + 1]);
    }
}

int main()
{
    struct cqueue *q = (struct cqueue *)malloc(sizeof(struct cqueue));
    int x, y, z;
    printf("Enter the size of circular queue:");
    scanf("%d", &x);
    q->f = q->r = 0;
    q->size = (x + 1);
    q->arr = (int *)malloc(q->size * (sizeof(int)));
    while (1)
    {
        printf("\nEnter 1 for enqueue\nEnter 2 for dequeue\nEnter 3 for display\nEnter 4 for exit\n");
        scanf("%d", &y);
        switch (y)
        {
        case 1:
            printf("Enter the value to enqueue:");
            scanf("%d", &y);
            enqueue(q, y);
            break;
        case 2:
            printf("The dequeue element:%d\n", dequeue(q));
            break;
        case 3:
            display(q);
            break;
        case 4:
            exit(0);

        default:
            printf("Enter the valid input!");
            break;
        }
    }
}