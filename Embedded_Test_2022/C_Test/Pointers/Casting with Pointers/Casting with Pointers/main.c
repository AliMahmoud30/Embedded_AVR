#include <stdio.h>
#include <stdlib.h>

int main()
{
//    unsigned short x=1026;
//    unsigned short *ptr;
//    ptr=&x;
//    *(unsigned char*)ptr=4;
//    printf("%hu\n",*ptr);
//    printf("%hu\n",*(unsigned char *)ptr);

      unsigned short x=257;
      unsigned char* a;
      char* b;
      a=&x;
      b=&x;

      printf("%i\n%i\n",*(unsigned short*)a,*(unsigned char*)b);
      printf("%i\n%i\n",*a,*b);

    return 0;
}
