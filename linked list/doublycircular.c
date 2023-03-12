#include "stdio.h"
#include "stdlib.h"

struct node
{
    struct node *prev;
    struct node *next;
    int data;
};

struct node *head = NULL;
struct node *tail = NULL;

struct node *createnode()
{
    struct node *newnode, *temp;
    int i, n;
    printf("Enter the size of list:");
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
    newnode->next = head;
    head->prev = newnode;
    return newnode;
}

void traversal()
{
    struct node *ptr = head;
    printf("\nThe linked:\n");
    while (ptr->next != head)
    {
        printf(" %d ", ptr->data);
        ptr = ptr->next;
    }
    printf(" %d ", ptr->data);
}
int length()
{
    struct node *ptr = head;
    int count = 1;
    while (ptr->next != head)
    {
        count++;
        ptr = ptr->next;
    }
    return count;
}
struct node *insertatfirst()
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    int d;
    printf("Enter the data to be inserted:");
    scanf("%d", &d);
    ptr->data = d;
    ptr->next = head;
    head->prev = ptr;
    head = ptr;
    tail->next = ptr;
    ptr->prev = tail;
    return head;
}

struct node *insertatend()
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    int d;
    printf("Enter the data to be inserted:");
    scanf("%d", &d);
    ptr->data = d;
    tail->next = ptr;
    ptr->prev = tail;
    tail = ptr;
    tail->next = head;
    head->prev = tail;
    return head;
}

struct node *insertatindex()
{
    int i = 0, d, index;
    printf("Enter the index to be insert:");
    scanf("%d", &index);
    if (index > length())
    {
        printf("insertion not possible at that index!");
        return NULL;
    }
    else if (index == 1)
    {
        insertatfirst();
    }
    else if ((index == length()))
    {
        insertatend();
    }
    else
    {
        struct node *ptr = (struct node *)malloc(sizeof(struct node));
        struct node *p = head;
        printf("Enter the data to be inserted:");
        scanf("%d", &d);
        while (i != index - 2)
        {
            p = p->next;
            i++;
        }
        ptr->data = d;
        ptr->prev = p;
        ptr->next = p->next;
        p->next = ptr;
        ptr->next->prev = ptr;
        return head;
    }
}

struct node *deleteatfirst()
{
    struct node *ptr = head;
    head = head->next;
    tail->next = head;
    head->prev = tail;
    free(ptr);
    return head;
}

struct node *deleteatend()
{
    struct node *ptr = tail;
    tail = tail->prev;
    head->prev = tail;
    tail->next = head;
    free(ptr);
    return head;
}

struct node *deleteatindex()
{
    int i = 0, d, index;
    printf("Enter the index want to delete:");
    scanf("%d", &index);
    if (index > length())
    {
        printf("deletion not possible at insdex!");
    }
    else if (index == 1)
    {
        deleteatfirst();
    }
    else if (index == length())
    {
        deleteatend();
    }
    else
    {
        struct node *ptr = head;
        while (i != index - 1)
        {
            ptr = ptr->next;
            i++;
        }
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
        free(ptr);
        return head;
    }
}
int main()
{
    int x;
    createnode();
    traversal();
    while (1)
    {
        printf("\nEnter 1 for traversal\n");
        printf("\nEnter 2 for insertatfirst\n");
        printf("\nEnter 3 for insertatend\n");
        printf("\nEnter 4 for insertatindex\n");
        printf("\nEnter 5 for deleteatfirst\n");
        printf("\nEnter 6 for deleteatend\n");
        printf("\nEnter 7 for deleteatindex\n");
        printf("\nEnter 8 for length\n");
        printf("\nEnter 9 for exit\n");
        scanf("%d", &x);
        switch (x)
        {
        case 1:
            traversal();
            break;

        case 2:
            head = insertatfirst();
            printf("\n");
            traversal();
            printf("\n");
            break;

        case 3:
            head = insertatend();
            printf("\n");
            traversal();
            printf("\n");
            break;

        case 4:
            head = insertatindex();
            printf("\n");
            traversal();
            printf("\n");
            break;

        case 5:
            head = deleteatfirst();
            printf("\n");
            traversal();
            printf("\n");
            break;

        case 6:
            head = deleteatend();
            printf("\n");
            traversal();
            printf("\n");
            break;

        case 7:
            head = deleteatindex();
            printf("\n");
            traversal();
            printf("\n");
            break;
        case 8:
            printf("The length of circular list:%d\n",length());
            break;
        case 9:
            exit(0);
            break;

        default:
            printf("Enter valid input!!");
            break;
        }
    }
    return 0;
}