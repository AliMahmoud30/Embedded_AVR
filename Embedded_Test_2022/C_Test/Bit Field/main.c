#include <stdio.h>
#include <stdlib.h>
#pragma pack(1)

struct car
{
    unsigned char x:3;     // with char
    unsigned char y:7;
    //unsigned char x:3;  //with int
    //unsigned char y:7;

}car;

int main()
{
    unsigned char *ptr;
    ptr=&car;
    car.x=2;
    car.y=6;
    printf("%i\n",sizeof(car));
    printf("%i\n",*(ptr+0));
    return 0;
}
