#include <stdio.h>
#include <stdlib.h>

void SacnArray(int* Arrat, int Size);
void PrintArray(int* Array, int Size);
void SortArray(int* Array, int Size);
void SORTARR(int* Array, int Size);
int main()
{
    int Arr[3];
    SacnArray (Arr, 3);
    PrintArray(Arr, 3);

    SORTARR(Arr, 3);
    PrintArray(Arr, 3);
    return 0;
}


void SortArray(int* Array, int Size)
{
    printf("\nArray After Sorted:\n");
    int counter1;
    int counter2;
    int Index;
    int Temp;
    for(counter1=0; counter1<Size; counter1++)
    {
        Index= counter1;
        for(counter2=counter1+1; counter2<Size;counter2++ )
        {
            if(Array[counter2]< Array[Index])
            {
                Index = counter2;

            }
        }
        if(Index != counter1)
        {
            Temp=Array[counter1];
            Array[counter1]=Array[Index];
            Array[Index]=Temp;

        }

    }

}




void SORTARR(int* Array, int Size)
{
    int counter1;
    int counter2;
    int index;
    int Temp;
    for(counter1=0; counter1<Size; counter1++)
    {
        index = counter1;
        for(counter2=counter1+1;counter2< Size;counter2++)
        {
            if(Array[counter2] < Array[index])
            {
                index = counter2;
            }

        }
        if(index != counter1)
        {
            Temp = Array[counter1];
            Array[counter1] = Array[index];
            Array[index] = Temp;
        }
    }

}
void SacnArray(int* Arra, int Size)
{
    int i;
    for(i=0; i<Size; i++)
    {
        printf("Enter Element Num_%d:",i);
        scanf("%d",&Arra[i]);
        //scanf("%d",Arrat+i);
    }

}

void PrintArray(int* Array, int Size)
{
    int i;
    for(i=0; i<Size; i++)
    {
        printf("Arrry[%d]=%d\n",i,Array[i]);
    }

}
