#include "stdio.h"
#include "stdlib.h"

struct stack
{
    int size;
    int top;
    int *arr;
};
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(struct stack *ptr, int val)
{
    if (isFull(ptr))
    {
        printf("Stack overflow!\n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}
int pop(struct stack *ptr)
{
    int val;
    if (isEmpty(ptr))
    {
        printf("stack underflow!\n");
    }
    else
    {
        val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
int main()
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 5;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));

    printf("before push,empty:%d\n", isEmpty(sp));
    printf("before push,full:%d\n", isFull(sp));

    int x, n,num;
    printf("Enter number where you want to run!");
    scanf("%d",&num);
    while (num--)
    {
        printf("Enter 1 for push!\nEnter 2 for pop!\n");
        scanf("%d", &n);
        if (n == 1)
        {
            printf("Enter push element:");
            scanf("%d", &x);
            push(sp, x);
                    
                    }
        else if (n == 2)
        {
            pop(sp);
        }
    }
}