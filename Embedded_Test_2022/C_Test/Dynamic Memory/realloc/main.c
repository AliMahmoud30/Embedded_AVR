#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr,*ptr2,n,n2;
    int sum=0;
    unsigned int i;
    printf("enter number of elements\n");
    scanf("%i",&n);
    ptr=(int*)malloc(n*sizeof(int));

    if(ptr==0)
    {
        printf("Memory not allocated\n");
    }
    else
    {
        printf("enter array elements:\n");
//        for(i=0;i<n;i++)
//        {
//            scanf("%i",ptr+i);
//            sum+=(*(ptr+i));
//            //printf("OK\n");
//        }
//        printf("Sum=%u\n",sum);
    }

    sum=0;

    printf("enter the new size:\n");
    scanf("%i",&n2);

    ptr2=realloc(ptr,n*sizeof(int));
     if(ptr2==0)
    {
        printf("Memory not allocated\n");
    }
    else
    {

        printf("ptr2=%i\n",ptr2);
//        printf("elements of new array:\n");
//
//            for(i=0;i<n2;i++)
//            {
//                //scanf("%i",ptr2+i);
//                sum+=(*(ptr2+i));
//                printf("%i\n",*(ptr2+i));
//            }
//            printf("Sum=%u\n",sum);
    }


    return 0;
}
