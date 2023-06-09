#include<stdio.h>
void merge_sort(int [],int,int);
void merge(int [],int,int,int);
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

    merge_sort(arr,0,n-1);

    printf("\n----------------------------------------------------------\nSorted Array : ");
    for(i=0;i<n;i++)
    {
        printf("    %d",arr[i]);
    }
    printf("\n----------------------------------------------------------");
}

void merge_sort(int arr[] , int low , int high)
{
    int mid;
    if(low < high)
    {
        mid = (low+high) / 2;
        merge_sort(arr,low,mid);    // first half
        merge_sort(arr,mid+1,high); // second half
        merge(arr , low , mid , high);
    }
}

void merge(int arr[],int low,int mid,int high)
{
    int i = low;
    int j = mid+1;
    int k = 0;  // initially k=0. It increase as elemeents inserted in array
    int brr[100];

    while(i <= mid && j<= high)
    {
        if(arr[i]<arr[j])
        {
            brr[k]=arr[i];
            i++;
            k++;
        }
        else
        {
            brr[k]=arr[j];
            j++;
            k++;
        }
    }

    // to insert remaining elements in array of i or j

    while(i <= mid )
    {
        brr[k]=arr[i];
        i++;
        k++;
    }
    while(j <= high )
    {
        brr[k]=arr[j];
        j++;
        k++;
    }
    // brr is sorted from low to high in arr
    // now we only put SORTED elements in brr into arr means from low to high
    // low and high can be anything in partitioned array

    k=0;

    for(i = low ; i <= high ; i++)
    {   
        // low and high can be anything in partitioned array
        arr[i] = brr[k];
        k++;
    }
}