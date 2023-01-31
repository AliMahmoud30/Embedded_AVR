#include <stdio.h>
#include <stdlib.h>

void swap(int **a ,int **b);

int main()
{
    int x=50, y=100;
    int *ptr1 =&x;
    int *ptr2 =&y;


    printf("address of x before swap:%i\n",ptr1);
    printf("address of y before swap:%i\n\n",ptr2);

    swap(&ptr1,&ptr2);
    //swap(&x,&y);

    printf("address of x after swap:%i\n",ptr1);
    printf("address of y after swap:%i\n\n",ptr2);

    printf("x=%i\n",x);
    printf("y=%i\n\n",y);

    return 0;
}

void swap(int **a ,int **b)
{
    int* temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
