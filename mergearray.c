#include<stdio.h>
void main()
{
    int a[4],ar[4],arr[4],n,m,i;
    printf("Enter the elements of first array:");
    for(i=0;i<4;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter the elements of second array:");
    for(i=0;i<4;i++)
    {
        scanf("%d",&ar[i]);
    }
    for(i=0;i<4;i++)
    {
        arr[i]=a[i]+ar[i];
         printf(" \n The elements of third array is:");
         printf("%d",arr[i]);
    }
}


