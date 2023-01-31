#include <stdio.h>
#include <stdlib.h>

#define ptr  int*
typedef int* ptr2;



int main()
{
    static int i,j,u,d;

    ptr2 x,y;  //
    ptr w,z;   // int* x ,y
    x=&i;
    y=&j;
    w=&u;
    z=&d;
    printf("%i\n",*y);
    printf("%i\n",*y);
    printf("%i\n",*w);
    printf("%i\n",*z);
    return 0;
}
