#include <stdio.h>
#include <stdlib.h>

struct emp
{
    short id;
    double salary;
};

struct company
{
     int id;
    struct emp emp1;
};
int main()
{
    struct company comp1;
    comp1.id=20;
    comp1.emp1.id=50;
    comp1.emp1.salary=3500;

    printf("comp   id:%i\n",(comp1.id);
    printf("emp    id:%hd\n",comp1.emp1.id);
    printf("salary id:%0.2lf\n",comp1.emp1.salary);
    return 0;
}
