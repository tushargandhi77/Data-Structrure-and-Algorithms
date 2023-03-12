#include "stdio.h"
#include "stdlib.h"

struct stack
{
    int top;
    int size;
    int *a;
};

void initstack(struct stack *sp, int msize)
{
    sp->top = -1;
    sp->size = msize;
    sp->a = (int *)malloc(msize * sizeof(int));
}

int isEmpty(struct stack *sp)
{
    if (sp->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *sp)
{
    if (sp->top == sp->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *sp, int val)
{
    if (isFull(sp))
    {
        printf("\nStack is full\n");
    }
    else
    {
        sp->top++;
        sp->a[sp->top] = val;
    }
}

int pop(struct stack *sp)
{
    int val = -1000;
    if (isEmpty(sp))
    {
        printf("\nStack is empty\n");
    }
    else
    {
        val = sp->a[sp->top];
        sp->top--;
    }
    return val;
}

void display(struct stack *sp)
{
    printf("\nThe stack Element:\n");
    for (int i = 0; i <= sp->top; i++)
    {
        printf("%d ", sp->a[i]);
    }
}
int main()
{
    struct stack *p;
    p = (struct stack *)malloc(sizeof(struct stack));
    int x, n, e;
    printf("\nEnter the size of stack:\n");
    scanf("%d", &n);
    initstack(p, n);
    while (1)
    {
        printf("\n\nEnter 1 for push\n");
        printf("\nEnter 2 for pop\n");
        printf("\nEnter 3 for display\n");
        printf("\nEnter 4 for exit\n");
        scanf("%d", &x);
        switch (x)
        {
        case 1:
            printf("\nEnter the element want to push\n");
            scanf("%d", &e);
            push(p, e);
            break;
        case 2:
            printf("\nThe pop element is %d\n", pop(p));
            break;
        case 3:
            display(p);
            break;
        case 4:
            exit(0);
            break;
        default:
            break;
        }
    }
}