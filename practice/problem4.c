#include "stdio.h"
#include "stdlib.h"

struct queue
{
    int f;
    int r;
    int size;
    int *arr;
};

int isEmpty(struct queue *ptr)
{
    if (ptr->f == ptr->r)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct queue *ptr)
{
    if (ptr->r == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(struct queue *ptr, int val)
{
    if (isFull(ptr))
    {
        printf("queue overflow\n");
    }
    else
    {
        ptr->r++;
        ptr->arr[ptr->r] = val;
    }
}

int dequeue(struct queue *ptr)
{
    int a = -1;
    if (isEmpty(ptr))
    {
        printf("queue underflow\n");
    }
    else
    {
        ptr->f++;
        a = ptr->arr[ptr->f];
    }
    return a;
}

void display(struct queue *ptr)
{
    int i;
    printf("\nThe queue:");
    for (i = ptr->f + 1; i <= ptr->r; i++)
    {
        printf("\t%d", ptr->arr[i]);
    }
}

int main()
{
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    int x, y, z;
    printf("Enter the size of queue:");
    scanf("%d", &x);
    q->f = q->r = -1;
    q->size = x;
    q->arr = (int *)malloc(q->size * sizeof(int));

    for (int i = 0;; i++)
    {
        printf("\nEnter 1 for enqueue\nEnter 2 for dequeue\nEnter 3 for display\nEnter 4 for exit\n");
        scanf("%d", &y);
        switch (y)
        {
        case 1:
            printf("Enter the number to enqueue:");
            scanf("%d", &z);
            enqueue(q, z);
            break;
        case 2:
            printf("The enqueue element:%d\n", dequeue(q));
            break;
        case 3:
            display(q);
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Enter valid input:\n");
            break;
        }
    }
}