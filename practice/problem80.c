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
        printf("\nEnter the date of node %d:\n", i + 1);
        scanf("%d", &newnode->data);
        newnode->prev = NULL;
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
            newnode->prev = temp;
            tail = newnode;
        }
    }
    tail->next = head;
    head->prev = tail;
}

void traverse()
{
    if (head == NULL)
    {
        printf("\nLinked list is empty\n");
        return;
    }
    struct node *temp = head;
    printf("\nThe circular doubly linked list:\n");
    while (temp->next != head)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d", temp->data);
}

void rev_traverse()
{
    if (head == NULL)
    {
        printf("\nLinked list is empty\n");
        return;
    }
    struct node *temp = tail;
    printf("\nThe circular doubly linked list:\n");
    while (temp->prev != tail)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
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
}

void insertatfirst()
{
    if (head == NULL)
    {
        printf("\nLinked list is empty\n");
        return;
    }
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the data want to insert:\n");
    scanf("%d", &ptr->data);
    ptr->next = head;
    head->prev = ptr;
    head = ptr;
    tail->next = head;
    head->prev = tail;
}

void insertatend()
{
    if (head == NULL)
    {
        printf("\nLinked list is empty\n");
        return;
    }
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the data want to insert:\n");
    scanf("%d", &ptr->data);
    tail->next = ptr;
    ptr->prev = tail;
    tail = ptr;
    tail->next = head;
    head->prev = tail;
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
        printf("\nEnter the data want to insert:\n");
        scanf("%d", &ptr->data);
        while (i != index - 2)
        {
            temp = temp->next;
            i++;
        }
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
        printf("\nLinked list is empty\n");
        return;
    }
    if (head->next == head)
    {
        head = NULL;
        tail = NULL;
        return;
    }
    head = head->next;
    tail->next = head;
    head->prev = tail;
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
        tail = NULL;
        return;
    }
    tail = tail->prev;
    tail->next = head;
    head->prev = tail;
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
        tail = NULL;
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
        free(temp);
    }
}

int main()
{
    createnode();
    int x;
    while (1)
    {
        printf("\nEnter 1 for traverse!\n");
        printf("Enter 2 for insertatfirst\n");
        printf("Enter 3 for insertatend\n");
        printf("Enter 4 for insertatindex\n");
        printf("Enter 5 for deleteatfirst\n");
        printf("Enter 6 for deleteatend\n");
        printf("Enter 7 for deleteatindex\n");
        printf("Enter 8 for reverse list\n");
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