#include<stdio.h>

void selection_sort(int [],int);  // we write selction_sort below of void main. So only declare it above main()

void main()
{
    int arr[100],n,i,j,search,low,high,mid,flag;
    char ch;
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

    selection_sort(arr,n);

    printf("\n----------------------------------------------------------\nSorted Array : ");
    for(i=0;i<n;i++)
    {
        printf("    %d",arr[i]);
    }
    printf("\n----------------------------------------------------------");

    do{
        printf("\nEnter element to search : ");
        scanf("%d",&search);

        low=0;
        high=n-1;
        flag=0;

        while(low <= high)
        {
            mid=(low+high)/2;
            if(search == arr[mid])
            {
                printf("Element is found at index %d.",mid);
                flag=1;
                break;
            }
            else if(search < arr[mid])
            {
                high = mid-1;
            }
            else if(search > arr[mid])
            {
                low = mid+1;
            }
        }
        if(flag==0)
            printf("Element NOT found.");

        printf("\nDo you want to search again (Y or N) : ");
        scanf(" %c",&ch);
    }while(ch=='y' || ch=='Y');
}

void selection_sort(int arr[],int n)
{
    int i,j,temp;

    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(arr[i]>arr[j])
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}