#include <stdio.h>
#include <stdlib.h>
int arr1[3];
int main()
{

    int arr2[3];
    static int arr3[3];
    int i;
    printf("arr_1\tarr_2\tarr_3\n");

    for(i=0;i<3;i++)
    {
        printf("%i\t%i\t%i\n",arr1[i],arr2[i],arr3[i]);
    }

    return 0;
}
