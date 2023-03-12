#include "stdio.h"
#include "stdlib.h"

struct node{
    int data;
    struct node *link;
};

struct node *top = NULL;

void push(){
    struct node *n = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the data be push:\n");
    scanf("%d",&n->data);
    n->link = NULL;
    if(top==NULL){
        top = n;
    }
    else{
        n->link = top;
        top = n;
    }
}

int pop(){
    int val = -1000;
    if(top==NULL){
        printf("\nStack is Empty\n");
        return -1000;
    }
    val = top->data;
    top = top->link;
    return val;
}

void display(){
    struct node *temp = top;
    if(temp==NULL){
        printf("\nStack is empty\n");
        return;
    }
    printf("\nThe stack list:\n");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->link;
    }
}

int main()
{
    int x;
    while (1)
    {
        printf("\n\nEnter 1 for push\n");
        printf("\nEnter 2 for pop\n");
        printf("\nEnter 3 for display\n");
        printf("\nEnter 4 for exit\n");
        scanf("%d", &x);
        switch (x)
        {
        case 1:
            push();
            break;
        case 2:
            printf("\nThe pop element is %d\n", pop());
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