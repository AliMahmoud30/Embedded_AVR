#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[3]={5,10,15};

    for(int i=0;i<3;i++)
    {
     printf("%i\n",arr[i]);
     printf("%i\n",*(arr+i));
    }

    return 0;
}
