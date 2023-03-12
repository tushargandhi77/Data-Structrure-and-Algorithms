#include"stdio.h"
#include"stdlib.h"

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

struct node *create_node(){
    struct node *newnode,*temp;
    int i,n;
    printf("Enter the number of nodes:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->next = NULL;
    printf("Enter the value at node %d:\n",i+1);
    scanf("%d",&newnode->data);
    if(head == NULL){
        head = newnode;
    }
    else{
        temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = newnode;
    }
    }
    return newnode;
}

void traversal(struct node *ptr){
    if(ptr==NULL){
        printf("The list is empty\n");
    }
    else{
        printf("The linked list:\n ");
        while(ptr!=NULL){
            printf("Element:%d\n",ptr->data);
            ptr = ptr->next;
        }
    }
}

int main(){
    create_node();
    traversal(head);
}