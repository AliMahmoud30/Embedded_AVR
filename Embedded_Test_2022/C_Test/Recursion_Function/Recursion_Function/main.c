#include <stdio.h>
#include <stdlib.h>

unsigned long long fact(unsigned int x)
{
    if(x<=1)
    {
        return 1;
    }
    else
    {
        return x*fact(x-1);
    }
}

int main()
{
    unsigned int num;
    scanf("%u",&num);
    if(num>=0)
    {
        printf("factorial number %u :%llu \n",num,fact(num));
    }
    else
    {
       printf("please enter positive number");
    }


    return 0;
}

