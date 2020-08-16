#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        int temp = arr[i];
        j = i;
        while (j > 0 && arr[j-1] > temp)
        {
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = temp;
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
    insertion_sort(arr, n);
    printArray(arr, n);
    return 0;
}
