

#include <stdio.h>
#include <stdlib.h>

#include "Linked_List.h"

void print_list(node* head)
{
    if(head== '\0')
    {
        printf("The Linked List is empty\n");
    }
    else
    {
        while(head!='\0')
        {
            printf("%d\n",head->val);
            head=head->next;
        }
    }
}
void Push_head(node** head_ptr,int Data)
{
    node* new_node;
    new_node=(node*)malloc(sizeof(node));
    new_node->val=Data;
    new_node->next=*head_ptr;
    *head_ptr=new_node;
}



void Push_end(node* head, node** head_add, int Data)
{
    if(head=='\0')
    {
        Push_head(head_add,Data);
    }
    else
    {
        while(head->next!='\0')
        {
            head=head->next;
        }

        head->next=(node*)malloc(sizeof(node));
        head->next->val=Data;
        head->next->next='\0';
    }
}


int Pop_head(node** head)
{
    int Retval;
    if(*head!=NULL)
    {
        node* temp_head=NULL;
        Retval=(*head)->val;
        temp_head=(*head)->next;
        free(*head);
        *head=temp_head;
    }
    return Retval;
}

int Remove_Last(node* head,node** head_add)
{
    int Retval=0;
    if(head!=NULL)
    {
        if(head->next==NULL)
        {
            Retval=Pop_head(head_add);
        }
        else
        {
            while(head->next->next!=NULL)
            {
                head=head->next;
            }
            Retval=head->next->val;
            free(head->next);
            head->next=NULL;
        }
    }
    return Retval;
}


void insert_by_index(node* head,node **head_ptr,int data ,int n)
{
node* temp;
node* current;
current=head;
int counter;
    if(n<0)
    {
        printf("the index must be positive number which greater than or equal zero\n");

    }
    else
    {
        if(head=='\0')
        {
            Push_head(head_ptr,data);
        }
        for(counter=0;counter<n-1;counter++)
        {
            current=current->next;
        }
        temp=(node*)malloc(sizeof(node));
        temp->val=data;
        temp->next=current->next;
        current->next=temp;
    }
}

int remove_by_index(node ** head_ptr, int n)
 {
    int i = 0;
    int retval;
    node * current = *head_ptr;
    node * temp_node = '\0';
    if(n<0)
    {
        printf("the index must be positive number which greater than or equal zero\n");
    }

    else if (n == 0)
    { //if the user inputs 0 so he want to remove the head
        retval=Pop_head(head_ptr);
    }
    else if(*head_ptr=='\0')
    {
        printf("the linked list is empty \n");
    }
    else
    {
        for (i = 0; i < n-1; i++)
        {
            if (current->next == '\0')
            {
                return Remove_Last(*head_ptr,head_ptr);
            }
            current = current->next;
        }

    temp_node = current->next;
    retval = temp_node->val;
    current->next = temp_node->next;
    free(temp_node);
    }
    return retval;
}




