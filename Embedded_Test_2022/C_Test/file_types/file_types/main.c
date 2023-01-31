#include <stdio.h>
#include <stdlib.h>

#include "calculator.h"
//#include "calculator.c"

unsigned char num2;

void address(void)
{

    unsigned char num1;

    unsigned char num3;
    printf("%i\n",&num1);
    printf("%i\n",&num2);
    printf("%i\n",&num3);

}

int main()
{
    /*
    int x;
    x=add(5,2);
    printf("Hello world!\n%i\n",x);
    x=sub(5,2);
    printf("Hello world!\n%i\n",x);


      */
      address();

typedef int arr[5];
arr iarr={1,2,3,4,5};
int i;
for(i=0;i<4;i++)
{
    printf("%d",iarr[i]);
}

    return 0;
}


