#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x=1026;
    void* ptr;
    ptr=&x;

    printf("%p\n",&x);
    printf("%p\n",ptr);
    printf("%i\n",*(char*)ptr);

    ptr++;
    printf("%p\n",ptr);
    printf("%i\n",*(char*)ptr);

    return 0;
}
