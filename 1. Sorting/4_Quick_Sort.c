#include<stdio.h>

void quick_sort(int [],int,int);
int partition(int [],int,int);

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

    quick_sort(arr,0,n-1);

    printf("\n----------------------------------------------------------\nSorted Array : ");
    for(i=0;i<n;i++)
    {
        printf("    %d",arr[i]);
    }
    printf("\n----------------------------------------------------------");
}

int partition(int arr[],int lb, int ub)
{
    int pivote,start,end,temp;
    pivote = arr[lb];
    start = lb;
    end = ub;

    while(start <= end)
    {
        while(start <= ub && arr[start] <= pivote )
            start++;

        while(end >=lb && arr[end] > pivote)
            end--;

        if(start <= end)
        {
            // swapping between start and end indexed elements
            temp=arr[start];
            arr[start]=arr[end];
            arr[end]=temp;   
            start++;
            end--;
        }
    }

    // swapping between pivote and end indexed elements
    temp=arr[lb];
    arr[lb]=arr[end];
    arr[end]=temp;

    return end;
}

void quick_sort(int arr[], int lb , int ub)
{
    int location;
    if(lb <= ub)
    {
        location = partition(arr,lb,ub);
        quick_sort(arr, lb , location-1);
        quick_sort(arr, location+1 , ub);
    }
}
