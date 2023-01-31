#include <stdio.h>
#include <stdlib.h>

int LinearSerach(int* Array, int Size, int Key);

int main()
{
    int Arr[5]={40,60,80,100,30};
    int Result;
    Result=LinearSerach(Arr,5,500);
    if(Result!=-1)
    {
     printf("key is Exist at Index:%d\n",Result);
    }
    else
    {
        printf("key is not exist! \n");
    }

    return 0;
}


int LinearSerach(int* Array, int Size, int Key)
{
    int i;
    int Result=-1;
    for(i=0;i<Size;i++)
    {
        if(Array[i]==Key)
        {
            Result=i;
           break;
        }
    }
    return Result;
}
