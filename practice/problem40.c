#include "stdio.h"
#include "stdlib.h"

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head, *tail;

struct node *createnode()
{
    struct node *newnode, *temp;
    int n;
    printf("Enter the number of nodes:");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data to insert in node %d:", i + 1);
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
}

int lengthlist()
{
    int count = 0;
    struct node *ptr = head;
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }
    return count;
}

void traversal()
{
    struct node *ptr = head;
    printf("\nThe doubly linked list:\n");
    while (ptr != NULL)
    {
        printf(" %d ", ptr->data);
        ptr = ptr->next;
    }
}

struct node *insertatfirst()
{
    int val;
    printf("Enter the value to be inserted:");
    scanf("%d", &val);
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("list is empty!");
        exit(0);
    }
    else
    {
        ptr->data = val;
        ptr->next = head;
        head->prev = ptr;
        ptr->prev = NULL;
        return ptr;
    }
}

struct node *insertatend()
{
    int val;
    printf("Enter the value to be inserted:");
    scanf("%d", &val);
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("list is empty!");
        exit(0);
    }
    else
    {
        ptr->data = val;
        ptr->prev = tail;
        tail->next = ptr;
        ptr->next = NULL;
    }
    return head;
}

struct node *insertatindex()
{
    int index, i = 0;
    int val;
    printf("Enter the value to be inserted:");
    scanf("%d", &val);
    printf("Enter the index where you want to insert:");
    scanf("%d", &index);

    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;
    if (head == NULL)
    {
        printf("list is empty!");
        exit(0);
    }
    if (index > lengthlist())
    {
        printf("insertion not possible!");
        exit(0);
    }
    else
    {
        while (i != index - 2)
        {
            p = p->next;
            i++;
        }
        ptr->data = val;
        ptr->prev = p;
        ptr->next = p->next;
        p->next = ptr;
        p->next->prev = ptr;
    }
    return head;
}
struct node *insertafterindex()
{
    int index, i = 0;
    int val;
    printf("Enter the value to be inserted:");
    scanf("%d", &val);
    printf("Enter the index where you want to insert:");
    scanf("%d", &index);

    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;
    if (head == NULL)
    {
        printf("list is empty!");
        exit(0);
    }
    if (index > lengthlist())
    {
        printf("Insertion not possible!");
        exit(0);
    }
    else
    {
        while (i != index - 1)
        {
            p = p->next;
            i++;
        }
        ptr->data = val;
        ptr->prev = p;
        ptr->next = p->next;
        p->next = ptr;
        p->next->prev = ptr;
    }
    return head;
}

struct node *deleteatfirst()
{
    struct node *ptr = head;
    if (head == NULL)
    {
        printf("list is empty!");
        exit(0);
    }
    else
    {
        head = head->next;
        head->prev = NULL;
        free(ptr);
    }
    return head;
}

struct node *deleteatend()
{
    struct node *ptr = tail;
    if (head == NULL)
    {
        printf("List is empty!");
        exit(0);
    }
    else
    {
        tail = tail->prev;
        tail->next = NULL;
        free(ptr);
    }
    return head;
}

struct node *deleteatindex()
{
    int index;
    int i = 0;
    printf("Enter the index:");
    scanf("%d", &index);

    struct node *ptr = head;
    if (head == NULL)
    {
        printf("list is empty!");
        exit(0);
    }
    if (index > lengthlist())
    {
        printf("Deletion not possible!");
        exit(0);
    }
    if (index == lengthlist())
    {
        deleteatend();
    }
    else
    {
        while (i != index - 1)
        {
            ptr = ptr->next;
            i++;
        }
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
        free(ptr);
    }
    return head;
}

struct node *deleteafterindex()
{
    int index;
    int i = 0;
    printf("Enter the index:");
    scanf("%d", &index);

    struct node *ptr = head;
    if (head == NULL)
    {
        printf("list is empty!");
        exit(0);
    }
    if ((index + 1) > lengthlist())
    {
        printf("Deletion not possible!");
        exit(0);
    }
    if ((index + 1) == lengthlist())
    {
        deleteatend();
    }
    else
    {
        while (i != index)
        {
            ptr = ptr->next;
            i++;
        }
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
        free(ptr);
    }
    return head;
}

struct node *reverse()
{
    struct node *current, *nextnode;
    current = head;
    while (current != 0)
    {
        nextnode = current->next;
        current->next = current->prev;
        current->prev = nextnode;
        current = nextnode;
    }
    current = head;
    head = tail;
    tail = current;

    return head;
}

void main()
{
    createnode();

    int x, x1, x2, x3, x4, i1, i2, i3;
    while (1)
    {
        printf("\nEnter 1 for traversal in doubly linked list\n");
        printf("\nEnter 2 for insertatfirst in doubly linked list\n");
        printf("\nEnter 3 for insertatend in doubly linked list\n");
        printf("\nEnter 4 for insertatindex in doubly linked list\n");
        printf("\nEnter 5 for insertafterindex in doubly linked list\n");
        printf("\nEnter 6 for deleteatfirst in doubly linked list\n");
        printf("\nEnter 7 for deleteatend in doubly linked list\n");
        printf("\nEnter 8 for deleteatindex in doubly linked list\n");
        printf("\nEnter 9 for deleteafterindex in doubly linked list\n");
        printf("\nEnter 10 for reverse the in doubly linked list\n");
        printf("\nEnter 11 for exit\n");
        scanf("%d", &x);
        switch (x)
        {
        case 1:
            traversal();
            break;
        case 2:
            head = insertatfirst();
            printf("\nAfter insert at first\n");
            traversal();
            printf("\n");
            break;
        case 3:
            head = insertatend();
            printf("\nAfter insert at end\n");
            traversal();
            printf("\n");
            break;
        case 4:
            head = insertatindex();
            printf("\nAfter insert at index\n");
            traversal();
            printf("\n");
            break;
        case 5:
            head = insertafterindex();
            printf("\nAfter insert after index\n");
            traversal();
            printf("\n");
            break;
        case 6:
            head = deleteatfirst();
            printf("\nAfter delete at first\n");
            traversal();
            printf("\n");
            break;
        case 7:
            head = deleteatend();
            printf("\nAfter delete at end\n");
            traversal();
            printf("\n");
            break;
        case 8:
            head = deleteatindex();
            printf("\nAfter delete at index\n");
            traversal();
            printf("\n");
            break;
        case 9:
            head = deleteafterindex();
            printf("\nAfter delete after index\n");
            traversal();
            printf("\n");
            break;
        case 10:
            head = reverse();
            printf("\nlist after reverse\n");
            traversal();
            printf("\n");
            break;
        case 11:
            exit(0);
            break;
        default:
            printf("Enter valid input!");
            break;
        }
    }
}