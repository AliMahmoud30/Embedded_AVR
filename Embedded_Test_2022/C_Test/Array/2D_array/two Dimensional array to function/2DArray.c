
#include <stdio.h>
void print_2d_array(int (*arr)[3],int size_1,int size_2)
{
    int i,j;
    for(i=0;i<size_1;i++)
    {
        for(j=0;j<size_2;j++)
        {
           printf("%i\t",*(*(arr+i)+j));  // int (*ptr)[]
        }
    printf("\n");
    }
}
