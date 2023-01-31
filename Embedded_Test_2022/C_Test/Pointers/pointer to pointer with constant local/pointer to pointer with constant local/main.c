#include <stdio.h>
#include <stdlib.h>

int main()
{
//    int x=50;
//    int* const ptr1=&x;
//    int** ptr2=&ptr1;
//
//    printf("%i\n",ptr1);
//    //ptr1++;  // syntax error
//    (*ptr2)++;
//    printf("%i\n",ptr1);

    int x=50;
    int ptr1=&x;

    int *const *ptr2;
    ptr2=&ptr1;

    printf("%i\n",ptr1);
    printf("%i\n",*ptr2);
    printf("%i\n",**ptr2);

    (**ptr2)++;
    printf("%i\n",**ptr2);

    (*ptr2)++;
    printf("%i\n",**ptr2);
    printf("%i\n",ptr1);


//
//    int ptr1;
//    //int *const *ptr2;
//    const int * *ptr2;
//    ptr2=&ptr1;
//
//    printf("%i\n",&ptr1);
//    printf("%i\n",ptr1);
//    printf("%i\n",*ptr2);
//    (*ptr2)++;
//    printf("%i\n",ptr1);
//    //(**ptr2)=50;
    return 0;
}
