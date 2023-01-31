#include <stdio.h>
#include <stdlib.h>

#include <string.h>

struct books
{
    char title[15];
    int book_id;

};

int main()
{
    struct books book_1;
    book_1.book_id=20;
    strcpy(book_1.title,"C Programming");

    printf("book title : %s\n",book_1.title);
    printf("book ID    : %i\n",book_1.book_id);

    return 0;
}
