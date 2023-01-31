#include <stdio.h>
#include <stdlib.h>

int sum(int x, int y);
int multiply(int x, int y);

int main()
{
    int z;
    int (*ptr[3])(int,int);

    //ptr[0]=sum;
    //ptr[1]=multiply;
    *ptr=sum;
    *(ptr+1)=multiply;

    z=ptr[0](5,6);
    printf("z=%i\n\n",z);

    z=ptr[1](5,6);
    printf("z=%i\n\n",z);

    return 0;
}


int sum(int x, int y)
{
    return x+y;
}

int multiply(int x, int y)
{
    return x*y;
}
