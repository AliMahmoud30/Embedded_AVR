#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr;
    ptr=(int*)calloc(4,6);

    printf("*ptr=%i\n",*ptr);  // >> Default Value is Zero
    return 0;
}
