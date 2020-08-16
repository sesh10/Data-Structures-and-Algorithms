#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void bubble_sort(int arr[], int n)
{
    bool sorted;
    do
    {
        sorted = true;
        for (int i = 0; i < n-1; i++)
        {
            if (arr[i] > arr[i+1])
            {
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                sorted = false;
            }
        }
    } while (sorted == false);
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
    bubble_sort(arr, n);
    printArray(arr, n);
    return 0;
}
