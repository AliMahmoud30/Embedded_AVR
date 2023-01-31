#include <stdio.h>
#include <stdlib.h>

#include <string.h>

union data
{
    int i;
    float f;
    char str[20];
};

int main()
{
    union data d1;
    union data d2;

    d1.i=20;
    d2=d1;
    printf("d1.i = %i\n",d1.i);
    printf("d2.i = %i\n",d2.i);

    d1.f=30.65;
     d2=d1;
    printf("d1.f = %0.2f\n",d1.f);
    printf("d2.f = %0.2f\n",d2.f);

    strcpy(d1.str,"c programming");
    d2=d1;
    printf("d1.str = %s\n",d1.str);
    printf("d2.str = %s\n",d2.str);

    printf("d1 size = %i\n",sizeof(d1));
    printf("d2 size = %i\n",sizeof(d2));


    return 0;
}
