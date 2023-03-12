#include"stdio.h"
#include"stdlib.h"

struct queue *f;
struct queue *r;

struct queue{
    int data;
    struct queue *next;
};

void enqueue(int val){
    struct queue *n = (struct queue*)malloc(sizeof(struct queue));
    if(n==NULL){
        printf("queue is full\n");
    }
    else{
        n->data = val;
        n->next = NULL;
        if(f==NULL){
            f=r=n;
        }
        else{
            r->next = n;
            r=n;
        }
    }
}

int dequeue(){
    struct queue *ptr = f;
    int val=-1;
    if(f==NULL){
        printf("queue is empty\n");
    }
    else{
        f=f->next;
        val = ptr->data;
        free(ptr);
    }
    return val;
}

void transversal(struct queue *ptr){
    printf("printing the element of queue:\n");
    while(ptr!=NULL){
        printf("Element:%d\n",ptr->data);
        ptr=ptr->next;
    }
}

int main(){
    int x,y;
    while(1){
        printf("\nEnter 1 for enqueue\nEnter 2 for dequeue\nEnter 3 for display queue\nEnter 4 for exit\n");
        scanf("%d",&x);
        switch (x)
        {
        case 1:
            printf("Enter the element to enque:");
            scanf("%d",&y);
            enqueue(y);
            break;
        case 2:
            printf("The dequeue element:%d\n",dequeue());
            break;
        case 3:
            transversal(f);
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Enter valid input!");
            break;
        }
    }
}