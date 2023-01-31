#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr,n;
    int sum=0;
    unsigned int i;
    printf("enter number of elements\n");
    scanf("%i",&n);
    ptr=(int*)calloc(n,sizeof(int));

    if(ptr==0)
    {
        printf("Memory not allocated\n");
    }
    else
    {
        printf("enter array elements\n");
        for(i=0;i<n;i++)
        {
            scanf("%i",ptr+i);
            sum+=(*(ptr+i));
            //printf("OK\n");
        }
        printf("Sum=%u\n",sum);
    }


    printf("ptr=%i\n",ptr);
    printf("*ptr=%i\n",*ptr);
    printf("ptr+1=%i\n",ptr+1);
    printf("*(ptr+1)=%i\n",*(ptr+1));

    free(ptr);

    printf("ptr=%i\n",ptr);
    printf("*ptr=%i\n",*ptr);
    printf("ptr+1=%i\n",ptr+1);
    printf("*(ptr+1)=%i\n",*(ptr+1));



    return 0;
}
