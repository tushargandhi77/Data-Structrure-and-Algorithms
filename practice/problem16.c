#include"stdio.h"
#include"stdlib.h"

struct cqueue{
    int f;
    int r;
    int size;
    int *arr;
};

int isEmpty(struct cqueue *q){
    if(q->f == q->r){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct cqueue *q){
    if((q->r+1)%q->size == q->f){
        return 1;
    }
    else{
        return 0;
    }
}

void enqueue(struct cqueue *q,int val){
    if(isFull(q)){
        printf("queue is full\n");
    }
    else{
        q->r = (q->r+1)%q->size;
        q->arr[q->r] = val;
    }
}

int dequeue(struct cqueue *q){
    int val = -1;
    if(isEmpty(q)){
        printf("queue is empty\n");
    }
    else{
        q->f = (q->f+1)%q->size;
        val = q->arr[q->f];
    }
    return val;
}

void display(struct cqueue *q){
    if(isEmpty(q)){
        printf("queue is empty\n");
    }
    else{
        printf("\nThe queue:\n");
        for(int i = q->f ;i!=q->r;i=(i+1)%q->size){
            printf("\t%d",q->arr[i+1]);
        }
    }
}

int main()
{
    int x, y, z;
    printf("Enter the size of queue:");
    scanf("%d", &x);
    struct cqueue *q = (struct cqueue *)malloc(sizeof(struct cqueue));
    q->size = x + 1;
    q->f = q->r = 0;
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