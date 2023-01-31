#include <stdio.h>
#include <stdlib.h>

//#define x 5

int main()
{

    #ifndef x
     printf("Hello world!\n");

    #else
    printf("OK\n");

    #endif // x
    return 0;
}
