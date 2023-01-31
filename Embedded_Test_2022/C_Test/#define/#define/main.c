#include <stdio.h>
#include <stdlib.h>

#define x 10
//continuation operator
#define A \
5+x
int main()
{
    int y=A;
    printf("%i\n",x);
    #undef x
    #define x 5
    printf("%i\n",A);

    //built in macros
    printf("File : %s\n",__FILE__);
    printf("DATE : %s\n",__DATE__);
    printf("TIME : %s\n",__TIME__);
    printf("LINE : %d\n",__LINE__);
    printf("ANSI : %d\n",__STDC__);



    return 0;
}
