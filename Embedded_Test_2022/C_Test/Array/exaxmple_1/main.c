#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[3]={10,20,30};
    //arr++; //Not Allowed
    int *ptr=arr;
    char *ptr2=&arr;

    //arr++; //Not Allowed
    printf("address of element 0 = %i\n",arr);
    printf("address of element 0 = %i\n",&arr);
    printf("address of element 0 = %i\n",arr+1);
    printf("address of element 0 = %i\n\n",arr+2);

    printf("pointer point address: %i\n",ptr);
    ptr++; //Allowed
    printf("pointer point address: %i\n",ptr);
    ptr++; //Allowed
    printf("pointer point address: %i\n\n",ptr);



    printf("%i\n",arr[0]);
    printf("%i\n",*(arr+1));
    printf("%i\n\n",*ptr);


    printf("%i\n",*ptr);
    printf("%i\n\n",*ptr2);

    *(ptr2+1)=1;
    printf("%i\n\n",arr[0]);
    printf("%i\n\n",*(arr+0));




    return 0;
}
