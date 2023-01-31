#include <stdio.h>
#include <stdlib.h>

int main()
{
  unsigned char x;
  scanf("%c",&x);

  switch(x)
      {
      case 'a' ... 'z':
      case '+':
        printf("Lower Case\n");
        break;
      case 'A' ... 'Z':
        printf("Upper Case\n");
        break;
      default:
        printf("default case\n");

      }



    return 0;
}
