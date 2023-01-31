#include <stdio.h>
#include <stdlib.h>

//#pragma pack(1)

struct car
{
    char x;
    int y;
    char z;
};

int main()
{
    struct car w;
    struct car *ptr=&w;

    printf("size of struct: %i\n",sizeof(w));
    printf("%i\n",&w.x);
    printf("%i\n",&w.y);
    printf("%i\n",&w.z);
    printf("%i\n",ptr);
    ptr++;
    printf("%i\n",ptr);

    return 0;
}
