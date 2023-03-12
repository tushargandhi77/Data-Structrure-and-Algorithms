#include"stdio.h"
#include"stdlib.h"

struct Node{
     int data;
     struct Node *next; 
};
void transverse(struct Node *head){
    struct Node *ptr = head;
    do{
        printf("Element of circular list:%d\n",ptr->data);
        ptr = ptr->next;
    }while(ptr!=head);
}
int main(){

    struct Node *head = (struct Node*)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fouth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 11;
    head->next = second;

    second->data = 12;
    second->next = third;

    third->data = 13;
    third->next = fouth;

    fouth->data = 14;
    fouth->next = head;

    transverse(head);
}