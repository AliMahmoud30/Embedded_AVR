#include <stdio.h>
#include <stdlib.h>

int main()
{
    char str[20];
    gets(str);
    int count;

    printf("string length: %i\n",strlen(str));
    return 0;
}
