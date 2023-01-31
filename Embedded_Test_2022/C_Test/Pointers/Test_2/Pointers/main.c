#include "stdio.h"
#include "stdlib.h"

int main()
{
    int x=258;

    int* a;
    unsigned char* b;
    char* c;
    a=b=c=&x;

    printf("%i\n",&x);
    printf("%i\n",a);
    printf("%i\n",b);
    printf("%i\n",x);
    printf("%i\n",*a);
    printf("%i\n",*(b+1));
    printf("%i\n",*(unsigned char*)a);
    printf("%i\n",*c);
    printf("%i\n",*(unsigned char*)c);
    c++;
    printf("%i\n",*(unsigned char*)c);


    return 0;
}
