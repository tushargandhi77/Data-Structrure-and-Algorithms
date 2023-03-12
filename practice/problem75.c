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
    printf("Enter the number of nodes:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data at node %d:\n", i + 1);
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
    printf("\nThe circular linked list:\n");
    struct node *temp = head;
    while (temp->next != head)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data);
}
int countnode()
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
    int d;
    printf("Enter the data to insert:\n");
    scanf("%d", &d);
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = d;
    ptr->next = head;
    head = ptr;
    tail->next = head;
}
void insertatend()
{
    int d;
    printf("Enter the data to insert:\n");
    scanf("%d", &d);
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = d;
    tail->next = ptr;
    tail = ptr;
    tail->next = head;
}
void insertatindex()
{
    int i = 1, index;
    printf("Enter the index:");
    scanf("%d", &index);
    if (index > countnode())
    {
        printf("Enter the valid input!");
        return;
    }
    else if (index == 1)
    {
        insertatfirst();
    }
    else if (index == countnode())
    {
        insertatend();
    }
    else
    {
        int d;
        printf("Enter the data to insert:\n");
        scanf("%d", &d);
        struct node *temp = head;
        struct node *ptr = (struct node *)malloc(sizeof(struct node));
        ptr->data = d;
        while (i != index - 1)
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
    head = head->next;
    tail->next = head;
}
void deleteatend()
{
    struct node *p = head;
    struct node *q = head->next;
    while (q->next != head)
    {
        p = p->next;
        q = q->next;
    }
    tail = p;
    tail->next = head;
    free(q);
}
void deleteatindex()
{
    int index, i = 1;
    printf("Enter the index:");
    scanf("%d", &index);
    if (index > countnode())
    {
        printf("Enter valid index!");
        return;
    }
    else if (index == 1)
    {
        deleteatfirst();
    }
    else if (index == countnode())
    {
        deleteatend();
    }
    else
    {
        struct node *p = head;
        struct node *q = head->next;
        while (i != index - 1)
        {
            p = p->next;
            q = q->next;
            i++;
        }
        p->next = q->next;
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
        printf("Enter 8 for exit\n");
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
            printf("Thank You!");
            exit(0);
            break;
        }
    }
    return 0;
}