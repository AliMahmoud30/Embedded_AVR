#include <stdio.h>
#include <stdlib.h>

int main()
{
    //int *ptr=100;  //>>  Runtime Error
    int x=50;
    //int *ptr=6356235;
    int *ptr=(int*)6356235;
    *ptr=1;
    printf("adress of x=%i\n",&x);
    printf("%i\n",ptr);
    printf("%i\n",*ptr);
    return 0;
}
