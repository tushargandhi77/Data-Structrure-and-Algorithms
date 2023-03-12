#include"stdio.h"
#include"stdlib.h"

struct node{
    int data;
    struct node *next;
};

struct node *head = NULL;

struct node  *create_linkedlist(){
    int i,n;
    struct node *newnode , *temp;
    printf("Enter the number of nodes:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the value at node %d:",i+1);
        scanf("%d",&newnode->data);
        newnode->next = NULL;
        if(head == NULL){
            head = newnode;
        }
        else{
            temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = newnode;
        }
    }
    return head;
}

void transversal(){
    struct node *temp = head;
    if(head == NULL){
        printf("list is empty:");
    }
    else{
        temp = head;
        while(temp!=NULL){
            printf("The element of list:%d\n",temp->data);
            temp = temp->next;
        }
    }
}

int main(){
    create_linkedlist();
    transversal();
    
}