#include"stdio.h"
#include"stdlib.h"

struct queue{
    int f;
    int r;
    int size;
    int *a;
};

int initqueue(struct queue *q,int maxsize){
    q->f = -1;
    q->r = -1;
    q->size = maxsize;
    q->a = (int *)malloc(maxsize*sizeof(int));
}

void enqueue(struct queue *q,int val){
    if((q->f==q->r+1)||(q->f==0 && q->r==q->size-1)){
        printf("\nQueue is Full\n");
    }
    else{
        if(q->f==-1){
            q->f = 0;
        }
        q->r = (q->r+1)%q->size;
        q->a[q->r] = val;
    }
}

int dequeue(struct queue *q){
    int val=-1000;
    if(q->f == -1){
        printf("\nQueue is Empty\n");
    }
    else{
        val = q->a[q->f];
        if(q->f==q->r){
            q->f = -1;
            q->r = -1;
        }
        else{
            q->f = (q->f+1)%q->size;
        }
    }
    return val;
}

void display(struct queue *q){
    int i;
    if(q->f==-1){
        printf("{}");
    }
    else{
        printf("\nThe circular queue\n");
        for(i=q->f;i!=q->r;i=(i+1)%q->size){
            printf("%d ",q->a[i]);
        }
    }
    printf("%d",q->a[i]);
}

int main(){
    struct queue *q = (struct queue*)malloc(sizeof(struct queue));
    int x,n,y;
    printf("\nEnter the size of queue");
    scanf("%d",&n);
    initqueue(q,n);
    while (1)
    {
        printf("\n\nEnter 1 for enqueue\n");
        printf("\nEnter 2 for dequeue\n");
        printf("\nEnter 3 for display\n");
        printf("\nEnter 4 for exit\n");
        printf("\n\nEnter your choice\n");
        scanf("%d", &x);
        switch (x)
        {
        case 1:
            printf("\nEnter the element want to enqueue\n");
            scanf("%d",&y);
            enqueue(q,y);
            break;
        case 2:
            printf("\nThe dequeue element is %d\n", dequeue(q));
            break;
        case 3:
            display(q);
            break;
        case 4:
            exit(0);
            break;
        default:
            break;
        }
    }
}