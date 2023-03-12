#include "stdio.h"
#include "stdlib.h"

struct stack
{
    int top;
    int size;
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
    char val = -1;
    if (isempty(ptr))
    {
        printf("stack underflow");
    }
    else
    {
        val = ptr->arr[ptr->top];
        ptr->top--;
    }
    return val;
}

int match(char a, char b)
{
    if (a == '(' && b == ')')
    {
        return 1;
    }
    if (a == '{' && b == '}')
    {
        return 1;
    }
    if (a == '[' && b == ']')
    {
        return 1;
    }
    return 0;
}

int parenthesismatch(char *exp)
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    int i;
    for (i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(sp, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (isempty(sp))
            {
                return 0;
            }
            else if (!match(pop(sp), exp[i]))
            {
                return 0;
            }
        }
    }
    if (isempty(sp))
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
    char *exp = "([{(24+32)})";
    if (parenthesismatch(exp))
    {
        printf("match succesfull\n");
    }
    else
    {
        printf("match unsuccesfull\n");
    }
}