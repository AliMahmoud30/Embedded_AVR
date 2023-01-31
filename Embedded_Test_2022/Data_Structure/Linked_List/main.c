#include <stdio.h>
#include <stdlib.h>

#include "Linked_List.h"

int main()
{
    int value;
    node* head='\0' ;
    Push_head(&head,25);
    Push_end(head,&head,30);
    print_list(head);
    printf("\n");
    Push_head(&head,5);
    print_list(head);
    printf("\n");
    value= Pop_head(&head);
    printf("the popped value is: %i\n",value);
    print_list(head);
    printf("\n");
    value= Remove_Last(head,&head);
    printf("the last item is: %i\n",value);
    print_list(head);
    printf("\n");
    Push_end(head,&head,300);
    print_list(head);
    printf("\n");
    insert_by_index(head,&head,50,1);
    print_list(head);
    printf("\n");
    remove_by_index(&head,1);
    print_list(head);
    printf("\n");
    remove_by_index(&head,0);
    print_list(head);
    printf("\n");
    remove_by_index(&head,0);
    print_list(head);
    printf("\n");
    return 0;
}
