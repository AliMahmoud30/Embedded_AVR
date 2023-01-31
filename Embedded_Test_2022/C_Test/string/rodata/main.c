#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *ptr="hello world";
    printf("%s\n",ptr);
    *(ptr+3)='a';    // runtime error
    printf("%s\n",ptr);
    return 0;
}
