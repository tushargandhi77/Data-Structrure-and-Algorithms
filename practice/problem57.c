#include "stdio.h"
#include "stdlib.h"

struct node
{
    int data;
    struct node *next;
};
struct node *head;
struct node *tail;
struct node *createlinkedlist()
{
    struct node *newnode, *temp;
    int i, n;
    printf("Enter the number of nodes:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data of node %d:", i + 1);
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
    return newnode;
}

void traversal()
{
    struct node *ptr = head;
    printf("\nThe linked list:");
    while (ptr != NULL)
    {
        printf(" %d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int length()
{
    struct node *ptr = head;
    int count = 0;
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }
    return count;
}

struct node *insertatfirst()
{
    int val;
    printf("Enter the value to be insert:");
    scanf("%d", &val);
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = val;
    ptr->next = head;
    head = ptr;
    return head;
}

struct node *insertatend()
{
    int val;
    printf("Enter the value to be insert:");
    scanf("%d", &val);
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = val;
    tail->next = ptr;
    ptr->next = NULL;
    tail = ptr;
    return head;
}

struct node *insertatindex()
{
    int index, i = 0;
    printf("Enter the index:");
    scanf("%d", &index);
    if (index > length())
    {
        printf("enter valid index:");
        return 0;
    }
    if (index == 1)
    {
        insertatfirst();
    }
    if (index == length())
    {
        insertatend();
    }
    else
    {
        int val;
        printf("Enter the value to be insert:");
        scanf("%d", &val);
        struct node *ptr = (struct node *)malloc(sizeof(struct node));
        struct node *p = head;
        while (i != index - 2)
        {
            p = p->next;
            i++;
        }
        ptr->data = val;
        ptr->next = p->next;
        p->next = ptr;
    }
    return head;
}

struct node *deleteatfirst()
{
    struct node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}
struct node *deleteatlast()
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

struct node *deleteatindex()
{

    int index, i = 0;
    printf("Enter the index:");
    scanf("%d", &index);
    if (index > length())
    {
        printf("enter valid index");
        return 0;
    }
    else if (index == 1)
    {
        deleteatfirst();
    }
    else if (index == length())
    {
        deleteatlast();
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
    return head;
}

int main(){
createlinkedlist();
    int x;
    while (1)
    {
        printf("\nEnter 1 for traversal\n");
        printf("\nEnter 2 for insertatfirst in  linked list\n");
        printf("\nEnter 3 for insertatend in  linked list\n");
        printf("\nEnter 4 for insertatindex in  linked list\n");
        printf("\nEnter 5 for deleteatfirst in  linked list\n");
        printf("\nEnter 6 for deleteatend in  linked list\n");
        printf("\nEnter 7 for deleteatindex in  linked list\n");
        printf("\nEnter 8 for exit\n");
        scanf("%d", &x);
        switch (x)
        {
        case 1:
            traversal();
            printf("\n");
            break;
        case 2:
            insertatfirst();
            traversal();
            printf("\n");
            break;
        case 3:
            insertatend();
            traversal();
            printf("\n");
            break;
        case 4:
            insertatindex();
            traversal();
            printf("\n");
            break;
        case 5:
            deleteatfirst();
            traversal();
            printf("\n");
            break;
        case 6:
            deleteatlast();
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