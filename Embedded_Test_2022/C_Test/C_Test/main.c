#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define K 1024

int main(void)
{
    int* ptr1,n,sum=0;
    int* ptr2;

    ptr1=(int*)malloc(3*K);
    printf("ptr=%i\n",ptr1);
    if(ptr1==0)
    {
        printf("Memory not Allocated!\n");
    }
    else
    {
        printf("Memory Allocated!\n");
    }
    ptr2=(int*)malloc(4*K);
    if(ptr2==0)
    {
        printf("Memory not Allocated!\n");
    }
    else
    {
        printf("Memory Allocated!\n");
    }
    free(ptr1);
    ptr1=(int*)malloc(4*K);
    if(ptr1==0)
    {
        printf("Memory not Allocated!\n");
    }
    else
    {
        printf("Memory Allocated!\n");
    }
 return 0;
}
