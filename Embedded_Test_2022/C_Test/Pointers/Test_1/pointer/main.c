#include <stdio.h>
#include <stdlib.h>

int main()
{


    //int x=50,*y=&x;
    int x=50;
    static int *y,*ptr;
    y=&x;
    *y=*y+5;
    ptr=y;
    printf("%i\n",&x);
    printf("%i\n",y);
    printf("%i\n",ptr);
    printf("%i\n",&ptr);
    printf("%i\n",x);
    printf("%i\n",*y);
    printf("%i\n",*ptr);

    return 0;
}
