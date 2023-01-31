#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i=0;
    char *ptr;
    char y[]={'A','l','I','\0'};
    char x[]={"hello world\n"};

    ptr=x;
    printf("%i\n",sizeof(x));
    printf("%i\n",x[5]);


    printf("%s\n",&x+1);
    printf("%i\n",x);
    printf("%i\n",y);

    while(x[i]!='\0')
    {
        printf("%c",x[i]);
        i++;
    }

    while((*ptr)!='\0')
    {
        printf("%c",*ptr);
        ptr++;
    }
    return 0;
}
