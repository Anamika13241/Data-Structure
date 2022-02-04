
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*head=NULL;
void insertionatbeg(int);
void insertionatend(int);
void insertionatspec(int,int,int);
void deletionatbeg();
void deletionatend();
void deletionatspec(int);
void display();
void main()
{
    int choice,value,loc1,loc2,key;
    printf("Circular Linked List \n");
    while(1)
    {
        printf("\n 1)Insertion at beginning \n 2)Insertion at end \n 3)Insertion at specific node \n 4)Deletion at beginning \n 5)Deletion at end \n 6)Deletion at specific node\n 7)Display \n");
        printf(" \n Enter your choice \n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter the value to be inserted \n");
            scanf("%d",&value);
            insertionatbeg(value);
            display();
            break;
        case 2:
            printf("Enter the value to be inserted \n");
            scanf("%d",&value);
            insertionatend(value);
            display();
            break;
        case 3:
            printf("Enter the value to be inserted \n");
            scanf("%d",&value);
            printf("Enter the first location \n");
            scanf("%d",&loc1);
            printf("Enter the second location \n");
            scanf("%d",&loc2);
            insertionatspec(value,loc1,loc2);
            display();
            break;
        case 4:
            deletionatbeg();
            display();
            break;
        case 5:
            deletionatend();
            display();
            break;
        case 6:
            printf("Enter the value to be deleted \n");
            scanf("%d",&key);
            deletionatspec(key);
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
void insertionatbeg(int value)
{
    struct node *newnode;
    newnode=malloc(sizeof(struct node));
    newnode->data=value;
    if(head==NULL)
    {
        head=newnode;
        newnode->next=head;
    }
    else
    {
        struct node *temp=head;
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        newnode->next=head;
        head=newnode;
        temp->next=newnode;
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
        newnode->next=head;
    }
    else
    {
        struct node *temp=head;
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->next=head;
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
        newnode->next=head;
    }
    else
    {
        struct node *temp=head;
        while(temp->data!=loc1 && temp->data!=loc2)
        {
            temp=temp->next;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }
}
void deletionatbeg()
{
    if(head==NULL)
    {
        printf("list is empty \n");
    }
    else
    {
        struct node *temp1=head,*temp2=head;
        while(temp2->next!=head)
        {
            temp2=temp2->next;
        }
        head=temp1->next;
        temp2->next=head;
        free(temp1);
    }
}
void deletionatend()
{
    if(head==NULL)
    {
        printf("list is empty \n");
    }
    else
    {
        struct node *temp1=head,*temp2=head;
        while(temp1->next!=head)
        {
            temp2=temp1;
            temp1=temp1->next;
        }
        temp2->next=head;
        free(temp1);
    }
}

void deletionatspec(int key)
{
    if(head==NULL)
    {
        printf("list is empty \n");
    }
    else
    {
        struct node *temp1=head,*temp2=head;
        while(temp1->data!=key)
        {
            if(temp1->next==head)
            {
                printf("value to be deleted is not found");
            }
            temp2=temp1;
            temp1=temp1->next;
        }
        if(temp1->next==head)
        {
          temp1=NULL;
          free(temp1);
          printf("node deleted \n");
        }
        temp2->next=temp1->next;
        free(temp1);
    }
}
void display()
{
    if(head==NULL)
    {
        printf("list is empty \n");
    }
    else
    {
        struct node *temp=head;
        while(temp->next!=head)
        {
            printf("%d-->",temp->data);
            temp=temp->next;
        }
        printf("%d-->%d",temp->data,temp->next->data);
    }
}
