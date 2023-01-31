#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr[5];
    int x=20, y=30, z=50;

    ptr[0]=&x;
    ptr[1]=&y;
    ptr[2]=&z;

    printf("ptr[0]=%i\n",ptr);
    printf("ptr[0]=%i\n",*ptr);
    printf("ptr[0]=%i\n",ptr[0]);
    printf("ptr[1]=%i\n",ptr[1]);
    printf("ptr[2]=%i\n\n",ptr[2]);

    printf("*ptr[0]=%i\n",*ptr[0]);     //ptr[0] >> *(ptr+0) >>*(*(ptr+0)) >> value
    printf("*ptr[1]=%i\n",*ptr[1]);
    printf("*ptr[2]=%i\n\n",*ptr[2]);

    printf("*ptr[0]=%i\n",*(*(ptr)));
    printf("*ptr[1]=%i\n",*(*(ptr+1)));
    printf("*ptr[2]=%i\n\n",*(*(ptr+2)));

    printf("ptr=%i\n\n",ptr);
    printf("ptr+1=%i\n\n",ptr+1);
    printf("&ptr=%i\n\n",&ptr);
    printf("&ptr+1=%i\n\n",&ptr+1);
    printf("*&ptr+1=%i\n\n",*&ptr+1);



    return 0;
}
