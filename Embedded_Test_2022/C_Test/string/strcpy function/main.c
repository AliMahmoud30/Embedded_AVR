#include <stdio.h>
#include <stdlib.h>

#include <string.h>

int main()
{
    char str[20];
    char str_copy[20];

    gets(str);
    puts(str);
    strcpy(str_copy,str);

    strcpy(str,"hello");
    printf("%s\n",str_copy);
    printf("%s\n",str);


    printf("%s\n",strcpy("hello",str));  //runtime error
    printf("%s\n",str);
    return 0;
}
