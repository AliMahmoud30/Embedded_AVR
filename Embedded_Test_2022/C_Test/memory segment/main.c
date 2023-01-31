#include <stdio.h>
#include <stdlib.h>


int main()
{
    static int x=5;
    x=x+5;
    x++;
    return 0;
}
