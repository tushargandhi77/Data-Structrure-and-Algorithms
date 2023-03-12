#include "stdio.h"
#include "stdlib.h"

struct stack
{
    int size;
    int top;
    char *arr;
};

int isfull(struct stack *ptr)
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

int isempty(struct stack *ptr)
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

void push(struct stack *ptr, char val)
{
    if (isfull(ptr))
    {
        printf("stackoverflow\n");
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
    if (isempty(ptr))
    {
        printf("stackunderflow\n");
        return -1;
    }
    else
    {
        val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int parenthesismatch(char *exp)
{
    struct stack *sp;
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            push(sp, '(');
        }
        else if (exp[i] == ')')
        {
            if (isempty(sp))
            {
                return 0;
            }
            else
            {
                pop(sp);
            }
        }
    }
        if (isempty(sp))
        {
            return 1;
        }
        else
            return 0;
        {
        }
}

int main()
{
    char *exp = ")(23+32))";
    if (parenthesismatch(exp))
    {
        printf("maching succesfull\n");
    }
    else
    {
        printf("maching not succesfull\n");
    }
    return 0;
}