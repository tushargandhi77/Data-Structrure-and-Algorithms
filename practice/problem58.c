#include"stdio.h"
#include"stdlib.h"

struct node{
    int data;
    struct node *next;
};

struct node *top ;

int isfull(){
    struct node *n = (struct node *)malloc(sizeof(struct node));
    if(n==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int isempty(){
    if(top == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

void push(int val){
    
    struct node *n = (struct node *)malloc(sizeof(struct node));
    if(isfull()){
        printf("Stack overflow");
    }
    else{
        n->data = val;
        n->next = top;
        top = n;
    }
}

int pop(){
    int val = -1;
    struct node *ptr = top;
    if(isempty()){
        printf("stack underflow");
    }
    else{
        val = ptr->data;
        top = top->next;
    }
    free(ptr);
    return val;
}

void display(){
    struct node *ptr = top;
    printf("\nThe stack linked list:");
    while(ptr!=NULL){
        printf(" %d ",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main(){
    int x,val;
    while(1){
        printf("\nEnter 1 for push\nEnter 2 for pop\nEnter 3 for display\nEnter 4 for exit\n");
        scanf("%d",&x);
        switch (x)
        {
        case 1:
      
            printf("Enter the data want to push in stack:");
            scanf("%d",&val);
            push(val);
            break;
        case 2:
            printf("The pop elment:%d\n",pop());
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