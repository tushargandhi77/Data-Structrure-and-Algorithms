#include"stdio.h"
#include"stdlib.h"

struct node{
    int data;
    struct node *next;
};

struct node *f = NULL;
struct node *r = NULL;

void enqueue(int val){
    struct node *n = (struct node *)malloc(sizeof(struct node));
    if(n==NULL){
        printf("queue is full\n");
    }
    else{
        n->data = val;
        n->next = NULL;
        if(f==NULL){
            f = r = n;
        }
        else{
            r->next = n;
            r = n;
        }
    }
}

int dequeue(){
    struct node * ptr = f;
    int val = -1;
    if(f==NULL){
        printf("queue is empty\n");
    }
    else{
        val = f->data;
        f = f->next;
        free(ptr);
    }
    return val;
}

void display(struct node *ptr){
    if(ptr==NULL){
        printf("queue is empty\n");
    }
    else{
        printf("\nThe queue:\n");
        while(ptr!=NULL){
            printf("\t%d",ptr->data);
            ptr = ptr->next;
        }
    }
}

int main()
{
    
    int y,z;
    while (1)
    {
        printf("\nEnter 1 for enqueue\nEnter 2 for dequeue\nEnter 3 for display\nEnter 4 for exit\n");
        scanf("%d", &y);
        switch (y)
        {
        case 1:
            printf("Enter the enqueue element:");
            scanf("%d", &z);
            enqueue(z);
            break;
        case 2:
            printf("The dequeue element:%d\n", dequeue());
            break;
        case 3:
            display(f);
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