#include <stdio.h>
#include <locale.h>
#include "arrayio.h"
#include "arrayf.h"

#define SIZE 20

int main()
{
    int M[SIZE];

    setlocale(0, "");

    printf("Массив M (размер %d):\n", SIZE);
    inputArray(M, SIZE);

    printf("Исходный массив: ");
    printArray(M, SIZE);

    insertZeroInMiddle(M, SIZE);

    printf("После вставки 0 в середину: ");
    printArray(M, SIZE);

    return 0;
}