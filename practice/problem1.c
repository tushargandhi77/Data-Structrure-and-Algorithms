#include "stdio.h"
#include "stdlib.h"

struct stack
{
    int top;
    int size;
    char *arr;
};

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    return 0;
}

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    return 0;
}

void push(struct stack *ptr, char val)
{
    if (isFull(ptr))
    {
        printf("stack overflow\n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

char pop(struct stack *ptr)
{
    char val;
    if (isEmpty(ptr))
    {
        printf("stack underflow\n");
        return -1;
    }
    else
    {
        val = ptr->arr[ptr->top];
        ptr->top--;
    }
    return val;
}

int parenthesismatch(char *exp)
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->top = -1;
    sp->size = 100;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            push(sp, '(');
        }
        else if (exp[i] == ')')
        {
            if (isEmpty(sp))
            {
                return 0;
            }
            else
            {
                pop(sp);
            }
        }
    }
    if (isEmpty(sp))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    char *exp = ")32+32(";
    if (parenthesismatch(exp))
    {
        printf("match succesfull\n");
    }
    else
    {
        printf("Match unsuccessull\n");
    }
}