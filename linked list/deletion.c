#include"stdio.h"
#include"stdlib.h"

struct Node{
    int data;
    struct Node *next;
};

void tranversal(struct Node *ptr){
    while(ptr!=NULL){
        printf("Element:%d\n",ptr->data);
        ptr = ptr->next;
    }
}
struct Node *deletefirst(struct Node *head){
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}
struct Node *deleteatindex(struct Node *head,int index){
    struct Node *p = head;
    struct Node *q = head->next;
    int i=0;
    while(i!=index-1){
        p=p->next;
        q=q->next;
        i++;
    }
    p->next = q->next;
    free(q);
    return head;
}
struct Node *deleteatlast(struct Node *head){
    struct Node *p = head;
    struct Node *q = head->next;
    while(q->next!=NULL){
        p=p->next;
        q=q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}
struct Node *deleteatval(struct Node *head,int value){
    struct Node *p = head;
    struct Node *q = head->next;
    while(q->data != value && q->next != NULL){
        p=p->next;
        q=q->next;
    }
    if(q->data == value){
    p->next = q->next;
    }
    free(q);
    return head;
}
int main(){
    struct Node *head = (struct Node*)malloc(sizeof(struct Node));
    struct Node *second = (struct Node*)malloc(sizeof(struct Node));
    struct Node *third = (struct Node*)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node*)malloc(sizeof(struct Node));

    head->data = 11;
    head->next = second;

    second->data = 12;
    second->next = third;

    third->data = 13;
    third->next = fourth;

    fourth->data = 14;
    fourth->next = NULL;

    // head = deletefirst(head);
    // head = deleteatindex(head ,2);
    // head = deleteatlast(head);
    head = deleteatval(head,11);
    tranversal(head);
}