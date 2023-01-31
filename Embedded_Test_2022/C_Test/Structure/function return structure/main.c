#include <stdio.h>
#include <stdlib.h>

struct employee
{
    int id;
    double salary;
};

struct employee add_value_to_structure(struct employee emp);

int main()
{
    struct employee emp1;
    scanf("%i%lf",&(emp1.id),&(emp1.salary));
    printf("id=%i\nsalary=%0.2f\n",emp1.id,emp1.salary);
    printf("\n\n");
    emp1=add_value_to_structure(emp1);
    printf("id=%i\nsalary=%0.2f\n",emp1.id,emp1.salary);
    return 0;
}

struct employee add_value_to_structure(struct employee emp)
{
    emp.id+=5;
    emp.salary+=emp.salary*0.1;
    return emp;
}
