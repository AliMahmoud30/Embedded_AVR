#include <stdio.h>
#include <stdlib.h>
#include "stack functions.h"
int main()
{
    int choice,popped_value,pushed_value;
    while(1)
    {
        printf("please enter your choice:");
        scanf("%i",&choice);
        printf("\n\n");
        switch(choice)
        {
            case 1:
            if(is_stack_full()==1)
            {
                printf("the stack is full\n");
            }
            else
            {
                printf("Enter a value to be pushed:");
                scanf("%i",&pushed_value);
                push(pushed_value);
            }
            break;
            case 2:
            if(is_stack_empty()==1)
            {
                printf("the stack is empty\n");
            }
            else
            {
                popped_value=pop();
                printf("the popped value is %i\n",popped_value);
            }
            break;
            case 3:
            if(is_stack_empty()==1)
            {
                printf("the stack is empty\n");
            }
            else
            {
                display_stack_elements();
            }
            break;
            case 4:
            if(is_stack_empty()==1)
            {
                printf("stack is empty\n");
            }
            else
            {
            printf("the top value=%i\n", return_top_value());
            }
            break;
            case 5:
            if(is_stack_empty()==1)
            {
                printf("stack is empty\n");
            }
            else
            {
           printf("number_of_stack_elements=%i\n",number_of_stack_elements());
            }
            break;
            case 6:
            exit(0);
            break;
            default:
            printf("wrong choice\n");
        }
        printf("\n");
    }
    return 0;
}


