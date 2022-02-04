#include<stdio.h>
#include<conio.h>
#define SIZE 10
void enqueue(int);
void dequeue();
void display();
int a[SIZE],front=-1,rear=-1;
void main()
{
    int choice,value;
    printf("Queue using Array \n");
    while(1)
    {
        printf("\n 1)Enqueue \n 2)Dequeue \n 3)Display \n");
        printf("\n Enter the choice \n");
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
            printf("EXIT \n");
        }
    }
}
void enqueue(int value)
{
    if(rear==SIZE-1)
    {
        printf("Insertion not possible \n");
    }
    else
    {
        rear++;
        a[rear]=value;
        if(front==-1)
        {
            front=0;
        }
    }

}
void dequeue()
{
    if(front==-1)
    {
        printf("Nothing to delete \n");
    }
    else
    {
        printf("The deleted value is %d \n",a[front]);
        front++;
    }
    if(front==rear)
    {
        front=rear=-1;
    }
}
void display()
{
    if(front==-1)
    {
        printf("Nothing to display \n");
    }
    else
    {
        int i;
        for(i=front;i<=rear;i++)
        {
            printf("%d \t",a[i]);
        }
    }
}
