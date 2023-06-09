#include<stdio.h>
void insertion_sort(int [],int);

void main()
{
    int arr[100],n,i,j;
    printf("How many elements you want to insert : ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("Enter element at index %d : ",i);
        scanf("%d",&arr[i]);
    }

    printf("Array : ");
    for(i=0;i<n;i++)
    {
        printf("    %d",arr[i]);
    }

    insertion_sort(arr,n);

    printf("\n----------------------------------------------------------\nSorted Array : ");
    for(i=0;i<n;i++)
    {
        printf("    %d",arr[i]);
    }
    printf("\n----------------------------------------------------------");
}

void insertion_sort(int arr[],int n)
{
    int i,empty,temp;

    for(i=1;i<n;i++)
    {
        empty=i;
        temp=arr[i];
        while(empty>0 && temp<arr[empty-1])
        {
            arr[empty]=arr[empty-1];
            empty--;
        }
        arr[empty]=temp;
    }
}