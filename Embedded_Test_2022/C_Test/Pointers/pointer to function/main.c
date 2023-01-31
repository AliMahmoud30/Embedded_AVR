#include <stdio.h>
#include <stdlib.h>

int sum(int a,int b);

int main()
{
    int z;
    //Pointer to Function Declaration
    int (*ptr)(int,int);
    ptr=sum;
    //z=sum(5,8); //call function
    z=ptr(5,6);  //call function with pointer to function

    printf("%i\n",z);
    return 0;
}
int sum(int a,int b)
{
    return a+b;
}
