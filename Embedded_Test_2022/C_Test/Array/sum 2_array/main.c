#include <stdio.h>
#include <stdlib.h>

#include "sum.h"
int main()
{
    int x[3]={2,3,4};
    int y[3]={5,6,7};
    int z[3];

    sum_2_array(x,y,z,3);
    print_arr(z,3);

    return 0;
}
