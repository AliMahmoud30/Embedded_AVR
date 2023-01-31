#include <stdio.h>
#include <stdlib.h>

#include <string.h>

struct books
{
    char name[20];
    int id;
    char auther[10];

};
typedef struct books book;

int main()
{
     book b1;

    printf("%i\n",sizeof(b1));
    printf("%i\n",sizeof(book));

    b1.id=230324;
    strcpy(b1.name,"C Programming");
    strcpy(b1.auther,"Ali Morsy");

    printf("Book ID : %i\n",b1.id);
    printf("Book Name : %s\n",b1.name);
    printf("Book Name : %s\n",b1.auther);

    return 0;
}
