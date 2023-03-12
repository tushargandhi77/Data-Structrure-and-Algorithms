#include "stdio.h"
#include "stdlib.h"

struct stack
{
    int size;
    int top;
    char *arr;
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

void push(struct stack *ptr, char data)
{
    if (isFull(ptr))
    {
        printf("stack overflow!");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top]=data;
    }
}

char pop(struct stack *ptr)
{
    char data;
    if (isEmpty(ptr))
    {
        printf("stack underflow");
        return -1;
    }
    else
    {
        data = ptr->arr[ptr->top];
        ptr->top--;
        return data;
    }
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
    struct stack *sp;
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char popped_val;

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(sp, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (isEmpty(sp))
            {
                return 0;
            }
            popped_val=pop(sp);
            if (!match(popped_val, exp[i]))
            {
                    return 0;
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
    char *exp = ")4(";
    if (parenthesismatch(exp))
    {
        printf("matching succesfull\n");
    }
    else
    {
        printf("matching unsuccesfull\n");
    }
}