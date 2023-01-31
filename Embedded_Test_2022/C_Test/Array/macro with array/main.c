#include <stdio.h>
#include <stdlib.h>
#define size 3

void print_arr(int *ptr);
int main()
{
   // int arr[3]={10,20,30};
    int arr[3];
    scan_arr(arr);
    print_arr(arr);

    return 0;
}

void scan_arr(int *ptr)
{ int i;
    for(i=0;i<size;i++)
    {
        scanf("%i",ptr+i);
    }
}

void print_arr(int *ptr)
{ int i;
    for(i=0;i<size;i++)
    {
        //printf("%i\n",ptr[i]);
        printf("%i\n",*(ptr+i));
    }
}
