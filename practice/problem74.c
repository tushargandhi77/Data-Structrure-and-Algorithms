#include "stdio.h"
#include "stdlib.h"
#include "malloc.h"

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;

void createnode()
{
    struct node *newnode, *temp;
    int i, n;
    printf("Enter the number of nodes:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data at node %d:", i + 1);
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
            tail = newnode;
        }
    }
}

void traverse()
{
    struct node *temp = head;
    printf("\nThe linked list is:\n");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int countnode()
{
    int count = 0;
    struct node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void insertatfirst()
{
    int d;
    printf("Enter the data want to insert:");
    scanf("%d", &d);
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = d;
    ptr->next = head;
    head = ptr;
}
void insertatend()
{
    if (head == NULL)
    {
        insertatfirst();
        return;
    }
    int d;
    printf("Enter the data want to insert:");
    scanf("%d", &d);
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = d;
    ptr->next = NULL;
    tail->next = ptr;
    tail = ptr;
}
void insertatindex()
{
    if (head == NULL)
    {
        insertatfirst();
        return;
    }
    int d, i = 1, index;
    printf("Enter the index want to insert:");
    scanf("%d", &index);
    if (index > countnode())
    {
        printf("Enter valid index!");
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
        printf("Enter the data want to insert:");
        scanf("%d", &d);
        struct node *ptr = (struct node *)malloc(sizeof(struct node));
        struct node *temp = head;
        ptr->data = d;
        ptr->next = NULL;
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
    struct node *temp = head;
    if (head->next == NULL)
    {
        head = NULL;
        return;
    }
    head = head->next;
    free(temp);
}
void deleteatlast()
{
    struct node *p = head;
    struct node *q = head->next;
    if (head->next == NULL)
    {
        head = NULL;
        return;
    }
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
}
void deleteatindex()
{
    struct node *p = head;
    struct node *q = head->next;
    int i = 1, index;
    printf("Enter the index:");
    scanf("%d", &index);
    if (index > countnode())
    {
        printf("Input valid index!");
        return;
    }
    else if (index == 1)
    {
        deleteatfirst();
    }
    else if (index == countnode())
    {
        deleteatlast();
    }
    else
    {
        while (i != index - 1)
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
            deleteatlast();
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