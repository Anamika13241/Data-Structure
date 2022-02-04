#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*front=NULL,*rear=NULL;
void enqueue(int);
void dequeue();
void display();
void main()
{
    int value,choice;
    printf("Queue using linked list:\n");
    while(1)
      {
       printf("\n 1)Enqueue \n 2)Dequeue \n 3)Display \n");
       printf("Enter your choice \n");
       scanf("%d",&choice);
       switch(choice)
       {
       case 1:
        printf("Enter the value to be inserted \n");
        scanf("%d",&value);
        enqueue(value);
        display();
        break;
       case 2:
        dequeue();
        display();
        break;
       case 3:
        display();
        break;
       default:
        printf("exit \n");
       }
   }
}
void enqueue(int value)
{
    struct node *newnode;
    newnode=malloc(sizeof(struct node));
    newnode->data=value;
    if(rear==NULL)
    {
        rear=front=newnode;
        newnode->next=NULL;
    }
    else
    {
        rear->next=newnode;
        rear=newnode;
        newnode->next=NULL;
    }
}
void dequeue()
{
    if(rear==NULL)
    {
        printf("Queue is empty \n");
    }
    else
    {
        struct node *temp=front;
        front=temp->next;
        free(temp);
    }
}
void display()
{
     if(rear==NULL)
    {
        printf("Queue is empty \n");
    }
    else
    {
        struct node *temp=front;
        while(temp->next!=NULL)
        {
            printf("%d-->",temp->data);
            temp=temp->next;
        }
        printf("%d-->NULL",temp->data);
    }
}


