#include <stdio.h>
#include <stdlib.h>

struct student
{
    int age;
    char id;
}x;

int main()
{
   struct student x;

    x.age=30;
    x.id=12;
    printf("%i\n",x.age);
    printf("%i\n",x.id);
    return 0;
}
