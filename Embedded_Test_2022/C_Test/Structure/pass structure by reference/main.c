#include <stdio.h>
#include <stdlib.h>

#include "struct.h"


int main()
{
    struct books book_1={"C programming",20};
    struct books book_2;

    print_struct(&book_1);
    printf("\n\n");
    print_struct(&book_2);
    printf("\n\n");
    book_2=book_1;
    print_struct(&book_2);

    return 0;
}

