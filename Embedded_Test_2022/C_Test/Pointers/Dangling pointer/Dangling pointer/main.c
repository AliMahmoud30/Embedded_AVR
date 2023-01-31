#include <stdio.h>
#include <stdlib.h>

int* func(void);

int main()
{
    int * ptr;
    ptr=func();

    printf("%i\n",ptr);
    printf("%i\n",*ptr);

    return 0;
}


int* func(void)
{
    //static int x=10;    //NO error >> x stored in .data segment
    int x=10;         // runtime error
    printf("%i\n",&x);
    return &x;
}
