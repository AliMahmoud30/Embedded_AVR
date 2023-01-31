#include <stdio.h>
#include <stdlib.h>

struct books
{
    char title[30];
    int book_iD;
};


void print_struct(struct books b);

int main()
{
    struct books book_1={"C programming",20};
    struct books *ptr;
    ptr=&book_1;

    print_struct(book_1);

    printf("title : %s\n",ptr->title);
    printf("title : %i\n",ptr->book_iD);

    return 0;
}

void print_struct(struct books b)
{
    printf("title : %s\n",b.title);
    printf("title : %i\n",b.book_iD);
}
