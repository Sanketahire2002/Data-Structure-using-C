#include<stdio.h>
void bubble_sort(int [],int);  // we write bubble_sort below of void main. So only declare it above main()

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

    bubble_sort(arr,n);

    printf("\n----------------------------------------------------------\nSorted Array : ");
    for(i=0;i<n;i++)
    {
        printf("    %d",arr[i]);
    }
    printf("\n----------------------------------------------------------");
}

void bubble_sort(int arr[],int n)
{
    int i,j,k,temp,flag;

    for(i=1;i<n;i++)
    {
        flag=0;
        for(j=0;j<n-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                flag=1;
            }
        }

        printf("\nPass %d : ",i);
        for(k=0;k<n;k++)
        {
            printf("    %d",arr[k]);
        }

        if(flag==0)
            break;
    }
}