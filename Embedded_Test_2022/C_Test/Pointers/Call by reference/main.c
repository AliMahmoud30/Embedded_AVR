#include <stdio.h>
#include <stdlib.h>

void swap(int* x, int* y);


int main()
{
    int x=20,y=50;

    printf("x=%i\ny=%i\n",x,y);
    swap(&x,&y);
    printf("x=%i\ny=%i\n",x,y);

    return 0;
}
void swap(int* a, int* b)
{

    int temp;
    temp=*a;
    *a=*b;
    *b=temp;

    printf("x=%i\ny=%i\n",*a,*b);

}
