#include"stdio.h"
#include"stdlib.h"

struct node{
    int data;
    struct node *next;
};

struct node *head = NULL;

struct node *create_node(){
    struct node *newnode,*temp;
    int i,n;
    printf("Enter the  number of node:");
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
            while(temp->next!=NULL){
                temp = temp->next;
            }
            temp->next = newnode;
        }
    }
    return newnode;
}

void traversal(){
    struct node *ptr  = head;
    printf("The element:\n");
    while(ptr!=NULL){
        printf("Element:%d\n",ptr->data);
        ptr = ptr->next;
    }
}

struct node *insertatfirst(int val){
    struct node *ptr = (struct  node *)malloc(sizeof(struct node));
    ptr->data = val;
    ptr->next = head;
    return ptr;
}
struct node *insertatindex(int val,int index){
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node * p = head;
    int i=0;
    while(i!=index-1){
        p=p->next;
        i++;
    }
    ptr->data = val;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

struct node *insertatend(int val){
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    struct node *p = head;
    int i=0;
    while(p->next!=NULL){
        p=p->next;
    }
    ptr->data = val;
    p->next = ptr;
    ptr->next = NULL;
    return head;
}
struct node *deleteatfirst(){
    struct node *p = head;
    head = head->next;
    free(p);
    return head;
}
struct node *deleteatindex(int index){
    struct node *p=head;
    struct node *q = head->next;
    int i=0;
    while(i!=index-1){
        p=p->next;
        q=q->next;
        i++;
    }
    p->next=q->next;
    free(q);
    return head;
}
int main(){
    create_node();
    traversal();
    head = deleteatindex(3);
    printf("\n");
    traversal();
}