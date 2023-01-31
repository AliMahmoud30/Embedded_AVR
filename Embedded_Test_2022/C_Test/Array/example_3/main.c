#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[3],i;


    for(i=0;i<3;i++)
    {
        //scanf("%i",&arr[i]);
        scanf("%i",arr+i);
    }

    for(i=0;i<3;i++)
    {
       printf("%i\n",arr[i]);
    }

    return 0;
}
