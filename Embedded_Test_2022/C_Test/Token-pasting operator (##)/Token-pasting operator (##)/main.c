#include <stdio.h>
#include <stdlib.h>

#define concat(a,b)  a##b
int main()
{
    int xy=30;
    printf("%d\n",concat(x,y));

    return 0;
}
