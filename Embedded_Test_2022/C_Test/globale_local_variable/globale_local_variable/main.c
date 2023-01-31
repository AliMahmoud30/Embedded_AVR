#include <stdio.h>
#include <stdlib.h>

int x;
int x=20;

void print(void);

int main()
{
    int y;
    int x=10;
    print();
    printf("x=%i\ny=%i\n",x,y);
    return 0;
}

void print(void)
{
    printf("x=%i\n",x);
}
