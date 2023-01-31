#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned int num=4294967295;
    int i,counter=0;

    for(i=0;i<sizeof(num)*8;i++)
    {
        if((num>>i)&1)
        {
            counter++;
        }
    }

    printf("number of ones : %i\n",counter);
    printf("number of ones : %i\n",sizeof(num)*8);
    return 0;
}
