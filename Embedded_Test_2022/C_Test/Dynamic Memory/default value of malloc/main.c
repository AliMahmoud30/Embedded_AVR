#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr;
    ptr=(int*)malloc(24);

    printf("*ptr=%i\n",*ptr);  // >> Garbage Value
    return 0;
}
