#include <stdio.h>
#include <stdlib.h>

#define x 6
int main()
{
    /*
    int x=5;
    if(x==6)
    {

    #error khaly balk feh error
    }
    else
    {
    printf("Hello world!\n");

    }
*/

#if (x==5)
    printf("Hello world!\n");
#else
     //#warning khaly balk feh error
     #error khaly balk feh error
#endif
printf("ok");
    return 0;
}
