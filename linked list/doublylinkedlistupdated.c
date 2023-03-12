#include "stdio.h"
#include "stdlib.h"

struct node
{
    int data;
    struct node *prev;
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
        printf("\nEnter the data at node %d:\n", i + 1);
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        newnode->prev = NULL;
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
            newnode->prev = temp;
            tail = newnode;
        }
    }
}

void traverse()
{
    if (head == NULL)
    {
        printf("\nList is Empty\n");
        return;
    }
    struct node *temp = head;
    printf("\nThe doubly Linked list:\n");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void rev_traverse()
{
    if (head == NULL)
    {
        printf("\nList is Empty\n");
        return;
    }
    struct node *temp = tail;
    printf("\nThe revese doubly Linked list:\n");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
}

int count()
{

    struct node *temp = head;
    int count = 0;
    while (temp != NULL)
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
        printf("\nList is Empty\n");
        return;
    }
    int d;
    printf("\nEnter the data want to insert:\n");
    scanf("%d", &d);
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = d;
    ptr->next = head;
    head->prev = ptr;
    head = ptr;
    head->prev = NULL;
}

void insertatend()
{
    if (head == NULL)
    {
        printf("\nList is Empty\n");
        return;
    }
    int d;
    printf("\nEnter the data want to insert:\n");
    scanf("%d", &d);
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = d;
    tail->next = ptr;
    ptr->prev = tail;
    tail = ptr;
    tail->next = NULL;
}

void insertatindex()
{
    if (head == NULL)
    {
        printf("\nList is Empty\n");
        return;
    }
    int i = 0, index;
    printf("\nEnter the index:\n");
    scanf("%d", &index);
    if (index > count())
    {
        printf("\nplease enter valid index\n");
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
        int d;
        printf("\nEnter the data want to insert:\n");
        scanf("%d", &d);
        struct node *ptr = (struct node *)malloc(sizeof(struct node));
        struct node *temp = head;
        while (i != index - 2)
        {
            temp = temp->next;
            i++;
        }
        ptr->data = d;
        ptr->next = temp->next;
        ptr->prev = temp;
        temp->next = ptr;
        ptr->next->prev = ptr;
    }
}

void deleteatfirst()
{
    if (head == NULL)
    {
        printf("\nList is Empty\n");
        return;
    }
    if (head->next == NULL)
    {
        head = NULL;
        return;
    }
    head = head->next;
    head->prev = NULL;
}

void deleteatend()
{
    if (head == NULL)
    {
        printf("\nList is Empty\n");
        return;
    }
    if (head->next == NULL)
    {
        head = NULL;
        return;
    }
    tail = tail->prev;
    tail->next = NULL;
}

void deleteatindex()
{
    if (head == NULL)
    {
        printf("\nList is Empty\n");
        return;
    }
    if (head->next == NULL)
    {
        head = NULL;
        return;
    }
    int i = 0, index;
    printf("\nEnter the index:\n");
    scanf("%d", &index);
    if (index > count())
    {
        printf("\nplease enter valid index\n");
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
        struct node *temp = head;
        while (i != index - 1)
        {
            temp = temp->next;
            i++;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }
}

int main()
{
    createnode();
    int x;
    while (1)
    {
        printf("\nEnter 1 for traverse in doubly linked list!\n");
        printf("Enter 2 for insertatfirst in doubly linked list\n");
        printf("Enter 3 for insertatend in doubly linked list\n");
        printf("Enter 4 for insertatindex in doubly linked list\n");
        printf("Enter 5 for deleteatfirst in doubly linked list\n");
        printf("Enter 6 for deleteatend in doubly linked list\n");
        printf("Enter 7 for deleteatindex in doubly linked list\n");
        printf("Enter 8 for reverse list in doubly linked list\n");
        printf("Enter 9 for exit\n");
        printf("Enter your choice\n\n");
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
            rev_traverse();
            break;

        case 9:
            printf("Thank You!");
            exit(0);
        }
    }
    return 0;
}