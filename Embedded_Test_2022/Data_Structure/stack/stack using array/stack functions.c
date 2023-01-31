#include <stdio.h>
#define SIZE 3
int top=-1;
int stack[SIZE];
int is_stack_full(void)
{
    int x;
    if(top>=SIZE-1)
    {
        x=1;
    }
    else
    {
        x=0;
    }
    return x;
}

void push(int x)
{
    top++;
    stack[top]=x;
}

int is_stack_empty(void)
{
    int x;
    if(top<=-1)
    {
        x=1;
    }
    else
    {
        x=0;
    }
    return x;
}

int pop(void)
{
    int x;
    x=stack[top];
    top--;
    return x;
}

void display_stack_elements(void)
{
    int i;
    for(i=0;i<=top;i++)
    {
        printf("%i\n",stack[i]);
    }
}

int return_top_value(void)
{
    return stack[top];
}

int number_of_stack_elements(void)
{
    return top+1;
}

