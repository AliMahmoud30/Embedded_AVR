#include <stdio.h>
#include <stdlib.h>

int main()
{
//    int x=50;
//    int *y,**z;
//    y=&x;
//    z=&y;
//    printf("%i\n",&x);
//    printf("%i\n",y);
//    printf("%i\n",*y);
//
//    printf("%i\n",&y);
//    printf("%i\n",z);
//    printf("%i\n",*z);
//    printf("%i\n",**z);

int **ptr1;
char **ptr2;
short **ptr3;

printf("%i\n",ptr1);
printf("%i\n",ptr2);
printf("%i\n\n",ptr3);

ptr1++;
ptr2++;
ptr3++;

printf("%i\n",ptr1);
printf("%i\n",ptr2);
printf("%i\n\n",ptr3);

    return 0;
}
