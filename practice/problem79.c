#include "stdio.h"
#include "stdlib.h"

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;

void createnode()
{
    struct node *temp, *newnode;
    int i, n;
    printf("\nEnter the number of nodes:\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("\nEnter the element at node %d:\n", i + 1);
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newnode;
            tail = newnode;
        }
    }
    tail->next = head;
}

void traverse()
{
    if (head == NULL)
    {
        printf("\nLinked list is empty\n");
        return;
    }
    struct node *temp = head;
    printf("\nThe Circular linked list :\n");
    while (temp->next != head)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d", temp->data);
}

int count()
{
    int count = 1;
    struct node *temp = head;
    while (temp->next != head)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void insertatfirst()
{
    if (head == NULL)
    {
        printf("\nLinked list is empty\n");
        return;
    }
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    int d;
    printf("\nEnter the data want to insert:\n");
    scanf("%d", &d);
    ptr->data = d;
    ptr->next = head;
    head = ptr;
    tail->next = head;
}

void insertatend()
{
    if (head == NULL)
    {
        printf("\nLinked list is empty\n");
        return;
    }
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    int d;
    printf("\nEnter the data want to insert:\n");
    scanf("%d", &d);
    ptr->data = d;
    tail->next = ptr;
    tail = ptr;
    tail->next = head;
}

void insertatindex()
{
    if (head == NULL)
    {
        printf("\nLinked list is empty\n");
        return;
    }
    int index, i = 0;
    printf("\nEnter the index:\n");
    scanf("%d", &index);
    if (index > count())
    {
        printf("\nEnter valid index\n");
        return;
    }
    else if (index == 1)
    {
        insertatfirst();
        return;
    }
    else if (index == count())
    {
        insertatend();
        return;
    }
    else
    {
        struct node *ptr = (struct node *)malloc(sizeof(struct node));
        struct node *temp = head;
        int d;
        printf("\nEnter the data want to insert:\n");
        scanf("%d", &d);
        ptr->data = d;
        while (i != index - 2)
        {
            temp = temp->next;
            i++;
        }
        ptr->next = temp->next;
        temp->next = ptr;
    }
}

void deleteatfirst()
{
    if (head == NULL)
    {
        printf("\nLinked list is empty\n");
        return;
    }
    if (head->next == head)
    {
        head = NULL;
        return;
    }
    head = head->next;
    tail->next = head;
}

void deleteatend()
{
    if (head == NULL)
    {
        printf("\nLinked list is empty\n");
        return;
    }
    if (head->next == head)
    {
        head = NULL;
        return;
    }
    struct node *p = head;
    struct node *q = head->next;

    while (q->next != head)
    {
        p = p->next;
        q = q->next;
    }
    p->next = head;
    tail = p;
}

void deleteatindex()
{
    if (head == NULL)
    {
        printf("\nLinked list is empty\n");
        return;
    }
    if (head->next == head)
    {
        head = NULL;
        return;
    }
    int i = 0, index;
    printf("\nEnter the index:\n");
    scanf("%d", &index);
    if (index > count())
    {
        printf("\nEnter valid index\n");
        return;
    }
    else if (index == 1)
    {
        deleteatfirst();
        return;
    }
    else if (index == count())
    {
        deleteatend();
        return;
    }
    else
    {
        struct node *p = head;
        struct node *q = head->next;
        while (i != index - 2)
        {
            p = p->next;
            q = q->next;
            i++;
        }
        p->next = q->next;
        free(q);
    }
}

int main()
{
    createnode();
    int x;
    while (1)
    {
        printf("\nEnter 1 for traverse in circular linked list!\n");
        printf("Enter 2 for insertatfirst in circular linked list\n");
        printf("Enter 3 for insertatend in circular linked list\n");
        printf("Enter 4 for insertatindex in circular linked list\n");
        printf("Enter 5 for deleteatfirst in circular linked list\n");
        printf("Enter 6 for deleteatend in circular linked list\n");
        printf("Enter 7 for deleteatindex in circular linked list\n");
        printf("Enter 8 for exit in circular linked list\n");
        printf("Enter your choice in circular linked list\n\n");
        scanf("%d", &x);
        switch (x)
        {
        case 1:
            traverse();
            break;

        case 2:
            insertatfirst();
            break;
        case 3:
            insertatend();
            break;

        case 4:
            insertatindex();
            break;

        case 5:
            deleteatfirst();
            break;

        case 6:
            deleteatend();
            break;

        case 7:
            deleteatindex();
            break;

        case 8:
            printf("Thank You!");
            exit(0);
            break;
        }
    }
    return 0;
}