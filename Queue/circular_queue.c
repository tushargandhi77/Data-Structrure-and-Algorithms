#include "stdio.h"
#include "stdlib.h"

struct circularqueue
{
    int r;
    int f;
    int size;
    int *arr;
};

int isEmpty(struct circularqueue *q)
{
    if (q->f == q->r)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct circularqueue *q)
{
    if ((q->r + 1) % q->size == q->f)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(struct circularqueue *q, int val)
{
    if (isFull(q))
    {
        printf("queue overflow\n");
    }
    else
    {
        q->r = (q->r + 1) % q->size;
        q->arr[q->r] = val;
    }
}

int dequeue(struct circularqueue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        printf("queue underflow\n");
    }
    else
    {
        q->f = (q->f + 1) % q->size;
        a = q->arr[q->f];
    }
    return a;
}

void display(struct circularqueue *q)
{
    printf("\nThe circular queue:");
    for (int i = q->f; i != q->r; i = (i + 1) % (q->size))
    {
        printf("\t%d", q->arr[i + 1]);
    }
}

int main()
{
    struct circularqueue *q = (struct circularqueue *)malloc(sizeof(struct circularqueue));
    int x, y, z;
    printf("Enter the size of circular queue:");
    scanf("%d", &x);
    q->f = q->r = 0;
    q->size = (x + 1);
    q->arr = (int *)malloc(q->size * sizeof(int));

    while (1)
    {
        printf("\nEnter 1 for enqueue\nEnter 2 for dequeue\nEnter 3 for display queue\nEnter 4 for exit\n");
        scanf("%d", &y);
        switch (y)
        {
        case 1:
            printf("Enter the number which you want to insert:");
            scanf("%d", &z);
            enqueue(q, z);
            break;
        case 2:
            printf("The poped element from queue:%d\n", dequeue(q));
            break;
        case 3:
            display(q);
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Enter valid input!\n");
            break;
        }
    }
}
