#include <stdio.h>
#include <stdlib.h>

int BinarySerach(int* Array, int FirstIndex, int LastIndex, int Keyvalue);

int main()
{
    int Arr[5]={40,60,80,100,200};
    int Result;
    Result=BinarySerach(Arr,0,4,100);
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

int BinarySerach(int* Array, int FirstIndex, int LastIndex, int Keyvalue)
{
    int mid;
    int Return_Val;
    mid = (FirstIndex + LastIndex)/2;
    if(FirstIndex > LastIndex)
    {
        Return_Val = -1;
    }
    else if(Array[mid] == Keyvalue)
    {
        Return_Val = mid;
    }
    else if(Array[mid] > Keyvalue)
    {
        Return_Val = BinarySerach(Array, FirstIndex, mid-1, Keyvalue);
    }
    else if(Array[mid] < Keyvalue)
    {
        Return_Val = BinarySerach(Array, mid +1, LastIndex, Keyvalue);
    }

    return Return_Val;
}






