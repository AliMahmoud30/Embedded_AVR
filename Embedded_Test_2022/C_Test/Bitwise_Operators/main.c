#include <stdio.h>
#include <stdlib.h>

int main()
{
   unsigned char x=8;
   x>>=2;
   printf("x=%d\n",x); // 2
   x<<=1;
   printf("x=%d\n",x); // 4
   x|=(1<<1);  // Set bit
   printf("x=%d\n",x);  // 6
   x&=(~(1<<2));  // clear bit
   printf("x=%d\n",x);  // 2
   x^=(1<<3);  // Toggle bit
   printf("x=%d\n",x);  // 10
   x=1&(x>>3);  // Read bit
   printf("x=%d\n",x);  // 1 or 0


}
