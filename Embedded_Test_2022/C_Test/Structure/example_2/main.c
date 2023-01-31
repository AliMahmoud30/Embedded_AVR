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
    struct books book_2;


    scanf("%i",&book_1.book_id);
    fflush(stdin);
    gets(book_1.title);

    printf("book_1 title : %s\n",book_1.title);
    printf("book_1 ID    : %i\n",book_1.book_id);

    printf("\n\n");

    printf("book_2 title : %s\n",book_2.title);
    printf("book_2 ID    : %i\n",book_2.book_id);

    book_2=book_1;

    printf("book_2 title : %s\n",book_2.title);
    printf("book_2 ID    : %i\n",book_2.book_id);

    return 0;
}
