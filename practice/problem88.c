#include"stdio.h"
#include"stdlib.h"

struct queue{
    int f;
    int r;
    int size;
    int *a;
};

void initqueue(struct queue *q,int size){
    q->f = 0;
    q->r = 0;
    q->size = size;
    q->a = (int *)malloc(size*sizeof(int));
}

void enqueue(struct queue *q,int val){
    int index;
    index = (q->f+q->r)%q->size;
    if(index==q->f && q->r!=0){
        printf("\nQueue is Full\n");
    }
    else{
        q->r++;
        q->a[index] = val;
    }
}

int dequeue(struct queue *q){
    int elem=-1000;
    if(q->r==0){
        printf("\nQueue is Empty\n");
    }
    else{
        elem = q->a[q->f];
        q->r--;
        q->f = (q->f+1)%q->size;
    }
    return elem;
}

void display(struct queue *q){
    if(q->r==0){
        printf("{}");
    }
    else{
        int index,i;
        printf("\nThe queue:\n");
        for(index=q->f,i=1;i<=q->r;i++,index++){
            printf("%d ",q->a[index%q->size]);
        }
    }
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