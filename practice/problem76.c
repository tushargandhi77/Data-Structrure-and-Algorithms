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
    int n, i;
    printf("Enter the number of nodes:\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data of node %d:", i + 1);
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
}

void traverse()
{
    struct node *temp = head;
    printf("\nThe linked list:\n");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void traverse_rev()
{
    struct node *temp = tail;
    printf("\nThe reverse linked list:\n");
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
    int d;
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the data want to insert:");
    scanf("%d", &d);
    if (head == NULL)
    {
        ptr->data = d;
        ptr->next = NULL;
        ptr->prev = NULL;
        head = ptr;
        tail = ptr;
        return;
    }
    ptr->data = d;
    ptr->prev = NULL;
    ptr->next = head;
    head->prev = ptr;
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
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the data want to insert:");
    scanf("%d", &d);
    ptr->data = d;
    ptr->next = NULL;
    ptr->prev = tail;
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
    else
    {
        int index, i = 1, d;
        printf("\nEnter the index:\n");
        scanf("%d", &index);
        if (index > count())
        {
            printf("\nEnter valid index!\n");
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
            struct node *ptr = (struct node *)malloc(sizeof(struct node));
            printf("\nEnter the data want to insert:\n");
            scanf("%d", &d);
            struct node *temp = head;
            while (i != index - 1)
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
}

void deleteatfirst()
{
    if (head == NULL)
    {
        printf("List is empty!");
        return;
    }
    if (head->next == NULL)
    {
        head = NULL;
        tail = NULL;
        return;
    }
    head = head->next;
    head->prev = NULL;
}

void deleteatend()
{

    if (head == NULL)
    {
        printf("List is empty!");
        return;
    }
    if (head->next == NULL)
    {
        head = NULL;
        tail = NULL;
        return;
    }
    tail = tail->prev;
    tail->next = NULL;
}

void deleteatindex()
{

    if (head == NULL)
    {
        printf("List is empty!");
        return;
    }
    if (head->next == NULL)
    {
        head = NULL;
        tail = NULL;
        return;
    }
    else
    {
        int index, i = 0;
        printf("\nEnter the index:\n");
        scanf("%d", &index);
        if (index > count())
        {
            printf("Enter valid index!!!");
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
            traverse_rev();
            break;

        case 9:
            printf("Thank You!");
            exit(0);
        }
    }
    return 0;
}