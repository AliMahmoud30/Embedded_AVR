#include <stdio.h>
#include <stdlib.h>

void strcopy(const char* array_1, char *array_2);
void print_array(char*array);

int main()
{
    char str_1[]="ali morsy";
    char str_2[20];
    printf("str_1\t\tstr_2\n");
    print_array(str_1);
    printf("\t");
    print_array(str_2);
    printf("\n");

    strcopy(str_1,str_2);
    print_array(str_1);
    printf("\t");
    print_array(str_2);
    printf("\n");


    return 0;
}


void strcopy(const char* array_1, char *array_2)
{
    int i=0;
    while(*(array_1+i)!='\0')
    {
        *(array_2+i)= *(array_1+i);
        i++;
    }
    *(array_2+i)='\0';
}

void print_array(char *array)
{
    int i=0;
    while(*(array+i)!='\0')
    {
       printf("%c",*(array+i));
       i++;
    }

}
