
/* C Code to Swap 4-bits with the other 4-bits in byte */

#include <stdio.h>
#include <stdlib.h>


int main(void)
{
  unsigned char x=0b10010011; //147
  unsigned char y=0b00000000; // 0
  unsigned char bit1,bit2;


  printf("x=%d\n",x);
  printf("y=%d\n",y);

  printf("\n\nafter swap\n\n");


  for(int i=0; i<4; i++)
  {
      bit1 = ((x>>i)&1); // get bit from x
      bit2 = ((y>>i)&1); // get bit from y

      // set bit in y with bit1
      if(bit1 == 1)
      {
          y|=(1<<i);
      }
      else
      {
         y&=~(1<<i);
      }

       // set bit in x with bit2
      if(bit2 == 1)
      {
         x|=(1<<i);
      }
      else
      {
          x&=~(1<<i);
      }

  }


  printf("x=%d\n",x);
  printf("y=%d\n",y);

	return 0;

}





