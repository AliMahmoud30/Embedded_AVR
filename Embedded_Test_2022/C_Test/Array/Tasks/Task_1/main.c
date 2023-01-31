#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[5]={100,30,1,500,300};
    int max_num=0,min_num=1000;
    int i=0;
    for(i=0;i<sizeof(arr)/sizeof(int);i++)
    {
        if((*(arr+i))>max_num)
        {
            max_num=*(arr+i);
        }
        if((*(arr+i))<min_num)
        {
            min_num=*(arr+i);
        }


    }
    printf("max_num=%i\n",max_num);
    printf("min_num=%i\n",min_num);
    return 0;
}
