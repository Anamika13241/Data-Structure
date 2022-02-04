#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
}*head=NULL;
void insertionatbeg(int);
void insertionatend(int);
void insertionatspec(int,int,int);
void display();
void main()
{
    int choice,value,loc1,loc2;
    printf("Doubly Linked List \n");
    while(1)
    {
        printf("\n 1)Insertion at Beginning \n 2)Insertion at end \n 3)Insertion at specific node \n");
        printf("Enter the choice:\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("enter the value to be inserted \n");
            scanf("%d",&value);
            insertionatbeg(value);
            display();
            break;
        case 2:
            printf("enter the value to be inserted \n");
            scanf("%d",&value);
            insertionatend(value);
            display();
            break;
        case 3:
             printf("enter the value to be inserted \n");
            scanf("%d",&value);
            printf("Enter the first location:\n");
            scanf("%d",&loc1);
            printf("Enter the second location:\n");
            scanf("%d",&loc2);
            insertionatspec(value,loc1,loc2);
            display();
            break;
        case 4:
            display();
            break;
        default:
            printf("EXIT \n");
        }
    }
}
void insertionatbeg(int value)
{
    struct node *newnode;
    newnode=malloc(sizeof(struct node));
    newnode->data=value;
    if(head==NULL)
    {
        head=newnode;
        newnode->next=NULL;
        newnode->prev=NULL;
    }
    else
    {
        newnode->prev=NULL;
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
    }
}
void insertionatend(int value)
{
    struct node *newnode;
    newnode=malloc(sizeof(struct node));
    newnode->data=value;
    if(head==NULL)
    {
        head=newnode;
        newnode->next=NULL;
        newnode->prev=NULL;
    }
    else
    {
        struct node *temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->prev=temp;
        newnode->next=NULL;
    }
}
void insertionatspec(int value,int loc1,int loc2)
{
    struct node *newnode;
    newnode=malloc(sizeof(struct node));
    newnode->data=value;
    if(head==NULL)
    {
        head=newnode;
        newnode->next=NULL;
        newnode->prev=NULL;
    }
    else
    {
        struct node *temp=head;
        while(temp->data!=loc1 && temp->data!=loc2)
        {
            if(temp->next==NULL)
            {
                printf("location not found \n");
            }
            temp=temp->next;
        }
        newnode->next=temp->next;
        temp->next->prev=newnode;
        temp->next=newnode;
        newnode->prev=temp;
    }
}
void display()
{
    if(head==NULL)
    {
        printf("Nothing to display \n");
    }
    else
    {
        struct node *temp;
        while(temp->next!=NULL)
        {
            printf("%d-->",temp->data);
            temp=temp->next;
        }
        printf("%d-->NULL",temp->data);
    }
}
