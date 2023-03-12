#include "stdio.h"
#include "stdlib.h"

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;

struct node *createnode()
{
    struct node *newnode, *temp;
    int i, n;
    printf("Enter the no of nodes:");
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
            tail = newnode;
        }
    }
    newnode->next = head;
    return newnode;
}

void traversal()
{
    struct node *ptr = head;
    printf("\nThe circular linked list:\n");
    while (ptr->next != head)
    {
        printf(" %d ", ptr->data);
        ptr = ptr->next;
    }
    printf(" %d ", ptr->data);
}

int getlength()
{
    int count = 1;
    struct node *ptr = head;
    while (ptr->next != head)
    {
        count++;
        ptr = ptr->next;
    }
    return count;
}

struct node *Insertatfirst()
{
    int d;
    printf("Enter the data to be insert:");
    scanf("%d", &d);
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = d;
    ptr->next = head;
    head = ptr;
    tail->next = ptr;
    return head;
}

struct node *Insertatend()
{
    int d;
    printf("Enter the data to be insert:");
    scanf("%d", &d);
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = d;
    tail->next = ptr;
    tail = ptr;
    ptr->next = head;
    return head;
}

struct node *Insertatindex()
{
    int d, index, i = 0;
    printf("Enter the index:");
    scanf("%d", &index);

    if (index > getlength())
    {
        printf("index not valid\n");
    }
    else
    {

        if (index == 1)
        {
            Insertatfirst();
        }
        else if (index == getlength())
        {
            Insertatend();
        }
        else
        {
            printf("Enter the data to be insert:");
            scanf("%d", &d);
            struct node *ptr = (struct node *)malloc(sizeof(struct node));
            struct node *p = head;
            while (i != index - 2)
            {
                p = p->next;
                i++;
            }
            ptr->data = d;
            ptr->next = p->next;
            p->next = ptr;
            return head;
        }
    }
}

struct node *deleteatfirst()
{
    struct node *p = head;

    head = head->next;
    tail->next = head;
    free(p);
    return head;
}

struct node *deleteatend()
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
    return head;
}

struct node *deleteatindex()
{
    struct node *p = head;
    struct node *q = head->next;
    int index;
    printf("Enter the index where you delete:");
    scanf("%d", &index);
    if (index > getlength())
    {
        printf("index invalid!");
    }
    else
    {
        if (index == 1)
        {
            deleteatfirst();
        }
        else if (index == getlength())
        {
            deleteatend();
        }
        else
        {
            int i = 0;
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
    return head;
}

int main()
{
    createnode();
    int x;
    while (1)
    {
        printf("\nEnter 1 for traversal\n");
        printf("\nEnter 2 for insertatfirst in circular linked list\n");
        printf("\nEnter 3 for insertatend in circular linked list\n");
        printf("\nEnter 4 for insertatindex in circular linked list\n");
        printf("\nEnter 5 for deleteatfirst in circular linked list\n");
        printf("\nEnter 6 for deleteatend in circular linked list\n");
        printf("\nEnter 7 for deleteatindex in circular linked list\n");
        printf("\nEnter 8 for exit\n");
        scanf("%d", &x);
        switch (x)
        {
        case 1:
            traversal();
            printf("\n");
            break;
        case 2:
            Insertatfirst();
            traversal();
            printf("\n");
            break;
        case 3:
            Insertatend();
            traversal();
            printf("\n");
            break;
        case 4:
            Insertatindex();
            traversal();
            printf("\n");
            break;
        case 5:
            deleteatfirst();
            traversal();
            printf("\n");
            break;
        case 6:
            deleteatend();
            traversal();
            printf("\n");
            break;
        case 7:
            deleteatindex();
            traversal();
            printf("\n");
            break;
        case 8:
            exit(0);
            break;
        default:
            printf("Eneter valid input:");
        }
    }
    return 0;
}