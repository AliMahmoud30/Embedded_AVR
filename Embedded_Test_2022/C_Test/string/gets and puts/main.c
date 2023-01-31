#include <stdio.h>
#include <stdlib.h>

int main()
{
   char str[20];
   int x;

   scanf("%i",&x);
   fflush(stdin);
   gets(str);
   puts(str);
   printf("%i",str[0]);
    return 0;
}
