#include <stdio.h>
#include <stdlib.h>

int main()
{
   int x;
   char flag=0;
   scanf("%i",&x);
   if(x>0)
   {

   if((x%2)==0)
   {
       printf("number is Even\n");
   }
   else
   {
       printf("number is Odd\n");
   }

   if((x==1)||x==0)
   {
        printf("number is not Prime\n");
   }
   else
   {
       for(int i=2;i<=x/2;i++)
       {
           if((x%i)==0)
           {
             flag=1;
             break;
           }

       }
       if(flag==1)
       {
           printf("number is not Prime\n");

       }
       else
       {
           printf("number is Prime\n");

       }
   }
   }
   else
   {

    printf("number can't be negative number\n");

    }

    return 0;
}
