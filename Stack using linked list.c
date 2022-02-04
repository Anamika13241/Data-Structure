#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*top=NULL;
void push(int);
void pop();
void display();
void main()
{
    int choice,value;
    printf(" \n Stack using Linked List \n");
    while(1)
    {
        printf("\n 1)Insertion \n 2)Deletion \n 3)Display \n");
        printf("\n Enter the choice \n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter the value to be inserted \n");
            scanf("%d",&value);
            push(value);
            display();
            break;
        case 2:
            pop();
            display();
            break;
        case 3:
            display();
            break;
        default:
            printf("EXIT \n");
        }
    }
}
void push(int value)
{
    struct node *newnode;
    newnode=malloc(sizeof(struct node));
    newnode->data=value;
    if(top==NULL)
    {
        top=newnode;
        newnode->next=NULL;
    }
    else
    {
        newnode->next=top;
        top=newnode;
    }
}
void pop()
{
    if(top==NULL)
    {
        printf("Nothing to delete \n");
    }
    else
    {
        struct node *temp=top;
        top=temp->next;
        free(temp);
    }
}
void display()
{
    if(top==NULL)
    {
        printf("Nothing to display \n");
    }
    else
    {
        struct node *temp=top;
        while(temp->next!=NULL)
        {
            printf("%d-->",temp->data);
            temp=temp->next;
        }
        printf("%d-->NULL",temp->data);
    }
}
