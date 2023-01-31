#include <stdio.h>
#include <stdlib.h>


#define x 10
int main()
{
    #if (x==10)
    printf("x=10\n");

    #else
    printf("x=100\n");

    #endif

    return 0;
}
