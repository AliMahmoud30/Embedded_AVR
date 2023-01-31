#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[3]={10,20,30};
    int (*ptr)[3];
    ptr=arr;
    printf("arr=%i\n",arr);
    printf("ptr=%i\n",ptr);
    printf("arr+1=%i\n",arr+1);
    printf("ptr+1=%i\n",ptr+1);
    printf("&arr+1=%i\n",&arr+1);
    printf("*ptr+1=%i\n",*ptr+1);
    printf("*&arr+1=%i\n",*&arr+1); //>>
    printf("**ptr=%i\n",**ptr); //>>
    printf("*(*ptr+1)=%i\n",*(*ptr+1)); //>>
    printf("*(*ptr+2)=%i\n",*(*ptr+2)); //>>
    ptr++;
    printf("ptr=%i\n",ptr); //>>
    printf("*ptr=%i\n",*ptr); //>>
    printf("*(*ptr+1)=%i\n",*(*ptr+1)); //>>
    ptr=arr;
    ptr=(*ptr)+1;
    //(*ptr)++;  // error
    printf("ptr=%i\n",ptr); //>>
    return 0;
}
