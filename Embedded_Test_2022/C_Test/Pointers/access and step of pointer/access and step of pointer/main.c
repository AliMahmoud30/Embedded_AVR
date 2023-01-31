#include <stdio.h>
#include <stdlib.h>

int main()
{
    //first example
    /*
    int num=258;
    char *ptr;
    ptr=&num;

    printf("first byte of num: %i\n",*ptr);
    ptr++;
    printf("Second byte of num: %i\n",*ptr);
    */

    //Second example
    int num=258;
    int *ptr1;
    char *ptr2;

    ptr1=&num;
    ptr2=&num;

    printf("%i\n",*ptr1);
    printf("%i\n",*ptr2);
    *ptr2=4;
    printf("%i\n",*ptr1);
    printf("%i\n",*ptr2);


    return 0;
}
