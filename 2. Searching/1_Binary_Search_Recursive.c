#include<stdio.h>

void selection_sort(int [],int);  // we write selction_sort below of void main. So only declare it above main()
int binary_search(int [],int,int,int);

void main()
{
    int arr[100],n,i,j,search,flag;
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
        flag=-2;
        flag=binary_search(arr,0,n-1,search);
        if(flag != -1)
        {
           printf("Element NOT found.");
        }

        printf("\nDo you want to search again (Y or N) : ");
        scanf(" %c",&ch);
    }while(ch=='y' || ch=='Y');
}

int binary_search(int arr[],int low,int high,int search)
{
    if(low <= high)
    {
        int mid = (low+high)/2;
        if(search == arr[mid])
        {
            printf("Element is found at index %d.",mid);
            return mid;
        }
        else if(search < arr[mid])
        {
            return binary_search(arr,low,mid-1,search);
        }
        else if(search > arr[mid])
        {
            return binary_search(arr,mid+1,high,search);
        }
    }
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
