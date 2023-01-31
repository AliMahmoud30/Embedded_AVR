#include <stdio.h>
#include <stdlib.h>

void print_arr(int *ptr,int size);
int main()
{
   // int arr[3]={10,20,30};
    int arr[3];
    scan_arr(arr,3);
    print_arr(arr,3);

    return 0;
}

void scan_arr(int *ptr,int size)
{ int i;
    for(i=0;i<size;i++)
    {
        scanf("%i",ptr+i);
    }
}

void print_arr(int *ptr,int size)
{ int i;
    for(i=0;i<size;i++)
    {
        //printf("%i\n",ptr[i]);
        printf("%i\n",*(ptr+i));
    }
}
