#include"stdio.h"
#include"stdlib.h"
struct node{
    int data;
    struct node *next;
};

struct node *head,*tail;

struct node *createnode(){
    struct node *newnode,*temp;
    int i,n;
    printf("Enter the number of node:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data at node %d:",i+1);
        scanf("%d",&newnode->data);
        newnode->next = NULL;
        if(head==NULL){
            head = newnode;
        }
        else{
            temp = head;
            while(temp->next!=NULL){
                temp = temp->next;
            }
            temp->next = newnode;
            tail=newnode;
        }
    }
}

void traverse(){
    struct node *ptr = head;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
}

int main(){
    createnode();
    traverse();
    // printf("%d",tail->data);
}