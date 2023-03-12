#include "stdio.h"
#include "stdlib.h"

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head, *tail;

struct node *createnode()
{
    struct node *newnode, *temp;
    int i, n;
    printf("Enter the number of node:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data of double linked list at node %d:", i + 1);
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        newnode->prev = NULL;
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
            newnode->prev = temp;
            tail = newnode;
        }
    }
}

void traversal()
{
    struct node *ptr = head;
    printf("The doubly link list:");
    while (ptr != NULL)
    {
        printf(" %d ", ptr->data);
        ptr = ptr->next;
    }
}

struct node *insertatfirst()
{
    int i, x;
    printf("Enter the element which you want to insert:");
    scanf("%d", &x);
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = x;
    ptr->next = head;
    head->prev = ptr;
    return ptr;
}

struct node *insertatend()
{
    int i, x;
    printf("Enter the element which you want to insert:");
    scanf("%d", &x);
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = x;
    ptr->prev = tail;
    tail->next = ptr;
    return head;
}
struct node *insertatindex()
{
    int i = 0, x, index;
    printf("Enter the element which you want to insert:");
    scanf("%d", &x);
    printf("Enter the index where you insert:");
    scanf("%d", &index);
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;
    while (i != index - 2)
    {
        p = p->next;
        i++;
    }
    ptr->data = x;
    ptr->prev = p;
    ptr->next = p->next;
    p->next = ptr;
    ptr->next->prev = ptr;

    return head;
}

struct node *insertafterindex()
{
    int i = 0, x, index;
    printf("Enter the element which you want to insert:");
    scanf("%d", &x);
    printf("Enter the index where you insert:");
    scanf("%d", &index);
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->data = x;
    ptr->prev = p;
    ptr->next = p->next;
    p->next = ptr;
    p->next->prev = ptr;
    return head;
}

void main()
{
    createnode();
    traversal();
    printf("\n");
    // head = insertatfirst();
    // head = insertatend();
    head = insertatindex();
    traversal();
}