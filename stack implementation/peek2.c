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
        printf("not possible\n");
    }
    else
    {
        return ptr->arr[ptr->top - i + 1];
    }
}
int main()
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 5;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));
    int n, num, x;
    printf("Empty:%d\n", isEmpty(sp));
    printf("Full:%d\n", isFull(sp));
    printf("Enter number for run!");
    scanf("%d", &num);
    while (num--)
    {
        printf("Enter 1 for push\nEnter 2 for pop\n");
        scanf("%d", &n);
        if (n == 1)
        {
            printf("Enter pushing element!");
            scanf("%d", &x);
            push(sp, x);
        }
        else if (n == 2)
        {
            printf("The pop element:%d\n", pop(sp));
        }
    }
    for (int i = 1; i <= sp->size; i++)
    {
        printf("Elements are:%d at position %d\n", i, peek(sp, i));
    }
}