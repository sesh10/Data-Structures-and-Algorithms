#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void selection_sort(int arr[], int n)
{
    int target;
    for (target = 0; target < n-1; target++)
    {
        int min = target;
        for (int i = target+1; i < n; i++)
        {
            if (arr[min] > arr[i])
                min = i;            
        }
        int temp = arr[target];
        arr[target] = arr[min];
        arr[min] = temp;        
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
    selection_sort(arr, n);
    printArray(arr, n);
    return 0;
}
