#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
}*head=NULL;
void insertatbeg(int);
void insertatbeg(int);
void insertatend(int);
void insertatspec(int,int,int);
void deleteatbeg();
void deleteatend();
void deleteatspec(int);
void display();
void main()
{
     int choice,value,loc1,loc2,key;
    printf("\n Linked List Operations\n");
    while(1)
    {
        printf("\n 1)Insertion at beginning \n 2)Insertion at end \n 3)Insertion at specific node \n 4)Deletion at beginning \n 5)Deletion at end \n 6)Deletion at specific node \n 7)Display \n");
        printf("Enter your choice \n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter the value to be inserted \n");
            scanf("%d",&value);
            insertatbeg(value);
            display();
            break;
        case 2:
            printf("Enter the value to be inserted \n");
            scanf("%d",&value);
            insertatend(value);
            display();
            break;
        case 3:
            printf("Enter the value to be inserted \n");
            scanf("%d",&value);
            printf("Enter the 1st location to be inserted \n");
            scanf("%d",&loc1);
            printf("Enter the 2nd location to be inserted \n");
            scanf("%d",&loc2);
            insertatspec(value,loc1,loc2);
            display();
            break;
        case 4:
            deleteatbeg();
            display();
            break;
        case 5:
            deleteatend();
            display();
            break;
        case 6:
            printf("Enter the value to be deleted \n");
            scanf("%d",&key);
            deleteatspec(key);
            display();
            break;
        case 7:
            display();
            break;
        default:
            printf("EXIT \n");
        }
    }
}
void insertatbeg(int value)
{
    struct node *newnode;
    newnode=malloc(sizeof(struct node));
    newnode->data=value;
    if(head==NULL)
    {
        head=newnode;
        newnode->prev=NULL;
        newnode->next=NULL;
    }
    else
    {
        newnode->prev=NULL;
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
    }
}
void insertatend(int value)
{
    struct node *newnode;
    newnode=malloc(sizeof(struct node));
    newnode->data=value;
    if(head==NULL)
    {
        head=newnode;
        newnode->prev=NULL;
        newnode->next=NULL;
    }
    else
    {
        struct node *temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        newnode->next=NULL;
        temp->next=newnode;
        newnode->prev=temp;
    }
}
void insertatspec(int value,int loc1,int loc2)
{

    struct node *newnode;
    newnode=malloc(sizeof(struct node));
    newnode->data=value;
    if(head==NULL)
    {
        head=newnode;
        newnode->prev=NULL;
        newnode->next=NULL;
    }
    else
    {
        struct node *temp=head;
        while(temp->data!=loc1 && temp->data!=loc2)
        {
            temp=temp->next;
        }
        newnode->next=temp->next;
        temp->next->prev=newnode;
        temp->next=newnode;
        newnode->prev=temp;
    }
}
void deleteatbeg()
{
    if(head==NULL)
    {
        printf("Nothing to delete \n");
    }
    else
    {
        struct node *temp=head;
        head=temp->next;
        head->prev=NULL;
        free(temp);
    }
}
void deleteatend()
{
    if(head==NULL)
    {
        printf("Nothing to delete \n");
    }
    else
    {
        struct node *temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->prev->next=NULL;
        free(temp);
    }
}
void deleteatspec(int key)
{
    if(head==NULL)
    {
        printf("Nothing to delete \n");
    }
    else
    {
        struct node *temp=head;
        while(temp->data!=key)
        {
            temp=temp->next;
        }
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
    }
}
void display()
{
    if(head==NULL)
    {
        printf("Nothing to delete \n");
    }
    else
    {
        struct node *temp=head;
        while(temp->next!=NULL)
        {
            printf("%d-->",temp->data);
            temp=temp->next;
        }
        printf("%d-->NULL",temp->data);
}
}
