#include <stdio.h>
#include <stdlib.h>

int main()
{
    char str[20];
    gets(str);
    int count=0;

    while(*(str+count)!='\0') // str[count]
    {
        count++;
    }
    printf("string length: %i\n",count);
    return 0;
}
