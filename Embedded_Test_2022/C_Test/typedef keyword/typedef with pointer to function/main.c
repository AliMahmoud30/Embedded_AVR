#include <stdio.h>
#include <stdlib.h>

typedef int (*ptr_func)(int,int);
int sum(int , int);

int main()
{
    int z;

    ptr_func  ptr1=sum;
    z=ptr1(5,6);
    printf("%i\n",z);
    return 0;
}
int sum(int x, int y)
{
    return x+y;
}
