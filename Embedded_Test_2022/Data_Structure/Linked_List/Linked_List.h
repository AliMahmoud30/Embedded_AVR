#ifndef LINKED_LIST_H
#define LINKED_LIST_H


typedef struct point
{
    int val;
    struct point* next;
}node;


void print_list(node* head);
void Push_head(node** head_ptr,int Data);
void Push_end(node* head, node** head_add, int Data);
int Pop_head(node** head);
int Remove_Last(node* head,node** head_add);
void insert_by_index(node* head,node **head_ptr,int data ,int n);
int remove_by_index(node ** head_ptr, int n);

#endif // LINKED_LIST_H
