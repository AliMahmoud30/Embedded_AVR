#include <stdio.h>
#include <stdlib.h>
#include "Queue functions.h"
#define SIZE 3
int queue[SIZE];
int front=0,rear=0,count=0;

int is_queue_empty(void)
{
    int x;
    if(count==0)
    {
        x=1;
    }
    else
    {
        x=0;
    }
    return x;
}
int is_queue_full(void)
{
    int x;
    if(count==SIZE)
    {
        x=1;
    }
    else
    {
        x=0;
    }
    return x;
}

void enqueue(int data)
{
    queue[rear]=data;
    rear=(rear+1)%SIZE;
    count++;
}
int dequeue(void)
{
    int x;
    x=queue[front];
    front=(front+1)%SIZE;
    count--;
    return x;
}

int number_of_queue_elements(void)
{
    return count;
}

void display_queue_elements(void)
{
    int i,front1=front;
    for(i=0;i<count;i++)
    {
        printf("%i\n",queue[front1]);
        front1=(front1+1)%SIZE;
    }
}
