#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned int x=20;
    unsigned int *p;

    p=&x;

    printf("x=%p\n",&x);
    printf("x=%p\n",p);
    printf("x=%u\n",*&x);
    printf("p=%p\n",*&p);
    printf("p=%p\n",&*p);
    printf("x=%u\n",*p);
    return 0;
}
