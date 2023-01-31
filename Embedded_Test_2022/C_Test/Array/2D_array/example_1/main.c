#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[2][3]={{1,2,3},{4,5,6}};
    int i,j;

    printf("%i\n",arr[0][1]);  //
    printf("%i\n",arr);  //
    printf("%i\n",arr+1);  //
    printf("%i\n",&arr);  //
    printf("%i\n",&arr+1);  //
    printf("%i\n",*(*(arr+1)+1));  // int (*ptr)[2]

    printf("\n\n");

    for(i=0;i<2;i++)
    {
        for(j=0;j<3;j++)
        {

           printf("%i\t",arr[i][j]);
        }
    printf("\n");
    }
//--------------------------------

    printf("\n\n");

    for(i=0;i<2;i++)
    {
        for(j=0;j<3;j++)
        {

           printf("%i\t",*(*(arr+i)+j));  // int (*ptr)[]
        }
    printf("\n");
    }


    return 0;
}
