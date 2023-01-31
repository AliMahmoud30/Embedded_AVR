#include <stdio.h>
#include <stdlib.h>

void SacnArray(int* Arrat, int Size);
void PrintArray(int* Array, int Size);
void Bubble_Sort(int* Array, int Size);

int main()
{
    int Arr[3];
    SacnArray (Arr, 3);
    PrintArray(Arr, 3);

    Bubble_Sort(Arr, 3);
    PrintArray(Arr, 3);
    return 0;
}


void Bubble_Sort(int* Array, int Size)
{
    printf("\nArray After Sorted:\n");
    int counter1;
    int counter2;
    int flag;
    int Temp;
    for(counter1= Size-1; counter1>0; counter1--)
    {
        flag= 0;
        for(counter2=0; counter2<counter1;counter2++ )
        {
            if(Array[counter2+1]< Array[counter2])
            {
                Temp=Array[counter2];
                Array[counter2]=Array[counter2+1];
                Array[counter2+1]=Temp;
                flag = 1;
            }
        }
        if(flag == 0)
        {
            break;
        }

    }

}
void SacnArray(int* Arrat, int Size)
{
    int i;
    for(i=0; i<Size; i++)
    {
        printf("Enter Element Num_%d:",i);
        scanf("%d",&Arrat[i]);
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
