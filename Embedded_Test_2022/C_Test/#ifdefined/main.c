#include <stdio.h>
#include <stdlib.h>

#define x
#define y

int main()
{
     #if (defined x) && (defined y)
    printf("x\n");
     #elif defined y
    printf("y\n");
     #elif defined z
    printf("z\n");
     #elif defined w
    printf("w\n");
     #else

     #endif

    return 0;
}
