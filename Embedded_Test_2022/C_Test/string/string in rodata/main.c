#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *ptr="hello world";
    //char ptr[]="hello world";

    printf("OK\n");
    *(ptr+6)='a';  // >> runtime error
    printf("Not OK\n");
    printf("%s\n",ptr);
        return 0;
}
