#include "stdio.h"
#include "stdlib.h"

struct queue
{
    int f;
    int r;
    int size;
    int *arr;
};

int isempty(struct queue *q)
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

int isfull(struct queue *q)
{
    if (q->r == q->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(struct queue *q, int val)
{
    if (isfull(q))
    {
        printf("queue is full\n");
    }
    else
    {
        q->r++;
        q->arr[q->r] = val;
    }
}

int dequeue(struct queue *q)
{
    int val = -1;
    if (isempty(q))
    {
        printf("queue is empty\n");
    }
    else
    {
        q->f++;
        val = q->arr[q->f];
    }
    return val;
}

void display(struct queue *q)
{
    int i;
    printf("\nThe queue:\n");
    for (i = q->f ; i < q->r; i++)
    {
        printf("\t%d", q->arr[i+1]);
    }
}

int main()
{
    int x, y, z;
    printf("Enter the size of queue:");
    scanf("%d", &x);
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->size = x;
    q->f = q->r = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));

    while (1)
    {
        printf("\nEnter 1 for enqueue\nEnter 2 for dequeue\nEnter 3 for display\nEnter 4 for exit\n");
        scanf("%d", &y);
        switch (y)
        {
        case 1:
            printf("Enter the enqueue element:");
            scanf("%d", &z);
            enqueue(q, z);
            break;
        case 2:
            printf("The dequeue element:%d\n", dequeue(q));
            break;
        case 3:
            display(q);
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
