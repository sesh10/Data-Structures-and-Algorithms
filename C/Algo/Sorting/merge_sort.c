#include <stdio.h>
#include <stdlib.h>

void merge_sort(int arr[], int beg, int end)
{
    if (beg == end)
        return;
    
    int m = (beg + end) / 2;
    merge_sort(arr, beg, m);
    merge_sort(arr, m+1, end);
    merge(arr, beg, end);
}

void merge(int arr[], int beg, int end)
{
    int m = (beg + end)/2;
    int temp_arr[end-beg+1];
    int i = beg;
    int j = m + 1;
    int k = 0;
    while (i <= m && j <= end)
    {
        if (arr[i] < arr[j])
            temp_arr[k++] = arr[i++];
        else
            temp_arr[k++] = arr[j++];
    }
    while (i <= m)
        temp_arr[k++] = arr[i++];
    while (j <= end)
        temp_arr[k++] = arr[j++];

    for (i = 0; i < k; i++)
    {
        arr[beg+i] = temp_arr[i];
    }
        
}

void printArray(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", arr[i]);  
} 

int main()
{
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    merge_sort(arr, 0, n-1);
    printf("Sorted array is: ");
    printArray(arr, n);
    return 0;
}
