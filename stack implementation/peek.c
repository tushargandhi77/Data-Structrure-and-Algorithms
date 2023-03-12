#include "stdio.h"
#include "stdlib.h"
struct stack
{
    int size;
    int top;
    int *arr;
};
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
void push(struct stack *ptr, int val)
{
    if (isFull(ptr))
    {
        printf("stack overflow!\n");
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
        printf("Stack underflow!\n");
    }
    else
    {
        val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
int peek(struct stack *ptr, int i)
{
    if (ptr->top - i + 1 < 0)
    {
        printf("not Possible!");
        return -1;
    }
    else
    {
        return ptr->arr[ptr->top - i + 1];
    }
}
int stacktop(struct stack *ptr)
{
    return ptr->arr[ptr->top];
}
int stackbottom(struct stack *ptr)
{
    return ptr->arr[0];
}
int main()
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 5;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));
    int n, x, i, num;
    printf("Enter number where you want to run!");
    scanf("%d", &num);
    while (num--)
    {
        printf("Enter 1 for push\nEnter 2 for pop\n");
        scanf("%d", &n);
        if (n == 1)
        {
            printf("Enter push element!");
            scanf("%d", &x);
            push(sp, x);
        }
        else if (n == 2)
        {
            printf("The poped element is %d\n", pop(sp));
        }
    }
    for (i = 1; i <= sp->size; i++)
    {
        printf("The element of stack at %d pos is %d\n", i, peek(sp, i));
    }
    printf("The top most element is :%d\n", stacktop(sp));
    printf("The bottom most element is :%d\n", stackbottom(sp));
}
