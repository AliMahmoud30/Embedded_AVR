#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num=-1;
    int i;

    for(i=31;i>=0;i--)
    {
         printf("%i",(num&(1u<<i))>>i);

    }

    return 0;
}
