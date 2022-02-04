
Conversation opened. 3 messages. All messages read.

Skip to content
Using Gmail with screen readers
msamilmanadiyil2560@gmail.com
Meet
New meeting
Join a meeting
Hangouts

2 of 10
(no subject)
Inbox

Amil Shaji <msamilmanadiyil2560@gmail.com>
Attachments
Wed, 22 Dec 2021, 11:49
to me


Attachments area

Anamika Arun <anamikaarun600@gmail.com>
Attachments
Wed, 22 Dec 2021, 11:50
to anjuanjima2000



---------- Forwarded message ---------
From: Amil Shaji <msamilmanadiyil2560@gmail.com>
Date: Wed, 22 Dec 2021 at 11:49
Subject:
To: <anamikaarun600@gmail.com>




Attachments area

Anamika Arun <anamikaarun600@gmail.com>
Attachments
Wed, 22 Dec 2021, 11:50
to anittavarghese2023a


Attachments area
#include<stdio.h>
int parent[30];
void makeset();
int find(int);
int unionn(int,int);
void main()
{
    unionn(2,3);
    unionn(1,4);
    unionn(4,2);
    unionn(1,3);
    int i;
    for(i=1;i<=5;i++)
    {
        if(parent[i]!=0 && parent[i]!=i)
        {
            printf("%d\t%d\t",i,parent[i]);

        }
    }
}
void makeset()
{
    int i;
    for(i=1;i<=5;i++)
    {
        parent[i]=0;
    }
}
int find(int a)
{
    if(parent[a]==0)
        return a;
    else
        find(parent[a]);

}
int unionn(int a,int b)
{
    a=find(a);
    b=find(b);
    if(a!=b)
        parent[b]=a;
    else
        printf("Same set");
}
setunion.c
Displaying setunion.c.
