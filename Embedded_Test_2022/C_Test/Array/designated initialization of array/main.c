#include <stdio.h>
#include <stdlib.h>

int main()
{
    //int arr[10]={0,0,2,0,0,10,0,0,0,20};
    int arr[]={[5]=10,30,[9]=20,[2]=2};
    int i;

    for(i=0;i<10;i++)
    {
        printf("arr[%i]=%i\n",i,arr[i]);
    }
    printf("%i\n",sizeof(arr));
    return 0;
}
