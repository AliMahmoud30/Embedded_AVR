

void sum_2_array(int *arr_1,int *arr_2,int *arr_3,int size)
{
    int i;
    for(i=0;i<size;i++)
    {
     //*(arr_3+i)= (*(arr_1+i)) + (*(arr_2+i));
     arr_3[i]= arr_1[i] + arr_2[i];
    }

}

void print_arr(int *ptr,int size)
{ int i;
    for(i=0;i<size;i++)
    {
        //printf("%i\n",ptr[i]);
        printf("%i\n",*(ptr+i));
    }
}

