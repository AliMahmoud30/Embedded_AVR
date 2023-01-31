#include <stdio.h>
#include <stdlib.h>

struct books
{
    char title[30];
    int book_iD;
};
int main()
{
    struct books book_1={"C programming",20};
    struct books *ptr;
    ptr=&book_1;

    printf("title : %s\n",book_1.title);
    printf("title : %i\n",book_1.book_iD);

    printf("title : %s\n",(*ptr).title);
    printf("title : %i\n",(*ptr).book_iD);

    printf("title : %s\n",ptr->title);
    printf("title : %i\n",ptr->book_iD);


    return 0;
}
