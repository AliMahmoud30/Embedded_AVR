#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_arr(int* ptr, int size)
{
    int i;
    for(i=0;i<size;i++)
    {
        printf("arr[%i]=%i\n",i,*(ptr+i));
    }
}

void cat_array(int* arr1,int* arr2,int* arr3, int size)
{
    int i;
    for(i=0;i<size;i++)
    {
        //*(arr3+i)=*(arr1+i);
        arr3[i]=arr1[i];
    }
    for(i=0;i<size;i++)
    {
        *(arr3+i+size)=*(arr2+i);
    }

}

void cat_str(char *str1,char *str2,char *str3)
{
    int i=0,j=0;
    while(*(str1+i)!='\0')
    {
        *(str3+i)=*(str1+i);
        i++;
    }
    while(*(str2+j)!='\0')
    {
        *(str3+i)=*(str2+j);
        i++;
        j++;
    }
   *(str3+i)='\0';
}

void print_str(const char* str)
{
    int i=0;
    while(*(str+i)!='\0')
    {
        printf("%c",*(str+i));
        i++;
    }
}
int main(void)
{
  int arr1[]={1,2,3};
  int arr2[]={4,5,6};
  int arr3[20];

  char str[20];
 printf("%i\n",sizeof(arr2));
 cat_array(arr1,arr2,arr3,3);
  print_arr(arr3,6);
cat_str("ali ","Morsy",str);
print_str(str);
  return 0;
}
