#include <stdio.h>
#include <stdlib.h>

struct  worker
{
    int id;
    double salary;
};

int main()
{   int i;
    struct worker arr[3]={{1,1500},{2,2055.3},{3,400.2}};
    struct worker *ptr;         // pointer to struct worker
    struct worker (*ptr1)[3];  //pointer to array of struct worker
    ptr=arr;
    ptr1=arr;
    printf("worker\t | ID\n");
    printf("---------|--------\n");
    for(i=0;i<3;i++)
    {
//        printf(" %i\t | %0.2lf\n",arr[i].id,arr[i].salary);
//        printf(" %i\t | %0.2lf\n",(ptr+i)->id,(ptr+i)->salary);
//        printf(" %i\t | %0.2lf\n",(*(ptr+i)).id,(*(ptr+i)).salary);
        printf(" %i\t | %0.2lf\n", (*(*ptr1+i)).id,(*(*ptr1+i)).salary);
    }

    return 0;
}
