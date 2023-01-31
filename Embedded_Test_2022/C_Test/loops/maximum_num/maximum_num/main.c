#include <stdio.h>
#include <stdlib.h>

int main()
{   /*
    // with if Statement
    int x,y,z,max;
    printf("Please Enter Three Numbers to Get The maximum of Them\n");
    scanf("%i%i%i",&x,&y,&z);
    if(x>y && x>z)
    {
        max=x;
    }
    else if(y>x && y>z)
    {
        max=y;
    }
    else if(z>x && z>y)
    {
        max=z;
    }
    else
    {
     printf("the three numbers are equal");

    }
    printf("The maximum number is: %i\n",max);
    */

    // with switch statement
    int x,y,z,max;
    printf("Please Enter Three Numbers to Get The maximum of Them\n");
    scanf("%i%i%i",&x,&y,&z);

    switch(x>y && x>z)
    {
      case 1:
          printf("number 1 is the maximum");
          break;
      case 0:
          switch(y>x && y>z)
          {
          case 1:
            printf("number 2 is the maximum");
            break;
          case 0:
            switch(z>x && z>y)
            {
            case 1:
                 printf("number 3 is the maximum");
                 break;
            case 0:
                 printf("the three numbers are equal");
                break;


            }
            break;
          }
          break;
    }
    return 0;

}
