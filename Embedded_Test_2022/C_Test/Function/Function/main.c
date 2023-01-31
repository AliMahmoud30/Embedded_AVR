#include <stdio.h>
#include <stdlib.h>


int sum(int ,int );

int main()
{

    printf("%i\n",sum(5,10));
    printf("%i\n",nam(5,10));

    return 0;
}

int sum(int a,int b)
{

    return (a>b)?a:b;
}
int nam(int a,int b)
{

    return (a>b)?a:b;
}
