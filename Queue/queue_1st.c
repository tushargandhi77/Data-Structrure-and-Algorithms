#include"stdio.h"
#include"stdlib.h"

struct queue{
    int r;
    int f;
    int size;
    int *arr;
};

int isFull(struct queue *q){
    if(q->r==q->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty(struct queue *q){
    if(q->r==q->f){
        return 1;
    }
    else{
        return 0;
    }
}

void Enqueue(struct queue *q,int val){
    if(isFull(q)){
        printf("stack overflow\n");
    }
    else{
        q->r++;
        q->arr[q->r]=val;
    }
}

int Dequeue(struct queue *q){
    int a=-1;
    if(isEmpty(q)){
        printf("Stack underflow\n");
    }
    else{
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}

void display(struct queue *q){
    if(q->r==-1){
        printf("Queue is empty\n");
    }
    else{
    int i;
    printf("\nThe queue:\n");
    for(i=q->f+1;i<q->r+1;i++){
        printf("%d\t",q->arr[i]);
    }
        }
}

int main(){
    struct queue *sp = (struct queue *)malloc(sizeof(struct queue));
    int x;
    printf("Enter the size of queue:");
    scanf("%d",&x);
    sp->f = sp->r = -1;
    sp->size = x;
    sp->arr = (int *)malloc(sp->size*sizeof(int));

    int a,b;
    for(int i=0;;i++){
        printf("\nEnter 1 for enqueue\nEnter 2 for dequeue\nEnter 3 for display queue\nEnter 4 for exit\n");
        scanf("%d",&a);
        switch (a)
        {
        case 1:
            printf("Enter the number which you want to insert:");
            scanf("%d",&b);
            Enqueue(sp,b);
            break;
        case 2:
            printf("The dequeue element:%d\n",Dequeue(sp));
            break;
        case 3:
            display(sp);
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Enter the valid input\n");
            break;
        }
    }
}