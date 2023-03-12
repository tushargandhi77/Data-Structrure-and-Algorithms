#include"stdio.h"
#include"stdlib.h"

struct queue{
    int front;
    int rear;
    int size;
    int *a;
};

void initqueue(struct queue *ptr,int maxsize){
    ptr->front = 0;
    ptr->rear = 0;
    ptr->size = maxsize;
    ptr->a = (int *)malloc(maxsize*sizeof(int));
}

void enqueue(struct queue *ptr,int val){
    int index;
    index = (ptr->front+ptr->rear)%ptr->size;
    if(index==ptr->front&&ptr->rear!=0){
        printf("\nQueue is Full\n");
    }
    else{
        ptr->rear++;
        ptr->a[index] = val;
    }
}

int dequeue(struct queue *ptr){
    int elem;
    if(ptr->rear==0){
        printf("\nQueue is Empty\n");
        return -1000;
    }
    elem = ptr->a[ptr->front];
    ptr->rear--;
    ptr->front = (ptr->front+1)%ptr->size;
    return elem;
}

void display(struct queue *ptr){
    int i,index;
    if(ptr->rear == 0){
        printf("{}");
    }
    else{
        for(index=ptr->front,i=1;i<=ptr->rear;i++,index++){
            printf("%d ",ptr->a[index%ptr->size]);
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