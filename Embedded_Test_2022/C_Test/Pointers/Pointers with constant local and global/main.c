#include <stdio.h>
#include <stdlib.h>

const int x=50;

int main()
{


    int *ptr=&x;

    printf("x=%i\n",x);
    *ptr=100;
    printf("x=%i\n",x);
    return 0;
}
