#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x=1026;    // 0000 0100 0000 0010
    int* ptr=&x;
    char *ptr2=&x;

    printf("x=%i\n",*ptr);
    printf("address of x=%i\n",ptr);

    printf("First Byte of x=%i\n",*((unsigned char*)ptr+0));
    printf("First Byte of x=%i\n\n",*((unsigned char*)ptr+1));

    //subscriptor with pointer to char
    printf("First Byte of x=%i\n",ptr2[0]);   //ptr2[0] == *(ptr+0)
    printf("First Byte of x=%i\n\n",ptr2[1]);

    //subscriptor with pointer to int and casting
    printf("First Byte of x=%i\n",((unsigned char*)ptr)[0]);
    printf("First Byte of x=%i\n\n",((unsigned char*)ptr)[1]);

    //get addresses with pointer to int and casting
    printf("address of First Byte of x=%i\n",((unsigned char*)ptr+0));
    printf("address of Second Byte of x=%i\n",((unsigned char*)ptr+1));


    return 0;
}
