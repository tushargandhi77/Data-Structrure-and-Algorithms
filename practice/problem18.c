#include"stdio.h"
#include"stdlib.h"

struct node{
    int data;
    struct node *next;
};
struct node *head = NULL;

struct node *createnode(){
    struct node *newnode , *temp;
    int i,n;
    printf("Enter the sizeof node:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("The element of node %d\n",i+1);
        scanf("%d",&newnode->data);
        newnode->next = NULL;
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

void traversal(){
    struct node *ptr = head;
    printf("The linkedlist:\n");
    while(ptr!=NULL){
        printf("element:%d\n",ptr->data);
        ptr = ptr->next;
    }
}
int main(){
    createnode();
    traversal();
}