#include <stdio.h>
#include <stdlib.h>

enum week
{
    saturday,sunday,monday,tuesday,wednesday,thursday,friday
};
int main()
{
    int x;
    enum week day;
    day= wednesday;

    printf("%i\n",day);
    return 0;
}
