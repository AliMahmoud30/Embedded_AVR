#include <stdio.h>
#include <stdlib.h>

int main()
{
    void file(void);   // function Extern By Default
    int x=5;
    //static int y=x;   // compilation error
    print();
    print();
    print();
    file();
    return 0;
}





void print(void)
{
    static int x=0; //this line not found in run time but before
    printf("%i\n",x);
    x++;
}
