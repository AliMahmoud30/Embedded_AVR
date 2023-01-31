#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b;
    float result;
    unsigned char operation;
    //scanf("%c",&operation);
    printf("please Enter 2 numbers:\n");
    scanf("%i%i",&a,&b);
    printf("Enter operation:\n");
    fflush(stdin);
    scanf("%c",&operation);

    if(operation=='+')
    {
      result=a+b;
    }
    else if(operation=='-')
    {
        result=a-b;
    }
    else if(operation=='*')
    {
        result=a*b;
    }
    else if(operation=='/')
    {
        if(b!=0)
        {
          result=a/(float)b;
        }
        else
        {
            printf("can't divide by Zero");
        }
    }
    else if(operation=='%')
    {

        result=a%b;
    }
    else
    {
        printf("Wrong Operation\n");
    }
    printf("result=%f\n",result);
     printf("operation= %i",operation);
    return 0;
}
