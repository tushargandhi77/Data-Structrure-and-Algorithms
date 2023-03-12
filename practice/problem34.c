#include "stdio.h"
#include "stdlib.h"

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

struct node *createnode()
{
    struct node *newnode, *temp;
    int i, n;
    printf("Enter the number of node:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data for node %d:", i + 1);
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        if (head == NULL)
        {
            head = newnode;
        }
        else
        {
            temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newnode;
        }
    }
}

void traversal()
{
    struct node *ptr = head;
    printf("The linked list:\n");
    while (ptr != NULL)
    {
        printf("\t%d", ptr->data);
        ptr = ptr->next;
    }
}

struct node *insertatfirst()
{
    int x;
    printf("Enter the data to insert:");
    scanf("%d", &x);
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = x;
    ptr->next = head;
    return ptr;
}

struct node *insertatindex()
{
    int i = 0, x, index;
    printf("Enter the data to insert:");
    scanf("%d", &x);
    printf("Enter the index where to inset:");
    scanf("%d", &index);
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;
    while (i != index - 2)
    {
        p = p->next;
        i++;
    }
    ptr->data = x;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

struct node *insertatend()
{
    int x;
    printf("Enter the data to insert:");
    scanf("%d", &x);
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    ptr->data = x;
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

struct node *deleteatfirst()
{
    struct node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

struct node *deleteatindex()
{
    struct node *p = head;
    struct node *q = head->next;
    int i = 0, index;
    printf("Enter the index where you want to delete:");
    scanf("%d", &index);
    while (i != index - 2)
    {
        p = p->next;
        q = q->next;
        i++;
    }
    p->next = q->next;
    free(q);
    return head;
}

struct node *deleteatend()
{
    struct node *p = head;
    struct node *q = head->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

void main()
{
    createnode();
    traversal();
    printf("\n");
    // head = insertatfirst();
    head = insertatindex();
    // head = insertatend();
    // head = deleteatfirst();
    // head = deleteatindex();
    // head = deleteatend();
    traversal();
}