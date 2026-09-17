#include <stdio.h>
#include "arrayio.h"

void inputArray(int arr[], int size)
{
    printf("¬ведите %d целых чисел:\n", size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
}

void printArray(const int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}