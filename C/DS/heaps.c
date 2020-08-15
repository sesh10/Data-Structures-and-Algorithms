#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct heap
{
    int * arr;
    int size;
};
typedef struct heap heap;

heap * create_heap(int max_size)
{
    heap * h = (heap *) malloc(sizeof(heap));
    h->arr = (int *) malloc(sizeof(int) * max_size);
    h->size = 0;
    for (int i = 0; i < max_size; i++)
    {
        h->arr[i] = 0;
    }
    return h;
}

bool empty_heap(heap * h)
{
    return h->size == 0;
}

void swap(int * num1, int * num2)
{
    int temp = * num1;
    * num1 = * num2;
    * num2 = temp;
}

int max(int num1, int num2)
{
    return num1 > num2 ? num1 : num2;
}

int min(int num1, int num2)
{
    return num1 < num2 ? num1 : num2;
}

void insert_max_heap(heap * h, int value)
{
    h->arr[++h->size] = value;
    int child = h->size;
    while (child > 1 && h->arr[child] > h->arr[child/2])
    {
        swap(&h->arr[child], &h->arr[child/2]);
    }
}

void insert_min_heap(heap * h, int value)
{
    h->arr[++h->size] = value;
    int child = h->size;
    while (child > 1 && h->arr[child] < h->arr[child/2])
    {
        swap(&h->arr[child], &h->arr[child/2]);
    }
}

int extract_max_heap(heap * h)
{
    if (empty_heap(h))
    {
        printf("Error! Heap is full");
        return -1;
    }
    int value = h->arr[1];
    h->arr[1] = h->arr[h->size];
    h->size--;
    int parent = 1;
    int left_child, right_child;
    do
    {
        left_child = parent * 2;
        right_child = (parent * 2) + 1;
        if (h->arr[parent] > max(h->arr[left_child], h->arr[right_child]))
        {
            break;
        }
        if (h->size == left_child || h->arr[left_child] > h->arr[right_child])
        {
            swap(&h->arr[left_child], &h->arr[parent]);
            parent = left_child;
        }
        else
        {
            swap(&h->arr[right_child], &h->arr[parent]);
            parent = right_child;
        }
    } while (parent < h->size);
    return value;
}

int extract_min_heap(heap * h)
{
    if (empty_heap(h))
    {
        printf("Error! Heap is full");
        return -1;
    }
    int value = h->arr[1];
    h->arr[1] = h->arr[h->size];
    h->size--;
    int parent = 1;
    int left_child, right_child;
    do
    {
        left_child = parent * 2;
        right_child = (parent * 2) + 1;
        if (h->arr[parent] < min(h->arr[left_child], h->arr[right_child]))
        {
            break;
        }
        if (h->size == left_child || h->arr[left_child] < h->arr[right_child])
        {
            swap(&h->arr[left_child], &h->arr[parent]);
            parent = left_child;
        }
        else
        {
            swap(&h->arr[right_child], &h->arr[parent]);
            parent = right_child;
        }
    } while (parent < h->size);
    return value;
}

int main()
{
    heap * h = create_heap(100);
    
    // perform operations
    return 0;
}
