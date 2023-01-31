#include <stdio.h>
#include <stdlib.h>

struct employee
{
    int id;
    double salary;
    char name[10];
};

int main()
{
    struct employee z={12,1570.25,"ali morsy"};
      struct employee *ptr;
        ptr=&z;
//
//    z.id=12;
//    z.salary=1570.25;
//    z.name="ali";
    printf("name   : %i\n",&z.name); //array+1 == &array[1]
    printf("ID     : %i\n",&z.id);
    printf("Salary : %i\n",&z.salary);

    printf("\n\n");

    printf("name   : %s\n",(&z.name)+0); //array+1 == &array[1]
    printf("ID     : %i\n",z.id);
    printf("Salary : %0.2lf\n",z.salary);


    printf("%i\n",&z);
    printf("%i\n",ptr);
    printf("%i\n",sizeof(z));
    printf("%i\n",&z+1);
    ptr++;
    printf("%i\n",ptr);


    return 0;
}
