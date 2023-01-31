#include <stdio.h>
#include <stdlib.h>


int fib(int num)
{
    if(num==0 || num==1)
    {
        return num;
    }

    else
    {
        return (fib(num-1)+fib(num-2));
    }


}



int main()
{
     int num;
    scanf("%i",&num);
    if(num>0)
    {
        printf("Fibonacci Series for number %u :%i \n",num,fib(num));
    }
    else
    {
       printf("please enter positive number");
    }


    return 0;
}
