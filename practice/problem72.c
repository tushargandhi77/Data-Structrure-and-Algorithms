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
    struct node *temp;
    int i, n;
    printf("Enter the number of nodes:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        struct node *n = (struct node *)malloc(sizeof(struct node));
        printf("Enter the value of node %d:", i + 1);
        scanf("%d", &n->data);
        n->next = NULL;
        if (head == NULL)
        {
            head = n;
        }
        else
        {
            temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = n;
        }
        tail = n;
    }
}

void traversal()
{
    struct node *ptr = head;
    printf("\nThe linked list:\n");
    while (ptr != NULL)
    {
        printf(" %d ", ptr->data);
        ptr = ptr->next;
    }
}

int length()
{
    struct node *ptr = head;
    int count = 0;
    printf("\nThe linked list:\n");
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }
}

struct node *insertatfirst()
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    int data;
    printf("\nEnter the data want to insert:");
    scanf("%d", &data);
    ptr->data = data;
    ptr->next = head;
    head = ptr;
    return head;
}

struct node *insertatend()
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    int data;
    printf("\nEnter the data want to insert:");
    scanf("%d", &data);
    ptr->data = data;
    tail->next = ptr;
    ptr->next = NULL;
    tail = ptr;
    return head;
}

struct node *insertatindex()
{
    int index, i = 0, d;
    printf("\nEnter the index:");
    scanf("%d", &index);
    if (index == 1)
    {
        insertatfirst();
    }
    else if (index == length())
    {
        insertatend();
    }

    else if (index > length())
    {
        printf("insertion not possible");
    }
    else
    {
        printf("Enter the want to insert:");
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
    }
    return head;
}

struct node *deleteatfirst()
{
    struct node *p = head;
    head = head->next;
    free(p);
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

struct node *deleteatindex()
{
    int index, i = 0;
    printf("\nEnter the index where want to insert:");
    scanf("%d", &index);
    if (index == 1)
    {
        deleteatfirst();
    }
    else if (index == length())
    {
        deleteatend();
    }
    else if (index > length())
    {
        printf("deletion not possible");
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
        return head;
    }
}
int main()
{
    createnode();
    traversal();
    head = deleteatindex();
    traversal();
}