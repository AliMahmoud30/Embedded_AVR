#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned short x=3;  // 0000 0000 0000 0011

    unsigned char *ptr;
    ptr=&x;


    if((*ptr)==3)
    //if(*((unsigned char*)ptr+0)==3)
    {
        printf("Code Block little Endian \n");
    }
    else
    {
        printf("Code Block Big Endian \n");
    }
    printf("first byte of  x= %i\n",*ptr);
    printf("Second byte of x= %i\n",*(ptr+1));

    return 0;
}
