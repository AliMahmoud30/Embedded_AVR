#include <stdio.h>
#include <stdlib.h>

int main()
{
  int arr[3],i,sum=0;

  for(i=0;i<3;i++)
  {
      scanf("%i",arr+i);
  }

  for(i=0;i<3;i++)
  {
      sum+=arr[i];
      printf("%i\t",*(arr+i));
  }

    printf("sum=%i\n",sum);
    return 0;
}
