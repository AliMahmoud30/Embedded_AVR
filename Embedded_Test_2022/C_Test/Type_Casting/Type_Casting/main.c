#include <stdio.h>
#include <stdlib.h>

int main()
{
/*
   unsigned long x=258;
   unsigned char y;
   unsigned char z;

   y=x;     //implicit casting
   printf("y=%i\n",y);
   printf("x=%i\n",x);
   z=(unsigned char)x;    //explicit casting
   printf("z=%i\n",z);
   printf("x=%i\n",x);
*/
/*
//integer promotion
 signed char x=-128;  // 1000000
 signed int y;

 y=x<<2;
 // x >> promotion to int
 //00000000 00000000 00000000 10000000  >> 128
 //11111111 11111111 11111111 10000000  >> -128

 //shift lift with tow
 //00000000 00000000 00000010 00000000  >> 512
 //11111111 11111111 11111110 00000000  >> -512
 printf("y=%i",y);


*/

/*
signed long x=-1;
//11111111 111111111 11111111 11111111  (-1)1 promotion to unsigned int
unsigned long y=5;

printf("x=%i\n",(unsigned int)x);

if(x<y)
{

    printf("OK\n");
}
else
{
    printf("not Ok\n");
}
*/

signed int x=-2;

if(((x&(1u<<31))>>31)==1)  // u to casting to unsigned int
{

    printf("MSB = 1");

}
else
    {
        printf("MSB = 0");
    }

    return 0;
}
