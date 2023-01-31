#include <stdio.h>
#include <stdlib.h>

#define message(a,b) \
printf(#a " and " #b ":are friends")
int main()
{
    message(ali,ahmed);

    printf(#ali);
    return 0;
}
