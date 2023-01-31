#include <stdio.h>
#include <stdlib.h>

void sum_2array(int (*array_1)[],int (*array_2)[], int (*array_3)[],int size);
void print_array(int *array,int size);
int main()
{
    int y;
    scanf("%i",&y);
    int arr_1[y];
    int arr_2[3]={3,3,3};
    int arr_3[3];
    int x;
    printf("Please enter 3 elements to array_1:\n");
    for(x=0;x<3;x++)
    {
        scanf("%i",(arr_1+x));
    }
    print_array(arr_3,3);
    sum_2array(arr_1, arr_2, arr_3, 3);
    print_array(arr_3,3);

    return 0;
}

void sum_2array(int (*array_1)[],int (*array_2)[], int (*array_3)[],int size)
{
    int i;
    for(i=0;i<size;i++)
    {
        //*(array_3+i)=*(array_1+i) + *(array_2+i);
        *(*(array_3)+i)=*(*(array_1)+i) + *(*(array_2)+i);

    }
}


void print_array(int *array,int size)
{
    int i;
    for(i=0;i<size;i++)
    {
        printf("%i\n",array[i]);
    }


}

