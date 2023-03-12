#include "stdio.h"
#include "stdlib.h"

struct node
{
    int data;
    struct node *next;
};

struct node *f = NULL;
struct node *r = NULL;

int isfull()
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    if (n == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isempty()
{
    if (f == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue()
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    int d;
    printf("Enter the data want to enqueue:");
    scanf("%d", &d);
    if (isfull())
    {
        printf("Queue overflow!!");
    }
    else
    {
        n->data = d;
        n->next = NULL;
        if (f == NULL)
        {
            f = r = n;
        }
        else
        {
            r->next = n;
            r = n;
        }
    }
}

int dequeue()
{
    struct node *ptr = f;
    int val = -1;
    if (isempty())
    {
        printf("Queue underflow!");
    }
    else
    {
        val = f->data;
        f = f->next;
    }
    free(ptr);
    return val;
}


void display(struct node *ptr){
    printf("\nThe queue :\n");
    while(ptr!=NULL){
        printf(" %d ",ptr->data);
        ptr = ptr->next;
    }
}


int main()
{
    
    int y,z;
    while (1)
    {
        printf("\nEnter 1 for enqueue\nEnter 2 for dequeue\nEnter 3 for display\nEnter 4 for exit\n");
        scanf("%d", &y);
        switch (y)
        {
        case 1:
            enqueue(z);
            break;
        case 2:
            printf("The dequeue element:%d\n", dequeue());
            break;
        case 3:
            display(f);
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Enter valid input\n");
            break;
        }
    }
}