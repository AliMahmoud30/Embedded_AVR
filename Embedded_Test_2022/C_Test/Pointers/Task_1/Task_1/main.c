#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned short x=65534;  // 0000 0100 0000 0010

    unsigned short *ptr;
    ptr=&x;
    unsigned char LB,HB;


    LB=x&0xFF;
    HB=x>>8;

    printf("%i\n",LB);
    printf("%i\n",HB);
    if(*((unsigned char*)ptr+0)==LB && *((unsigned char*)ptr+1)==HB)
    {
        printf("Code Block little Endian \n");
    }
    else
    {
        printf("Code Block Big Endian \n");
    }
    printf("first byte of  x= %i\n",*((unsigned char*)ptr));
    printf("Second byte of x= %i\n",*((unsigned char*)ptr+1));

    return 0;
}
