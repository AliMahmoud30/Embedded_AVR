#include <stdio.h>
#include <stdlib.h>
 // int y;
int main()
{   //int y;    //when declare variable y here, the address of y
    //after address of. ptr++ point to variable y hahahahah

    int x=5;
    int *ptr;
    ptr=&x;
    int y;

    printf("address of x=%p\n",&x);
    printf("address of y=%p\n",&y);
    printf("pointer to  :%p\n",ptr);
    printf("x=%i\n",*ptr);
    printf("x=%i\n",x);
    printf("y=%i\n\n",y);
    //--------------------------------
    y=*ptr++;

    printf("address of x=%p\n",&x);
    printf("pointer to  :%p\n",ptr);
    printf("pointer Dereference=%i\n",*ptr); // Garbage Value
    printf("x=%i\n",x);    //5
    printf("y=%i\n\n",y);    // Garbage Value
    //--------------------------------

    ptr=&x;
    y=*++ptr;
    printf("address of x=%p\n",&x);
    printf("pointer to  :%p\n",ptr);
    printf("pointer Dereference=%i\n",*ptr); // Garbage Value
    printf("x=%i\n",x);    //5
    printf("y=%i\n\n",y);    // Garbage Value
    //--------------------------------

    ptr=&x;
    y=(*ptr)++;
    printf("address of x=%p\n",&x);
    printf("pointer to  :%p\n",ptr);
    printf("pointer Dereference=%i\n",*ptr); // Garbage Value
    printf("x=%i\n",x);    //5
    printf("y=%i\n\n",y);    // Garbage Value
    //--------------------------------


    ptr=&x;
    y=++(*ptr);
    printf("address of x=%p\n",&x);
    printf("pointer to  :%p\n",ptr);
    printf("pointer Dereference=%i\n",*ptr); // Garbage Value
    printf("x=%i\n",x);    //5
    printf("y=%i\n\n",y);    // Garbage Value
    //--------------------------------


    return 0;
}
