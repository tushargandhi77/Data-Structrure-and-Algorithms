#include "stdio.h"
#include "stdlib.h"

struct Node
{
    int data;
    struct Node *next;
};

void tranverse(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element:%d\n", ptr->data);
        ptr = ptr->next;
    }
}
struct Node *InsertAtfirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}
struct Node *InsertAtindex(struct Node *head, int index, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}
struct Node *InsertAtend(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    ptr->data = data;
    return head;
}
struct Node *InsertAtnode(struct Node *head, struct Node *previousnode, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = previousnode->next;
    previousnode->next = ptr;
    return head;
}
int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 11;
    head->next = second;

    second->data = 12;
    second->next = third;

    third->data = 13;
    third->next = fourth;

    fourth->data = 14;
    fourth->next = NULL;

    tranverse(head);
    printf("\n");
    // head = InsertAtfirst(head,10);
    // head = InsertAtindex(head,3,10);
    // head = InsertAtend(head ,16);
    head = InsertAtnode(head, third, 19);
    tranverse(head);
}