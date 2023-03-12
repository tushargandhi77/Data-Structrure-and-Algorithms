#include "stdio.h"
#include "stdlib.h"

struct stack
{
    int size;
    int top;
    char *arr;
};


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
        printf("stack underflow\n");
        return -1;
    }
    else
    {
        val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int matchfunc(char a, char b)
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

int parenthesismatching(char *exp)
{

    struct stack *sp;
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char poped_val;

    for (int i = 0; exp[i] != '\0'; i++)
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
            poped_val = pop(sp);
            if (!matchfunc(poped_val, exp[i]))
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
    char *exp = ")(";
    if (parenthesismatching(exp))
    {
        printf("matching succesfull\n");
    }
    else
    {
        printf("matching unsuccesfull\n");
    }
    return 0;
}