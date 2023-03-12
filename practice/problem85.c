#include"stdio.h"
#include"stdlib.h"


struct node{
    int data;
    struct node *link;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(){
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data want to enqueue:\n");
    scanf("%d",&ptr->data);
    ptr->link = NULL;
    if(front == NULL && rear == NULL){
        front = ptr;
        rear = ptr;
    }
    else{
        rear->link = ptr;
        rear = ptr;
    }
}

int dequeue(){
    int val = -1;
    if(front==NULL && rear == NULL){
        printf("\nQueue is Empty\n");
    }
    else if(front==rear){
        val = front->data;
        front = NULL;
        rear = NULL;
    }
    else{
        val = front->data;
        front = front->link;
    }
    return val;
}

void display(){
    if(front==NULL && rear == NULL){
        printf("{}");
    }
    else{
        struct node *ptr = front;
        printf("\nThe queue:\n");
        while(ptr!=NULL){
            printf("%d ",ptr->data);
            ptr = ptr->link;
        }
    }
}

int main()
{
    int x;
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
            enqueue();
            break;
        case 2:
            printf("\nThe dequeue element is %d\n", dequeue());
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            break;
        }
    }
}